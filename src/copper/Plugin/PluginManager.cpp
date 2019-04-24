#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

// MinGW related workaround
#define BOOST_DLL_FORCE_ALIAS_INSTANTIATION

#include "copper/Plugin/PluginManager.h"

namespace dll = boost::dll;

namespace copper {

PluginManager::PluginManager(const boost::filesystem::path& plugins_directory)
  : _plugins_directory(plugins_directory) {
  
  loadAll();
}


//[plugcpp_plugins_collector_load_all
void PluginManager::loadAll() {
    namespace fs = ::boost::filesystem;
    typedef fs::path::string_type string_type;
    const string_type extension = dll::shared_library::suffix().native();

    // Searching a folder for files with '.so' or '.dll' extension
    fs::recursive_directory_iterator endit;
    for (fs::recursive_directory_iterator it(_plugins_directory); it != endit; ++it) {
        if (!fs::is_regular_file(*it)) {
            continue;
        }

        if ( !is_shared_library((*it).path()) ) {
            continue;
        }

        // We've found a file. Trying to load it
        boost::system::error_code error;
        dll::shared_library plugin(it->path(), error);
        if (error) {
            continue;
        }
        BOOST_LOG_TRIVIAL(debug) << "Loaded (" << plugin.native() << "): " << it->path();

        // Gets plugin using "create_plugin" or "plugin" function
        insertPlugin(boost::move(plugin));
    }

    dll::shared_library plugin(dll::program_location());
    std::cout << "Loaded self\n";
    insertPlugin(boost::move(plugin));
}
//]

bool PluginManager::loadPluginLib(const boost::filesystem::path& plugin_file_path) {

}

//[plugcpp_plugins_collector_insert_plugin
void PluginManager::insertPlugin(BOOST_RV_REF(dll::shared_library) lib) {
    std::string plugin_name;
    if (lib.has("create_plugin")) {
        plugin_name = lib.get_alias<boost::shared_ptr<BaseAPI>()>("create_plugin")()->name();
    } else if (lib.has("plugin")) {
        plugin_name = lib.get<BaseAPI>("plugin").name();
    } else {
        return;
    }

    if (_plugins.find(plugin_name) == _plugins.cend()) {
        _plugins[plugin_name] = boost::move(lib);
    }
}
//]

void PluginManager::printPluginLibs() const {
    if (_plugins.size() > 0 ) {
        plugins_t::const_iterator const end = _plugins.cend();
        for (plugins_t::const_iterator it = _plugins.cbegin(); it != end; ++it) {
            std::cout << '(' << it->second.native() << "): " << it->first << '\n';
        }
    } else {
        std::cout << "No plugin libraries loaded !\n";   
    }
}

std::size_t PluginManager::countPluginLibs() const {
    return _plugins.size();
}

}