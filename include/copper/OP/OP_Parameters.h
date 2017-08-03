#ifndef __OP_Parameters_h__
#define __OP_Parameters_h__

class OP_Parameters {
	public:
		// these next two are the minimal overrides for subclasses that have
		// transforms (see OBJ_Node)
		//virtual const UT_DMatrix4& getWorldTransformRef(int &ret, OP_Context &);
		//virtual const UT_DMatrix4& getIWorldTransformRef(int &ret, OP_Context &);
};

#endif