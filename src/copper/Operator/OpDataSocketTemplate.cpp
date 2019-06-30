#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpDataSocketTemplate.h"


namespace copper {

OpDataSocketTemplate::OpDataSocketTemplate(unsigned int idx, OpDataSocketTemplateFlags flags) {
	_idx = idx;
	_flags = flags;
}

OpDataSocket *OpDataSocketTemplate::createOpDataSocket(OpNode *op_node) {
	OpDataSocket *opdata_socket_ptr = new OpDataSocket(op_node);
	if (_flags & OpDataSocketTemplateFlags::INPUT_SOCKET) {
		opdata_socket_ptr->_is_input = true;
		if (_flags & OpDataSocketTemplateFlags::MULTI_INPUT_SOCKET) {
			opdata_socket_ptr->_is_multi_input = true;
		}
	} else {
		opdata_socket_ptr->_is_input = opdata_socket_ptr->_is_multi_input = false;
	}
	return opdata_socket_ptr;
}

}