#ifndef BOX_GEOMETRY_OP_H
#define BOX_GEOMETRY_OP_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpTable.h"

namespace copper {

class BoxGeometryOp : public OpBase {
  public:
    BoxGeometryOp();
    ~BoxGeometryOp();

  public:
    bool cookData(uint output_index, OpDataBase &out_data);

  public:
    // factory method
    static void registerOperator(OpTable *op_table);
    static OpBase *myConstructor();
};

}

#endif // BOX_GEOMETRY_OP_H