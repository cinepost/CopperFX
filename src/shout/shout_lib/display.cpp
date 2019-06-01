#include <dlfcn.h>
#include <stdlib.h>
#include <boost/format.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "utils.h"
#include "display.h"

Display::Display(const std::string& driver_name) {
	char *error;
    
  boost::format libdspy_name(expandEnvVars("${SHOUT_HOME}/lib/d_%1%.so"));
	libdspy_name % driver_name;

	void* lib_handle = dlopen(libdspy_name.str().c_str(), RTLD_NOW);//RTLD_LOCAL|RTLD_LAZY);
  if (!lib_handle) {
    printf("[%s] Unable to load library: %s\n", __FILE__, dlerror());
    exit(1);
  } else {
  	m_OpenFunc = (PtDspyOpenFuncPtr)dlsym(lib_handle, "DspyImageOpen");
    if ((error = dlerror()) != NULL) {
      fputs(error, stderr);
      exit(1);
    }

    m_CloseFunc = (PtDspyCloseFuncPtr)dlsym(lib_handle, "DspyImageClose");
    if ((error = dlerror()) != NULL)  {
      fputs(error, stderr);
      exit(1);
    }
      
    m_WriteFunc = (PtDspyWriteFuncPtr)dlsym(lib_handle, "DspyImageData");
    if ((error = dlerror()) != NULL)  {
      fputs(error, stderr);
      exit(1);
    }

    m_QueryFunc = (PtDspyQueryFuncPtr)dlsym(lib_handle, "DspyImageQuery");
    if ((error = dlerror()) != NULL)  {
      // no panic. this driver don't support this method
      m_QueryFunc = nullptr;
    }
  }

  this->driver_name = driver_name;
  BOOST_LOG_TRIVIAL(debug) << "Display \"" << driver_name << "\" constructed using driver " << libdspy_name.str();
}

Display::~Display() {
    BOOST_LOG_TRIVIAL(debug) << "Display \"" << driver_name << "\" destructed!";
}

void Display::open() {
  BOOST_LOG_TRIVIAL(debug) << "Opening display " << driver_name;
  //format can be rgb, rgba, rgbaz or rgbz
  int formatCount = 3;
  //char* channels[5] = {"r","g","b","a","z"};
  char channels[6] = "rgbaz";

  PtDspyDevFormat *outformat = new PtDspyDevFormat[formatCount]();
  PtDspyDevFormat *f_ptr = &outformat[0];
  for(int i=0; i<formatCount; i++){
    f_ptr->type = PkDspyFloat32;
    f_ptr->name = &channels[i];
    f_ptr++;
  }

  UserParameter *prms = new UserParameter[2];

  const char *compression[1] = {"none"};
  makeStringsParameter("exrcompression", compression, 1, prms[0]);

  const char *pixeltype[1] = {"float"};
  makeStringsParameter("exrpixeltype", pixeltype, 1, prms[1]);

  PtDspyError err = m_OpenFunc(&image, driver_name.c_str(), "/Users/max/dev/CopperFX/test_img.exr", 800, 600, 0, prms, formatCount, outformat, &flagstuff);
  
  // check for an error
  if(err != PkDspyErrorNone ) {
    BOOST_LOG_TRIVIAL(error) << "Unable to open display \"" << driver_name << "\" : ";
    switch (err) {
      case PkDspyErrorNoMemory:
        BOOST_LOG_TRIVIAL(error) << "Out of memory";
        break;
      case PkDspyErrorUnsupported:
        BOOST_LOG_TRIVIAL(error) << "Unsupported";
        break;
      case PkDspyErrorBadParams:
        BOOST_LOG_TRIVIAL(error) << "Bad params";
        break;
      case PkDspyErrorNoResource:
        BOOST_LOG_TRIVIAL(error) << "No resource";
        break;
      case PkDspyErrorUndefined:
      default:
        BOOST_LOG_TRIVIAL(error) << "Undefined";
        break; 
    }
  } else {
    // check image info
    if (m_QueryFunc != nullptr) {
      PtDspySizeInfo img_info;

      BOOST_LOG_TRIVIAL(info) << "Querying display image size " << driver_name;
      err = m_QueryFunc(image, PkSizeQuery, sizeof(PtDspySizeInfo), &img_info);
      if(err) {
        BOOST_LOG_TRIVIAL(error) << "Unable to query image size info " << driver_name;
      } else {
        BOOST_LOG_TRIVIAL(info) << "Image size: " << img_info.width << " " << img_info.height << " " << img_info.aspectRatio;
      }
    }

    // check flags
    if (flagstuff.flags & PkDspyFlagsWantsScanLineOrder)
      BOOST_LOG_TRIVIAL(debug) << "PkDspyFlagsWantsScanLineOrder ";

    if (flagstuff.flags & PkDspyFlagsWantsEmptyBuckets)
      BOOST_LOG_TRIVIAL(debug) << "PkDspyFlagsWantsEmptyBuckets";

    if(flagstuff.flags & PkDspyFlagsWantsNullEmptyBuckets)
      BOOST_LOG_TRIVIAL(debug) << "PkDspyFlagsWantsNullEmptyBuckets";
  }

  delete [] prms;
  delete [] outformat;
}

