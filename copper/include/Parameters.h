#ifndef __Parameters_h__
#define __Parameters_h__

class Parameters {
	public:
		// these next two are the minimal overrides for subclasses that have
		// transforms (see OBJ_Node)
		//virtual const UT_DMatrix4& getWorldTransformRef(int &ret, OP_Context &);
		//virtual const UT_DMatrix4& getIWorldTransformRef(int &ret, OP_Context &);
};

#endif