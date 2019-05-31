#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/join.hpp>
namespace po = boost::program_options;

#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>

//#include "antlr4-runtime.h"
//#include "IFDLexer.h"
//#include "IFDParser.h"

#include "shout/shout_lib/SCN/SCN_IORegistry.h"
#include "shout/shout_lib/SCN/SCN_IFDTranslator.h"
#include "shout/shout_lib/SCN/SCN_Scene.h"
#include "shout/shout_lib/renderer.h"
#include "shout/shout_lib/renderer_opengl.h"

namespace logging = boost::log;

using namespace std;
//using namespace antlr4;


void signalHandler( int signum ){
    std::cerr << "Interrupt signal (" << signum << ") received." << std::endl;

    // cleanup and close up stuff here  
    // terminate program  
   exit(signum);  
}


// A helper function to simplify the main part.
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " ")); 
    return os;
}


int main(int argc, char **argv) {
	logging::core::get()->set_filter(
    	logging::trivial::severity >= logging::trivial::debug
  	);

	signal(SIGTERM, signalHandler);
	signal(SIGABRT, signalHandler);

  try { 
    int opt;
    string config_file;

    // Declare a group of options that will be allowed only on command line
    namespace po = boost::program_options; 
    po::options_description generic("Options"); 
    generic.add_options() 
      ("help,h", "Print help messages") 
      ("version,v", "Shout version information")
      ;

    // Declare a group of options that will be allowed both on command line and in config file
    po::options_description config("Configuration");
    config.add_options()
        ("optimization", po::value<int>(&opt)->default_value(10), 
              "optimization level")
        ("include-path,I", 
             po::value< vector<string> >()->composing(), 
             "include path")
        ;

    // Hidden options, will be allowed both on command line and in config file, but will not be shown to the user.
    po::options_description hidden("Hidden options");
    hidden.add_options()
        ("input-file", po::value< vector<string> >(), "input file")
        ;

    po::options_description cmdline_options;
    cmdline_options.add(generic).add(config).add(hidden);

    po::options_description config_file_options;
    config_file_options.add(config).add(hidden);

    po::options_description visible("Allowed options");
    visible.add(generic).add(config);

    po::positional_options_description p;
    p.add("input-file", -1);
 
    po::variables_map vm; 
    po::store(po::command_line_parser(argc, argv).
      options(cmdline_options).positional(p).run(), vm); // can throw 
    po::notify(vm); // throws on error, so do after help in case there are any problems

    /** --help option 
     */ 
    if ( vm.count("help")  ) { 
		cout << "Basic Command Line Parameter App\n" << generic << endl; 
		exit(EXIT_SUCCESS);
    }

    if (vm.count("version")) {
		cout << "Shout, version 0.0\n";
		exit(EXIT_SUCCESS);
    }

    // Handle config file
    ifstream ifs(config_file.c_str());
    if (!ifs) {
        BOOST_LOG_TRIVIAL(debug) << "No config file provided but that's totally fine." << config_file << "\n";
    } else {
        store(parse_config_file(ifs, config_file_options), vm);
        notify(vm);
    }

    // Populate IO_Registry with internal and external scene translators
    SCN_IORegistry::getInstance().addIOTranslator(
      SCN_IFDTranslatorFactory::myExtensions, 
      SCN_IFDTranslatorFactory::myConstructor
    );

    SCN_Scene scene;
    SCN_IOTranslator *translator = 0;
    Renderer  *renderer = 0;

    renderer = new RendererOpenGL();


    if (vm.count("input-file")) {
      // loading provided files
      vector<string> files = vm["input-file"].as< vector<string> >();
      BOOST_LOG_TRIVIAL(debug) << "Input scene files are: "<< boost::algorithm::join(files, " ") << "\n";
      for (vector<string>::const_iterator fi = files.begin(); fi != files.end(); ++fi) {
        std::ifstream in_file(*fi, std::ifstream::binary);
        if ( in_file ) {
          string file_extension = boost::filesystem::extension(*fi);
          BOOST_LOG_TRIVIAL(debug) << "ext " << file_extension;
          translator = SCN_IORegistry::getInstance().getTranslatorByExt(file_extension);

          BOOST_LOG_TRIVIAL(debug) << "translator";
          //BOOST_LOG_TRIVIAL(debug) << "Reading "<< *fi << " scene file with " << translator->formatName() << " translator";
          if (!translator->fileLoad(scene, in_file, false)) {
            // error loading scene from file
            BOOST_LOG_TRIVIAL(error) << "Error loading scene from file " << *fi;
          }
        } else {
          // error opening scene file
          std::cerr << "Unable to open file " << *fi << " ! aborting..." << std::endl;
        }
      }
    } else {
      // loading from stdin
      BOOST_LOG_TRIVIAL(debug) << "Reading scene from stdin ...\n";
      translator =  SCN_IORegistry::getInstance().getTranslatorByExt(".ifd"); // default format for reading stdin is ".ifd"
      if (!translator->fileLoad(scene, std::cin, false)) {
        // error loading scene from stdin
        BOOST_LOG_TRIVIAL(error) << "Error loading scene from stdin !";
      }
    }
    if(translator)delete translator;

    renderer->render(0);
    if(renderer)delete renderer;
  } 
  catch(exception& e) 
  { 
  	// Unhandled exception reached top of main
    BOOST_LOG_TRIVIAL(error) << "Unhandled Exception: " << e.what(); 
    exit(EXIT_FAILURE);
  }

  BOOST_LOG_TRIVIAL(info) << "All done! Bye ;)";
  exit(EXIT_SUCCESS);
}