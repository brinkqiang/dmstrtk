cmake_minimum_required(VERSION 3.2)

PROJECT(dmstrtk)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

ModuleImportAll("thirdparty")
ExeImport("test" "")
