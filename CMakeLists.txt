

cmake_minimum_required(VERSION 2.8.11)

project(InterviewQuestion)

# if(GTEST MATCHES "Yes")
# 	MESSAGE(STATUS ${GTEST_DIR})
# 	INCLUDE_DIRECTORIES(${GTEST_DIR}/include)
# 	link_directories(${GTEST_DIR}/libs)
# endif()

#rpath

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
	message(STATUS "This is mac")
	set(CMAKE_MACOSX_RPATH 1)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  	message(STATUS "This is Linux")
endif()

add_subdirectory(Common)

option(build_tests "Build the project's unit tests" OFF)

if(build_tests)
  	add_subdirectory(test)
  	add_subdirectory(gtest-1.7.0)
endif()