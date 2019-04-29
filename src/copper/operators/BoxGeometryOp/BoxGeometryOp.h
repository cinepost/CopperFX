#ifndef BOX_GEOMETRY_OP_H
#define BOX_GEOMETRY_OP_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "copper/Operator/OperatorBase.h"


namespace copper {

class BoxGeometryOp : public OperatorBase {
  public:
    BoxGeometryOp();
    ~BoxGeometryOp();

  public:
    const std::string name() const;
    const std::string typeName() const;
    const unsigned int version() const;

    bool cookData(OpDataBase &out_data);

  public:
    // factory methods
    static std::string myTypeName();
    static OperatorBase *myConstructor();
};

}

#endif // BOX_GEOMETRY_OP_H