#ifndef OP_NODE_H
#define OP_NODE_H

#include <string>
#include <map>

#include "copper/Util/UT_StringUtils.h"
#include "copper/OpParameter/OpParameter.h"
#include "copper/Operator/OpCreator.h"
#include "copper/Operator/NetworkBoxItem.h"


namespace copper {

class OpNetwork;

class OpNode : public NetworkBoxItem {
	friend class OP_Engine;
	friend class OpNetwork;

	public:
		OpNode(const OpNode &OpNode); // copy constructor

		OpNode 		*node(std::string OpNode_path);
		const std::string getName();
		const std::string path();
		void setName( std::string name );

	protected:
		OpNetwork 	*parent() const;
		OpNetwork 	*root() const;

	protected:
		OpNode(OpNetwork *parent, std::string name, OpCreator *op = nullptr);
		std::string buildBase1NodeName(std::string name);
		OpNetwork 	*_parent;
		std::string	_name;
		OpBase 			*_operator;
		std::map<std::string, OpNode *> _children;
};

}

#endif // OP_NODE_H