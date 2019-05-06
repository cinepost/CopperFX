#ifndef OP_TABLE_H
#define OP_TABLE_H

#include <vector>
#include <unordered_map>

#include "copper/Plugin/AbstractFactory.h"
#include "copper/Operator/OpBase.h"

namespace copper {

class OpDefinition;	

class OpTable {
	public:
		void registerOpDefinition(OpDefinition *op_def);
		OpDefinition* opDefinition(const std::string &type_name);
		std::vector<std::string> registeredTypeNames();

	private:
		std::unordered_map<std::string, OpDefinition *> _op_definitions_by_type_name;
};

}

#endif // OP_TABLE_H