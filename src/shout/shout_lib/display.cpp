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

  PtDspyDevFormat *outformat = new PtDspyDevFormat[formatCount];
  PtDspyDevFormat *f_ptr = outformat;
  for(int i=0;i<formatCount;i++){
    f_ptr->type = PkDspyFloat32;
    f_ptr->name = &channels[i];
    f_ptr += 1;
  }

  UserParameter *prms = new UserParameter[1];

  PtDspyError err = m_OpenFunc(&image, driver_name.c_str(), "/Users/max/dev/CopperFX/test_img.exr", 800, 600, 0, prms, formatCount, outformat, &flagstuff);
  if(err) {
    BOOST_LOG_TRIVIAL(error) << "Unable to open display " << driver_name;
  } else {
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
  int entrysize = 12; // 3 x sizeof(float)
  unsigned char *data = new unsigned char [800*600*entrysize];
  unsigned char *ptr = data;

  // test fill colour
  for (int i = 0; i < 800*600; i++) {
    ptr[0] = 1.0;
    ptr[4] = 0.5;
    ptr[8] = 0.0;
    ptr += entrysize;
  }

  PtDspyError err = PkDspyErrorNone;

  if (flagstuff.flags & PkDspyFlagsWantsScanLineOrder) {
    int scanline = 0;
    while ((err == PkDspyErrorNone) && (scanline < 600)) {
      BOOST_LOG_TRIVIAL(debug) << "Writing scanline " << scanline;
      err = m_WriteFunc(image, 0, scanline, 800, scanline, entrysize, &data[scanline*800*entrysize]);
      scanline++;
    }
  } else {
    // write whole image
    err = m_WriteFunc(image, 0, 0, 800, 600, entrysize, data);
  }

  if(err)
    BOOST_LOG_TRIVIAL(error) << "Unable to write data to display " << driver_name;

  delete [] data;
}

void Display::close() {
  BOOST_LOG_TRIVIAL(debug) << "Closing display " << driver_name;
  PtDspyError err = m_CloseFunc(image);
  if(err)
    BOOST_LOG_TRIVIAL(error) << "Unable to close display " << driver_name;
}

