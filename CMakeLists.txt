cmake_minimum_required(VERSION 3.11)
project(test)

option(DYNAMIC "Build dynamic library" ON)

if(DYNAMIC)
    add_library(singleton STATIC singleton_lib.hpp singleton_lib.cc)
    target_include_directories(singleton PUBLIC .)
    set_target_properties(singleton PROPERTIES POSITION_INDEPENDENT_CODE ON)
    add_library(wrapper SHARED wrapper.hpp wrapper.cc)
    target_link_libraries(wrapper PUBLIC singleton)
    target_include_directories(wrapper PUBLIC .)
    target_compile_definitions(wrapper PUBLIC -DEXPORTING_DLL)
    add_executable(singleton_test test.cc)
    target_link_libraries(singleton_test PUBLIC wrapper)
else()
    add_library(singleton_withwrraper STATIC
    singleton_lib.hpp singleton_lib.cc wrapper.hpp wrapper.cc)
    set_target_properties(singleton_withwrraper PROPERTIES POSITION_INDEPENDENT_CODE ON)
    target_include_directories(singleton_withwrraper PUBLIC ${CMAKE_CURRENT_LIST_DIR})
    add_executable(singleton_test test.cc)
    target_link_libraries(singleton_test PUBLIC singleton_withwrraper)
endif()

