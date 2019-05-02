#include "OpFactory.h"


namespace copper {

void OpFactory::registerOperator(OpCreator *op_creator) {
	registerType(
		op_creator->typeName(), 
		op_creator->constructor()
	);
	_op_creators_by_type_name.push_back(op_creator);
}

}