#ifndef __SCN_Scene_h__
#define __SCN_Scene_h__

#include <string>
#include <vector>

#include <copper/Sys/SysCompiler.h>
#include <copper/Sys/SysTypes.h>

class SCN_Scene {
	public:
		SCN_Scene();

	/// This class is used to return the status from I/O operations on a
	/// SCN_Scene.
	class IOStatus {
		public:
			IOStatus(bool success=false) : mySuccess(success){}
			IOStatus(const IOStatus &src) : mySuccess(src.mySuccess){}
			~IOStatus() {}

			IOStatus &operator=(const IOStatus &src) {
				if (this != &src)
					mySuccess = src.mySuccess;
				return *this;
			}
 
			/// Return a boolean for success or failure.
			/// true means success
			bool	success() const { return mySuccess; }
 
			/// bool operator
			SYS_SAFE_BOOL operator bool() const { return mySuccess; }
 
			/// For backward compatibility in older code, you can query the status
			/// as an integer, 0 for success, less than zero for failure.
			int	gbstatus() const { return mySuccess ? 0 : -1; }

		private:
			bool	mySuccess;
	};
};


#endif // __SCN_Scene_h__