#ifndef OPERATOR_BASE_H
#define OPERATOR_BASE_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"
#include "copper/OpData/OpDataBase.h"


namespace copper {

class OperatorBase: public BaseAPI {
	public:
		virtual bool cookData(OpDataBase &out_data) = 0;
};

}

#endif // OPERATOR_BASE_H