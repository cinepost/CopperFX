#ifndef COM_PYMODULE_H
#define COM_PYMODULE_H

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "OP/OP_Node.h"
#include "Engine.h"


template<class T>
struct vector_to_python_list {
  static PyObject* convert(const std::vector<T>& vec) {
    boost::python::list* l = new boost::python::list();
    for(std::size_t i = 0; i < vec.size(); i++)
      (*l).append(&vec[i]);

    return l->ptr();
  }
};

template<class T>
struct vector_to_python_tuple {
  static PyObject* convert(const std::vector<T>& vec) {
    boost::python::tuple* l = new boost::python::tuple();
    for(std::size_t i = 0; i < vec.size(); i++)
      (*l) += boost::python::make_tuple(&vec[i]);

    return l->ptr();
  }
};

#endif






