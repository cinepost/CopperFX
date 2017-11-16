///////////////////////////////////////////////////////////////////////////////
// Plugin architecture                                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef COPPER_ENGINE_KERNEL_H
#define COPPER_ENGINE_KERNEL_H

#include "copper/CopperEngineAPI.h"
#include "copper/OpsServer.h"
#include "copper/PanelsServer.h"
#include "copper/Plugin.h"

#include <string>
#include <map>

namespace CopperEngine {

  /// <summary>The engine's plugin core</summary>
  class Kernel {

    /// <summary>Map of plugins by their associated file names</summary>
    typedef std::map<std::string, Plugin> PluginMap;

    /// <summary>Accesses the ops server</summary>
    public: COPPER_ENGINE_API OpsServer &getOpsServer() {
      return this->opsServer;
    }

    /// <summary>Accesses the panels server</summary>
    public: COPPER_ENGINE_API PanelsServer &getPanelsServer() {
      return this->panelsServer;
    }

    /// <summary>Loads a plugin</summary>
    /// <param name="filename">File the plugin will be loaded from</param>
    public: COPPER_ENGINE_API void loadPlugin(const std::string &filename) {
      if(this->loadedPlugins.find(filename) == this->loadedPlugins.end()) {
        this->loadedPlugins.insert(
          PluginMap::value_type(filename, Plugin(filename))
        ).first->second.registerPlugin(*this);
      }
    }

    /// <summary>All plugins currently loaded</summary>
    private: PluginMap loadedPlugins;
    /// <summary>Manages storage-related tasks for the engine</summary>
    private: OpsServer opsServer;
    /// <summary>Manages graphics-related tasks for the engine</summary>
    private: PanelsServer panelsServer; 

  };

} // namespace MyEngine

#endif // COPPER_ENGINE_KERNEL_H
