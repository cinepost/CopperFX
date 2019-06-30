#ifndef OP_DATA_SOCKET_TEMPLATE_H
#define OP_DATA_SOCKET_TEMPLATE_H

#include <string>
#include <vector>
#include <map>

#include <type_traits>

#include "flags/flags.hpp"
#include "copper/Plugin/PluginApi.h"
#include "copper/OpData/OpDataBase.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

enum class OpDataSocketTemplateFlags {
	INPUT_SOCKET = 0x01,
	OUTPUT_SOCKET = 0x02,
	MULTI_INPUT_SOCKET = 0x04
};

class OpDataSocketTemplate {
	public:
		OpDataSocketTemplate(unsigned int idx, OpDataSocketTemplateFlags flags);
		OpDataSocket *createOpDataSocket(OpNode *op_node);

	protected:
		unsigned int _idx;
		OpDataSocketTemplateFlags _flags;
};

}

ALLOW_FLAGS_FOR_ENUM(copper::OpDataSocketTemplateFlags)

#endif // OP_DATA_SOCKET_TEMPLATE_H
