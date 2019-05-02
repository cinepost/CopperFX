#ifndef OP_FACTORY_H
#define OP_FACTORY_H

#include <vector>

#include "copper/Plugin/AbstractFactory.h"
#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpCreator.h"

namespace copper {
	
class OpFactory: public AbstractFactory<OpBase> {
	public:
		void registerOperator(OpCreator *op);

	private:
		std::vector<OpCreator *> _op_creators_by_type_name;
};

}

#endif // OP_FACTORY_H