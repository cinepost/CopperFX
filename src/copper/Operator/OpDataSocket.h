#ifndef OP_DATA_SOCKET_H
#define OP_DATA_SOCKET_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"


namespace copper {

class OpDataSocket {
	public:
	/// Flags passed to the operator definition contructor:
	enum Flags{
		INPUT_SOCKET	= 0x01, /// Socket for output data
		OUTPUT_SOCKET  = 0x02, /// Socket for ouput data
		MULTY_INPUT   = 0x04  /// Unordered multiple input
	};

	public:
		OpDataSocket(
			unsigned int id, 											/// input id
			unsigned int opdata_type_version, 		/// opdata type version
			const std::string &opdata_type_name,	/// internal opdata type name
			OpDataSocket::Flags flags 						/// socket flags
		);

	public:
		bool isInput() const;
		bool isOutput() const;

	private:
		unsigned int 				_id;
		unsigned int 				_opdata_type_version;
		std::string 				_opdata_type_name;
		OpDataSocket::Flags _flags;
};

}

#endif // OP_DATA_SOCKET_H