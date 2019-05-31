#ifndef SYS_COMPILER_H
#define SYS_COMPILER_H

// Define "explicit" for C++11 safe-bool operator
#if (__cplusplus >= 201103) || (_MSC_VER >= 1800)
	#define SYS_SAFE_BOOL       explicit
#else
	#define SYS_SAFE_BOOL       
#endif

#define SYS_SAFE_BOOL       explicit

#endif // SYS_COMPILER_H