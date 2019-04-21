#ifndef GEOMETRY_OP_DATA_H
#define GEOMETRY_OP_DATA_H

#include <string>
#include <map>

#include "copper/OpData/BaseOpData.h"


namespace copper {

class GeometryOpData: public BaseOpData {
	public:
		GeometryOpData();

		virtual const std::string name() const;
		virtual const std::string typeName() const;
		virtual const unsigned int version() const;
		
	private:
		
};

}

#endif // GEOMETRY_OP_DATA_H