#ifndef BOX_GEOMETRY_OP_H
#define BOX_GEOMETRY_OP_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpFactory.h"

namespace copper {

class BoxGeometryOp : public OpBase {
  public:
    BoxGeometryOp();
    ~BoxGeometryOp();

  public:
    const std::string name() const;
    const std::string typeName() const;
    const unsigned int version() const;

    bool cookData(uint output_index, OpDataBase &out_data);

  public:
    // factory method
    static void registerOperator(OpFactory *op_factory);
    static OpBase *myConstructor();
};

}

#endif // BOX_GEOMETRY_OP_H