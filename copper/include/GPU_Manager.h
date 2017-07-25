#ifndef __GPU_Manager_h__
#define __GPU_Manager_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define __NO_STD_VECTOR // Use cl::vector instead of STL version
#define __CL_ENABLE_EXCEPTIONS

#ifdef __APPLE__
    #include "OpenCL/opencl.h"
#else
    #include "CL/cl.h"
#endif

class GPU_Manager {
    public:
    	GPU_Manager();

    	bool isOpenCLEnabled();
    	cl_context getOpenCLContext();
    	cl_command_queue getOpenCLCommandQueue();

	private:
		bool				_opencl_ready;
		cl_context 			_opencl_context;
		cl_command_queue 	_opencl_command_queue;

};

#endif