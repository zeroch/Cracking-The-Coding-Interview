project(common)

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g3 ")

set(SOURCE_FILE_LIST 
	Node
	)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY
	${PROJECT_SOURCE_DIR}/library)