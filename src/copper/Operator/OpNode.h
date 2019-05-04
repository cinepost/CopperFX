#ifndef OP_NODE_H
#define OP_NODE_H

#include <string>
#include <map>
#include <unordered_map>

#include "copper/Util/UT_StringUtils.h"
#include "copper/OpParameter/OpParameter.h"
#include "copper/Operator/OpCreator.h"
#include "copper/Operator/NetworkBoxItem.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

class OpNetwork;

class OpNode : public NetworkBoxItem {
	friend class OP_Engine;
	friend class OpNetwork;

	public:
		OpNode(const OpNode &OpNode); // copy constructor

		OpNode 		*node(std::string OpNode_path);
		const std::string name() const;
		const std::string path() const ;
		void setName( std::string name );

	protected:
		OpNetwork 	*parent();
		OpNetwork 	*root();

	protected:
		OpNode(OpNetwork *parent, const std::string &name, OpCreator *op = nullptr);
		const std::string buildBase1NodeName(const std::string &name);
		OpNetwork 	*_parent;
		std::string	_name;
		OpBase 			*_operator;

		std::unordered_map<std::string, OpNode *> _children;

		std::vector<OpDataSocket> _inputs;
		std::vector<OpDataSocket> _outputs;
};

}

#endif // OP_NODE_H