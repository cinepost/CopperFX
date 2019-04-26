#ifndef OP_PARAMETER_H
#define OP_PARAMETER_H

class OpParameter {
	public:
		OpParameter();
		// these next two are the minimal overrides for subclasses that have
		// transforms (see OBJ_Node)
		//virtual const UT_DMatrix4& getWorldTransformRef(int &ret, OP_Context &);
		//virtual const UT_DMatrix4& getIWorldTransformRef(int &ret, OP_Context &);
};

#endif // OP_PARAMETER_H