void Display::write() {
  BOOST_LOG_TRIVIAL(debug) << "Writing to display " << driver_name;
  int num_channels = 3; // rgb
  int entrysize = num_channels * sizeof(PkDspyFloat32); // pixel data size in bytes; num channels x sizeof(float)
  float *data = new float [800*600*num_channels]();
  float *ptr = &data[0];

  // test fill colour
  for (int i = 0; i < 800*600; i++) {
    ptr[0] = 1.0f;
    ptr[1] = 0.15f;
    ptr[2] = 0.0f; 
    ptr+=3; // jump to next pixel
  }

  PtDspyError err = PkDspyErrorNone;

  if (flagstuff.flags & PkDspyFlagsWantsScanLineOrder) {
    // write scanlines
    BOOST_LOG_TRIVIAL(debug) << "Writing scanlines";
    int scanline = 0;
    while ((err == PkDspyErrorNone) && (scanline < 600)) {
      err = m_WriteFunc(image, 0, 800, scanline, scanline+1, entrysize, reinterpret_cast<const unsigned char*>(&data[scanline*800*num_channels]));
      scanline++;
    }
  } else {
    // write whole image
    BOOST_LOG_TRIVIAL(debug) << "Writing while image";
    err = m_WriteFunc(image, 0, 800, 0, 600, entrysize, reinterpret_cast<const unsigned char*>(&data[0]));
  }

  if(err)
    BOOST_LOG_TRIVIAL(error) << "Cannot write data to display " << driver_name;

  delete [] data;
}

void Display::close() {
  BOOST_LOG_TRIVIAL(debug) << "Closing display " << driver_name;
  PtDspyError err = m_CloseFunc(image);
  if(err)
    BOOST_LOG_TRIVIAL(error) << "Unable to close display " << driver_name;
}

void Display::makeStringsParameter(const char* name, const char** strings, int count, UserParameter& parameter) {
  // Allocate and fill in the name.
  char* pname = reinterpret_cast<char*>(malloc(strlen(name)+1));
  strcpy(pname, name);
  parameter.name = pname;
  // Allocate enough space for the string pointers, and the strings, in one big block,
  // makes it easy to deallocate later.
  int totallen = count * sizeof(char*);
  int i;
  for ( i = 0; i < count; i++ )
    totallen += (strlen(strings[i])+1) * sizeof(char);

  char** pstringptrs = reinterpret_cast<char**>(malloc(totallen));
  char* pstrings = reinterpret_cast<char*>(&pstringptrs[count]);
  
  for ( i = 0; i < count; i++ )
  {
    // Copy each string to the end of the block.
    strcpy(pstrings, strings[i]);
    pstringptrs[i] = pstrings;
    pstrings += strlen(strings[i])+1;
  }
  
  parameter.value = reinterpret_cast<RtPointer>(pstringptrs);
  parameter.vtype = 's';
  parameter.vcount = count;
  parameter.nbytes = totallen;
}

