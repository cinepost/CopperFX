#include <algorithm>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpDataSocket.h"


namespace copper {


OpDataSocket::OpDataSocket(
	unsigned int id,
	unsigned int opdata_type_version,
	const std::string &opdata_type_name,
	OpDataSocket::Flags flags
): _id(id), _opdata_type_version(opdata_type_version), _opdata_type_name(opdata_type_name), _flags(flags) {
	if ((flags & OpDataSocket::Flags::INPUT_SOCKET) && (flags & OpDataSocket::Flags::OUTPUT_SOCKET)) {
		BOOST_LOG_TRIVIAL(error) << "OpDataSocket must be either INPUT_SOCKET or OUTPUT_SOCKET not both !!!";
	}

}

bool OpDataSocket::isInput() const {
  if (_flags & OpDataSocket::Flags::INPUT_SOCKET) {
    return true;
  }
  return false;
}

bool OpDataSocket::isOutput() const {
  if (_flags & OpDataSocket::Flags::OUTPUT_SOCKET) {
    return true;
  }
  return false;
}

bool OpDataSocket::connect(OpDataSocket *socket) {
	if ((this->isInput() && socket->isInput()) || (this->isOutput() && socket->isOutput())) {
		BOOST_LOG_TRIVIAL(error) << "OpDataSocket can not connect socket of the same type !";
		return false;
	}

	if ( std::find(_connections.begin(), _connections.end(), socket) != _connections.end() ) {
		// already connected
  	BOOST_LOG_TRIVIAL(warning) << "OpDataSocket already connected !";
	} else {
  	_connections.push_back(socket);
	}

	return true;
}

std::vector<OpDataSocket*> OpDataSocket::connections() {
	return _connections;
}

OpDataSocket::Flags OpDataSocket::flags() const {
	return _flags;
}

}