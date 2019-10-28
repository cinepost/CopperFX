#ifndef OP_BASE_H
#define OP_BASE_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"
#include "copper/Plugin/TypeInfo.h"
#include "copper/OpData/OpDataBase.h"


namespace copper {

typedef unsigned int uint;

class OpBase {//: public BaseAPI {
	public:
		virtual bool cookData(uint output_index, OpDataBase &out_data) = 0;
};

}

#endif // OP_BASE_H