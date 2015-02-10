
cmake_minimum_required(VERSION 2.8)

PROJECT(StlWriteIssue)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(StlWriteIssue MACOSX_BUNDLE StlWriteIssue)

target_link_libraries(StlWriteIssue ${VTK_LIBRARIES})
