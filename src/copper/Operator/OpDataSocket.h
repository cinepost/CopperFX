#ifndef OP_DATA_SOCKET_H
#define OP_DATA_SOCKET_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"


namespace copper {

class OpDataSocket {

	/// Flags passed to the operator definition contructor:
	enum Flags{
		INPUT_SOCKET	= 0x01, /// Socket for output data
		OUPUT_SOCKET  = 0x02, /// Socket for ouput data
		MULTY_INPUT   = 0x04  /// Unordered multiple input
	};

	public:
		OpDataSocket(
			unsigned int id, 										/// input id
			unsigned int opdata_type_version, 	/// opdata type version
			std::string  opdata_type_name,			/// internal opdata type name
			Flags Flags 												/// socket flags
		);
};

}

#endif // OP_DATA_SOCKET_H