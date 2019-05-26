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

class OpDataSocketTemplateBase {
	public:
		//virtual OpDataSocketTemplateBase(unsigned int idx, OpDataSocketTemplateFlags flags);
		virtual ~OpDataSocketTemplateBase();

		virtual OpDataSocketBase *createOpDataSocket() = 0;
};

template <class T>
class OpDataSocketTemplate: public OpDataSocketTemplateBase {
	static_assert(std::is_base_of<OpDataBase, T>::value, "T must inherit from OpDataBase");

	public:
		OpDataSocketTemplate(unsigned int idx, OpDataSocketTemplateFlags flags);
		OpDataSocketBase *createOpDataSocket();

	protected:
		unsigned int _idx;
		OpDataSocketTemplateFlags _flags;
};

template <class T>
OpDataSocketTemplate<T>::OpDataSocketTemplate(unsigned int idx, OpDataSocketTemplateFlags flags) {
	_idx = idx;
	_flags = flags;
}

template<class T>
OpDataSocketBase *OpDataSocketTemplate<T>::createOpDataSocket() {
	return new OpDataSocket<T>();
}

}

ALLOW_FLAGS_FOR_ENUM(copper::OpDataSocketTemplateFlags)

#endif // OP_DATA_SOCKET_TEMPLATE_H
