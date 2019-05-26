#ifndef OP_TABLE_H
#define OP_TABLE_H

#include <vector>
#include <unordered_map>

#include "copper/Plugin/AbstractFactory.h"
#include "copper/Operator/OpBase.h"

namespace copper {

class OpNodeTemplate;	

class OpTable {
	public:
		void registerOpNodeTemplate(OpNodeTemplate *op_template);
		OpNodeTemplate *getOpNodeTemplate(const std::string &type_name);
		const std::vector<std::string> registeredTypeNames() const;

	private:
		std::unordered_map<std::string, OpNodeTemplate* > _op_node_templates_by_type_name;
};

}

#endif // OP_TABLE_H