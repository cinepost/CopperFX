#ifndef PL_PLUGINMANAGER_H
#define PL_PLUGINMANAGER_H

#include <boost/dll/runtime_symbol_info.hpp> // for program_location()
#include <boost/dll/shared_library.hpp>
#include <boost/make_shared.hpp>
#include <boost/container/map.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

#include "copper/UT/UT_Singleton.h"
#include "copper/PL/PL_PluginApi.h"

namespace dll = boost::dll;


// This class takes care of loading all the core related plugins like operators and data types
// It also registers internally defined ones..
// For gui related plugins we'll use another manager so we can completely skip scanning, registering and loading 
// them when not needed, like command line processing...
// And yes it's a singleton. There is no foreseeble need to have two instances. But...
class PL_PluginManager: public UT_Singleton<PL_PluginManager> {
  public:
    PL_PluginManager(const boost::filesystem::path& plugins_directory);

    void print_plugins() const;

    std::size_t count() const;

  private:
    // Name => plugin
    typedef boost::container::map<std::string, dll::shared_library> plugins_t;

    boost::filesystem::path _plugins_directory;
    plugins_t               _plugins;

    // loads all plugins in plugins_directory_
    void load_all();

    // Gets `my_plugin_api` instance using "create_plugin" or "plugin" imports,
    // stores plugin with its name in the `plugins_` map.
    void insert_plugin(BOOST_RV_REF(dll::shared_library) lib);
};

#endif // PL_PLUGINMANAGER_H