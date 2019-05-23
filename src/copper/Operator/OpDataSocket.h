#ifndef OP_DATA_SOCKET_H
#define OP_DATA_SOCKET_H

#include <string>
#include <map>

#include <flags/flags.hpp>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class OpDataSocket {
	public:
	/// Flags passed to the operator definition contructor:
	enum class Flags {
		INPUT_SOCKET	 = 0x01, /// Socket for output data
		OUTPUT_SOCKET  = 0x02, /// Socket for ouput data
		MULTY_INPUT    = 0x04  /// Unordered multiple input
	};

	public:
		OpDataSocket(
			unsigned int id, 											/// input id
			unsigned int opdata_type_version, 		/// opdata type version
			const std::string &opdata_type_name,	/// internal opdata type name
			OpDataSocket::Flags flags 						/// socket flags
		);

	public:
		unsigned int idx() const;
		bool isInput() const;
		bool isOutput() const;
		const std::string& dataTypeName() const;
		bool connect(const OpDataSocket *socket);
		std::vector<const OpDataSocket*> connections() const;

		static bool canConnect(const OpDataSocket* socket_1, const OpDataSocket* socket_2);

		OpDataSocket::Flags flags() const;

	private:
		unsigned int 				_id;
		unsigned int 				_opdata_type_version;
		std::string 				_opdata_type_name = "";
		OpDataSocket::Flags _flags;

		std::vector<const OpDataSocket*> 	_connections;
};

}

ALLOW_FLAGS_FOR_ENUM(copper::OpDataSocket::Flags)

#endif // OP_DATA_SOCKET_H