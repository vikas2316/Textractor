cmake_minimum_required(VERSION 3.5)

set(MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${MODULE_DIR})

project(Textractor)

add_compile_options(
  /std:c++17
  /MP
)

add_definitions(
  /DUNICODE # config.pri
  /D_UNICODE
)

include_directories(include)

if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
  set(CMAKE_FINAL_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Builds/${CMAKE_BUILD_TYPE}/x64)
else()
  set(CMAKE_FINAL_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Builds/${CMAKE_BUILD_TYPE}/x86)
endif()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_FINAL_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_FINAL_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_FINAL_OUTPUT_DIRECTORY})

set(CMAKE_CONFIGURATION_TYPES Debug Release)

add_subdirectory(GUI)
add_subdirectory(vnrhook)
add_subdirectory(extensions)
