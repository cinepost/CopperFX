#ifndef __OP_Network_h__
#define __OP_Network_h__

#include "Operator/OP_Node.h"

#include <string>
#include <map>

class OP_Network : public OP_Node {
	public:
		OP_Node 	*createNode(const char *type, const char *name = 0);

	protected:
		// Protected constructor since networks are only created by Operators.
		OP_Network(OP_Network *parent, const char *name, OP_Operator *op);
		virtual ~OP_Network();


	private:
		OP_Node *_parent;
		std::string	_name;
		std::map<std::string, OP_Node *> _children;
};

#endif