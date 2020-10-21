# Copyright (C) 2020 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.


set(CMAKE_SWIG_FLAGS "-Wextra;-module;Foo;-threads")


find_package(PythonInterp 3.6 REQUIRED)
find_package(PythonLibs 3.6 REQUIRED)

include_directories(${PYTHON_INCLUDE_PATH})
link_libraries(${PYTHON_LIBRARY})

## in Windows it seems necessary to declare explictly the link_directory
if(WIN32)
  get_filename_component(PYTHON_DIR ${PYTHON_LIBRARY} PATH)
  link_directories(${PYTHON_DIR})
endif()

set(target_name Foo_python)

set_source_files_properties(../Foo.i PROPERTIES CPLUSPLUS ON)
swig_add_module(${target_name} python ../Foo.i)
set_target_properties(_${target_name} PROPERTIES OUTPUT_NAME "_Foo")
set_target_properties(_${target_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/python)


# installation path is determined reliably on most platforms using distutils
execute_process(COMMAND ${PYTHON_EXECUTABLE}
    -c "from distutils import sysconfig; print(sysconfig.get_python_lib(1,0,prefix=''))"
    OUTPUT_VARIABLE PYTHON_INSTDIR)

string(STRIP ${PYTHON_INSTDIR} PYTHON_INSTDIR)
       install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Foo.py DESTINATION ${PYTHON_INSTDIR})
       install(TARGETS _${target_name} DESTINATION ${PYTHON_INSTDIR})

if(WIN32)
    set_target_properties(_${target_name} PROPERTIES SUFFIX ".pyd")
endif(WIN32)
