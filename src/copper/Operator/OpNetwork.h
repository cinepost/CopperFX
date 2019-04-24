#ifndef OP_NETWORK_H
#define OP_NETWORK_H

#include "Operator/OP_Node.h"

#include <string>
#include <map>

class OpNetwork {//: public OP_Node {
	public:
		BaseOperator 	*addOp(const char *type, const char *name = 0);

	protected:
		// Protected constructor since networks are only created by Operators.
		OpNetwork(OP_Network *parent = nullptr, const char *name, OP_Operator *op);
		virtual ~OpNetwork();


	private:
		OP_Node *_parent;
		std::string	_name;
		std::map<std::string, OP_Node *> _children;
};

#endif // OP_NETWORK_H