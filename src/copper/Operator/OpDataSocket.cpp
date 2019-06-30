#include <algorithm>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpNode.h"
#include "OpDataSocket.h"


namespace copper {

boost::uuids::string_generator gen;

OpDataSocket::OpDataSocket() {
	_op_node = nullptr;
	_id = 0;
	_input_guids.clear();
	_data_type_uuid = gen("{01234567-89ab-cdef-0123-456789abcdef}");
}

OpDataSocket::~OpDataSocket() {}

/*
OpDataSocket::OpDataSocket(unsigned int id, unsigned int opdata_type_version, const std::string &opdata_type_name, OpDataSocket::Flags flags ) {
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

unsigned int OpDataSocket::idx() const {
	return _id;
}

bool OpDataSocket::isInput() const {
  return _is_input;
}

bool OpDataSocket::isMultiInput() const {
  return _is_input && _is_multi_input;
}

bool OpDataSocket::isOutput() const {
  return !_is_input;
}

bool OpDataSocket::canConnect(const OpDataSocket* socket_1, const OpDataSocket* socket_2) {
	if (!socket_1 || !socket_2) {
		// one of socket pointers is null
		BOOST_LOG_TRIVIAL(debug) << "OpDataSocket fatal connection error !";
		return false;
	}
	if ((socket_1->GUID() == socket_2->GUID()) || (socket_1->_op_node_guid == socket_2->_op_node_guid)) {
		// same socket or same node sockets
		BOOST_LOG_TRIVIAL(debug) << "OpDataSocket can't be connected to itself !";
		return false;
	}
	if (socket_1->dataTypeUUID() != socket_2->dataTypeUUID()) {
		// different data types
		BOOST_LOG_TRIVIAL(debug) << "OpDataSocket can't be connected to different data type socket without converters available !";
		return false;
	}
	if ((socket_1->isInput() && socket_2->isInput()) || (socket_1->isOutput() && socket_2->isOutput())) {
		// both inputs or outputs
		BOOST_LOG_TRIVIAL(debug) << "OpDataSocket's can't be both inputs or outputs !";
		return false;
	}	
	return true;
}

bool OpDataSocket::setInput(const OpDataSocket *socket) {
	if (!isInput()) return false; // only input socket can be connected
	if (!OpDataSocket::canConnect(this, socket)) return false; // additional checks

	if (!isMultiInput()) {
		// this is not multi input socket so clear old connection first
		_input_guids.clear();
	}

  _input_guids.push_back(socket->GUID());
	return true;
}

const std::vector<OpDataSocketGUID>& OpDataSocket::inputGUIDs() const {
	return _input_guids;
}

boost::uuids::uuid OpDataSocket::dataTypeUUID() const {
	return _data_type_uuid;
}

}