#ifndef DT_GEOMETRY_H
#define DT_GEOMETRY_H

#include <string>
#include <map>

#include "copper/DT/DT_BaseData.h"

class DT_GeometryData: public DT_BaseData {
	public:
		DT_GeometryData();

		virtual std::string name() const;
		virtual bool cookData(float time);

	private:
		
};

#endif // DT_GEOMETRY_H