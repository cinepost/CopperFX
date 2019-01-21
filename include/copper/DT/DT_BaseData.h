#ifndef DT_BASEDATA_H
#define DT_BASEDATA_H

#include <string>
#include <map>

#include "copper/PL/PL_PluginApi.h"


class DT_BaseData: public PL_DataAPI {
	public:
		DT_BaseData();

		virtual bool cookData(float time) = 0;

	private:
		
};

#endif // DT_BASEDATA_H