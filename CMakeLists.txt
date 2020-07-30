cmake_minimum_required(VERSION 3.2)

PROJECT(dmstrtk)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMSTRTK_VERSION_MAJOR "1")
SET(DMSTRTK_VERSION_MINOR "0")
SET(DMSTRTK_VERSION_PATCH "1")
SET(DMSTRTK_VERSION "${DMSTRTK_VERSION_MAJOR}.${DMSTRTK_VERSION_MINOR}.${DMSTRTK_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSTRTK_VERSION}")

OPTION(USE_DMSTRTK "use dmstrtk" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmstrtk_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmstrtk_config.h)

ModuleImportAll("thirdparty")
LibImport("dmstrtk_module" "src/dmstrtk_module")
ExeImport("test" "dmstrtk_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmstrtktest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmstrtktest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmstrtk
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMSTRTK_LIBS "dmstrtk")
#MARK_AS_ADVANCED(${DMSTRTK_LIBS})