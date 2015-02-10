
cmake_minimum_required(VERSION 2.8)

PROJECT(StlWriteToStringIssue)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(StlWriteToStringIssue MACOSX_BUNDLE StlWriteToStringIssue)

target_link_libraries(StlWriteToStringIssue ${VTK_LIBRARIES})
