project(testArray)

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g3 ")

include_directories( "../Common")
include_directories( "../LinkedLists")
link_directories( "../Common/library/" )


set(SOURCE_FILE_LIST 
        rangesumquery2d.cpp
	)


add_executable(${PROJECT_NAME} ${SOURCE_FILE_LIST})

