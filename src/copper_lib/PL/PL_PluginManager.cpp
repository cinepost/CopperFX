// MinGW related workaround
#define BOOST_DLL_FORCE_ALIAS_INSTANTIATION

//#include "../tutorial4/static_plugin.hpp"

#include "copper/PL/PL_PluginManager.h"

namespace dll = boost::dll;


PL_PluginManager::PL_PluginManager(const boost::filesystem::path& plugins_directory)
  : _plugins_directory(plugins_directory) {
  
  load_all();
}


//[plugcpp_plugins_collector_load_all
void PL_PluginManager::load_all() {
    namespace fs = ::boost::filesystem;
    typedef fs::path::string_type string_type;
    const string_type extension = dll::shared_library::suffix().native();

    // Searching a folder for files with '.so' or '.dll' extension
    fs::recursive_directory_iterator endit;
    for (fs::recursive_directory_iterator it(_plugins_directory); it != endit; ++it) {
        if (!fs::is_regular_file(*it)) {
            continue;
        }
        /*<-*/
        //if ( !b2_workarounds::is_shared_library((*it).path()) ) {
        //    continue;
        //}
        /*->*/

        // We found a file. Trying to load it
        boost::system::error_code error;
        dll::shared_library plugin(it->path(), error);
        if (error) {
            continue;
        }
        std::cout << "Loaded (" << plugin.native() << "):" << it->path() << '\n';

        // Gets plugin using "create_plugin" or "plugin" function
        insert_plugin(boost::move(plugin));
    }

    dll::shared_library plugin(dll::program_location());
    std::cout << "Loaded self\n";
    insert_plugin(boost::move(plugin));
}
//]

//[plugcpp_plugins_collector_insert_plugin
void PL_PluginManager::insert_plugin(BOOST_RV_REF(dll::shared_library) lib) {
    std::string plugin_name;
    if (lib.has("create_plugin")) {
        plugin_name = lib.get_alias<boost::shared_ptr<PL_BaseAPI>()>("create_plugin")()->name();
    } else if (lib.has("plugin")) {
        plugin_name = lib.get<PL_BaseAPI>("plugin").name();
    } else {
        return;
    }

    if (_plugins.find(plugin_name) == _plugins.cend()) {
        _plugins[plugin_name] = boost::move(lib);
    }
}
//]

void PL_PluginManager::print_plugins() const {
    plugins_t::const_iterator const end = _plugins.cend();
    for (plugins_t::const_iterator it = _plugins.cbegin(); it != end; ++it) {
        std::cout << '(' << it->second.native() << "): " << it->first << '\n';
    }
}

std::size_t PL_PluginManager::count() const {
    return _plugins.size();
}