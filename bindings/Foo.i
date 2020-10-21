// -*- c++ -*-
/* File : Foo.i */

%module Foo

// Python
#ifdef SWIGPYTHON
%include "./python/eigen.i"
#endif


// Pull in the headers from Python itself and from our library
%{
#define SWIG_FILE_WITH_INIT
#include <Python.h>

#include "../include/foo.h"
%}

%eigen_typemaps(Eigen::Vector4d)
%include "../include/foo.h"
