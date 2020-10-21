
#############################################################################
## Options for compiling supported languages.  There's nothing magical
## about this list, any SWIG-supported language should work - take a
## look at e.g. ruby code below for how to do it.

option(FRAMEWORK_USES_PYTHON "Do you want to create the Python bindings" FALSE)

find_package(SWIG)

if(SWIG_FOUND)
    include(UseSWIG)

    set_source_files_properties(Foo.i PROPERTIES CPLUSPLUS ON)
    link_libraries(foo)


    if(FRAMEWORK_USES_PYTHON)
        add_subdirectory(python)
    endif(FRAMEWORK_USES_PYTHON)
endif()
