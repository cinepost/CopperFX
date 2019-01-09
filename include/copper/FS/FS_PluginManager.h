#ifndef __FS_PluginManager_h__
#define __FS_PluginManager_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "UT/UT_Singleton.h"


class FS_PluginManager: public UT_Singleton<FS_PluginManager> {
  friend class UT_Singleton<FS_PluginManager>;
	public:
		FS_PluginManager();

	private:
			    
};


#endif // __FS_PluginManager_h__