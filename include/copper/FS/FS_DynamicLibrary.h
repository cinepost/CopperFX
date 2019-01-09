#ifndef __FS_DynamicLibrary_h__
#define __FS_DynamicLibrary_h__

#include <string>


class FS_DynamicLibrary {
	public:
	  static FS_DynamicLibrary * load(const std::string & path, std::string &errorString);
	  ~FS_DynamicLibrary();
	  void * getSymbol(const std::string & name);
	private:
	  FS_DynamicLibrary();
	  FS_DynamicLibrary(void * handle);
	  FS_DynamicLibrary(const FS_DynamicLibrary &);
	private:
	  void * handle_;  
};


#endif // __FS_DynamicLibrary_h__