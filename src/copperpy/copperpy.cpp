#include <stdio.h>
#include <stdlib.h>

#include <boost/python.hpp>


using namespace boost::python;

#if PY_MAJOR_VERSION >= 3
#   define INIT_MODULE PyInit_cfx
    extern "C" PyObject* INIT_MODULE();
#else
#   define INIT_MODULE initcfx
    extern "C" void INIT_MODULE();
#endif


int main(int argc, char *argv[]) {

    try {
    	//Py_SetProgramName("somename"); // do i need this !?
        PyImport_AppendInittab((char*)"cfx", INIT_MODULE);
        Py_Initialize();

        PyRun_SimpleString("import cfx");
        PyRun_InteractiveLoop(stdin, "-");
        Py_Finalize();
    } catch (error_already_set& e) {
        PyErr_PrintEx(0);
        return 1;
    }

    return 0;
}