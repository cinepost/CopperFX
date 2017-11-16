///////////////////////////////////////////////////////////////////////////////
// Plugin architecture example                                               //
//                                                                           //
// This code serves as an example to the plugin architecture discussed in    //
// the article and can be freely used.                                       //
///////////////////////////////////////////////////////////////////////////////
#ifndef COPPER_ENGINE_OPS_SERVER_H
#define COPPER_ENGINE_OPS_SERVER_H

#include "copper/CopperEngineAPI.h"

#include <list>
#include <string>
#include <memory>
#include <stdexcept>

namespace CopperEngine {

  // ----------------------------------------------------------------------- //

  class Operator {}; // Dummy

  // ----------------------------------------------------------------------- //

  /// <summary>Manages storage related stuff</summary>
  class OpsServer {

    /// <summary>Reads Operator files like zips and rars</summary>
    public: class OperatorReader {

      /// <summary>Releases any resources owned by the reader</summary>
      public: virtual ~OperatorReader() {}

      /// <summary>Checks whether the reader can open an Operator</summary>
      /// <param name="filename">Name of the file that will be checked</param>
      public: virtual bool canOpenOperator(const std::string &filename) = 0;

      /// <summary>Opens an Operator for reading</summary>
      /// <param name="filename">Filename of the Operator to open</param>
      public: virtual std::auto_ptr<Operator> openOperator(
        const std::string &filename
      ) = 0;

    };

    /// <summary>A list of Operator readers</summary>
    private: typedef std::list<OperatorReader *> OperatorReaderList;

    /// <summary>Destroys the storage server</summary>
    public: COPPER_ENGINE_API ~OpsServer() {
      for(
        OperatorReaderList::reverse_iterator it = this->OperatorReaders.rbegin();
        it != this->OperatorReaders.rend();
        ++it
      ) {
        delete *it;
      }
    }

    /// <summary>Allows plugins to add new Operator readers</summary>
    public: COPPER_ENGINE_API void addOperatorReader(
      std::auto_ptr<OperatorReader> OperatorReader
    ) {
      this->OperatorReaders.push_back(OperatorReader.release());
    }
    
    /// <summry>
    ///   Opens an Operator by searching for a matching Operator reader
    /// </summary>
    /// <param name="filename">File a reader will be searched for</param>
    public: COPPER_ENGINE_API std::auto_ptr<Operator> openOperator(
      const std::string &filename
    ) {
      for(
        OperatorReaderList::iterator it = this->OperatorReaders.begin();
        it != this->OperatorReaders.end();
        ++it
      ) {
        if((*it)->canOpenOperator(filename))
          return (*it)->openOperator(filename);
      }

      throw std::runtime_error("Invalid or unsupported operator type");
    }

    private: OperatorReaderList OperatorReaders; ///< All available Operator readers

  };

  // ----------------------------------------------------------------------- //

} // namespace COPPER_ENGINE

#endif // COPPER_ENGINE_OPS_SERVER_H
