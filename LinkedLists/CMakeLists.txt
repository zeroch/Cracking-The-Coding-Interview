project(testLL)

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g3 ")

include_directories( "../Common")
link_directories( "../Common/library/" )
set(SOURCE_FILE_LIST 
	MyList
	main
	)

set( LIB_FILE_LIST	
	MyList)

add_library("List" SHARED ${LIB_FILE_LIST})
set_target_properties("List"
  PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../Common/library)



add_executable(${PROJECT_NAME} ${SOURCE_FILE_LIST})

target_link_libraries(${PROJECT_NAME} common)
