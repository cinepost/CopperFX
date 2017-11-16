///////////////////////////////////////////////////////////////////////////////
// Plugin architecture example                                               //
//                                                                           //
// This code serves as an example to the plugin architecture discussed in    //
// the article and can be freely used                                        //
///////////////////////////////////////////////////////////////////////////////
#ifndef COPPER_ENGINE_PANELS_SERVER_H
#define COPPER_ENGINE_PANELS_SERVER_H

#include "copper/CopperEngineAPI.h"

#include <vector>
#include <string>

namespace CopperEngine {

  // ----------------------------------------------------------------------- //

  class Panel {}; // Dummy

  // ----------------------------------------------------------------------- //

  /// <summary>Manages graphics related stuff for the engine</summary>
  class PanelsServer {

    /// <summary>Graphics driver interface for the engine</summary>
    public: class GraphicsDriver {
      /// <summary>Releases resources of a driver after use</summary>
      public: virtual ~GraphicsDriver() {}
      /// <summary>Gets the name of the graphics driver</summary>
      public: virtual const std::string &getName() const = 0;
      /// <summary>Creates a Panel using the driver's rendering API</summary>
      public: virtual std::auto_ptr<Panel> createPanel() = 0;
    };

    /// <summary>A vector of graphics drivers</summary>
    private: typedef std::vector<GraphicsDriver *> GraphicsDriverVector;

    /// <summary>Releases the resources of the graphics server</summary>
    public: COPPER_ENGINE_API ~PanelsServer() {
      for(
        GraphicsDriverVector::const_iterator it = this->graphicsDrivers.begin();
        it != this->graphicsDrivers.end();
        ++it
      ) {
        delete *it;
      }
    }

    /// <summary>Allows plugins to add new graphics drivers</summary>
    /// <param name="graphicsDriver">Graphics driver that will be added</param>
    public: COPPER_ENGINE_API void addGraphicsDriver(
      std::auto_ptr<GraphicsDriver> graphicsDriver
    ) {
      this->graphicsDrivers.push_back(graphicsDriver.release());
    }

    /// <summary>Gets the total number of registered graphics drivers</summary>
    public: COPPER_ENGINE_API size_t getDriverCount() const {
      return this->graphicsDrivers.size();
    }

    /// <summary>Accesses a driver by its index</summary>
    public: COPPER_ENGINE_API GraphicsDriver &getDriver(size_t Index) {
      return *this->graphicsDrivers.at(Index);
    }

    /// <summary>All available graphics drivers</summary>
    private: GraphicsDriverVector graphicsDrivers;

  };

  // ----------------------------------------------------------------------- //

} // namespace COPPER_ENGINE

#endif // COPPER_ENGINE_PANELS_SERVER_H
