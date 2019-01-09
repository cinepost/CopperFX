#include <stdio.h>
#include <stdlib.h>

#include <boost/python.hpp>


using namespace boost::python;

#if PY_MAJOR_VERSION >= 3
#   define INIT_MODULE PyInit_hou
    extern "C" PyObject* INIT_MODULE();
#else
#   define INIT_MODULE inithou
    extern "C" void INIT_MODULE();
#endif


int main(int argc, char *argv[]) {

    try {
    	Py_SetProgramName("lalala");
        PyImport_AppendInittab((char*)"hou", INIT_MODULE);
        Py_Initialize();
        
        PyRun_SimpleString("import hou");
        PyRun_InteractiveLoop(stdin, "-");
        Py_Finalize();
    } catch (error_already_set& e) {
        PyErr_PrintEx(0);
        return 1;
    }

    return 0;
}