#include "../include/GPU_Manager.h"

GPU_Manager::GPU_Manager() {
	std::cout << "Initializing GPU Manager..." << std::endl;

	// *** Initialize OpenCL *** //
	_opencl_ready = false;
	cl_int ret;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_device_id device_id = NULL;
	cl_platform_id platform_id = NULL;
	
	_opencl_context = NULL;
	_opencl_command_queue = NULL;

	// Get platform and device info
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

	// Create OpenCL context
	_opencl_context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	// Create Command Queue
	_opencl_command_queue = clCreateCommandQueue(_opencl_context, device_id, 0, &ret);

	_opencl_ready = true;
	std::cout << "GPU Manager initialized. All done." << std::endl;
}


bool GPU_Manager::isOpenCLEnabled(){
	return _opencl_ready;
}


cl_context GPU_Manager::getOpenCLContext() {
	if (_opencl_ready) {
		return _opencl_context;
	}
	return false;
}


cl_command_queue GPU_Manager::getOpenCLCommandQueue() {
	if (_opencl_ready) {
		return _opencl_command_queue;
	}
	return false;
}