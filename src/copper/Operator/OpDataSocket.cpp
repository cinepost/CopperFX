#include <algorithm>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpNode.h"
#include "OpDataSocket.h"


namespace copper {

OpDataSocketBase::OpDataSocketBase() {
	_op_node = nullptr;
	_id = 0;
}

OpDataSocketBase::~OpDataSocketBase() {}

/*
OpDataSocketBase::OpDataSocketBase(unsigned int id, unsigned int opdata_type_version, const std::string &opdata_type_name, OpDataSocket::Flags flags ) {
	_op_node = nullptr;
	_id = id;
	_opdata_type_version = opdata_type_version;
	_opdata_type_name = opdata_type_name;
	_flags = flags;

	if ((flags & OpDataSocket::Flags::INPUT_SOCKET) && (flags & OpDataSocket::Flags::OUTPUT_SOCKET)) {
		BOOST_LOG_TRIVIAL(error) << "OpDataSocket must be either INPUT_SOCKET or OUTPUT_SOCKET not both !!!";
	}
}
*/

unsigned int OpDataSocketBase::idx() const {
	return _id;
}

bool OpDataSocketBase::isInput() const {
  return _is_input;
}

bool OpDataSocketBase::isMultiInput() const {
  return _is_input && _is_multi_input;
}

bool OpDataSocketBase::isOutput() const {
  return !_is_input;
}

bool OpDataSocketBase::canConnect(const OpDataSocketBase* socket_1, const OpDataSocketBase* socket_2) {
	if (!socket_1 || !socket_2) return false;
	// TODO: check if it's the same node sockets then return false
	if (socket_1->dataTypeName() != socket_2->dataTypeName()) return false;

	return true;
}

bool OpDataSocketBase::connect(const OpDataSocketBase *socket) {
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

std::vector<const OpDataSocketBase*> OpDataSocketBase::connections() const {
	return _connections;
}

}