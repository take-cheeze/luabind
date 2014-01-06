cmake_minimum_required(VERSION 2.8)

project(luabind CXX)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

find_package(Lua51 REQUIRED)
find_package(Boost REQUIRED)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}"
  ${LUA_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS})

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" luabind_srcs)
add_library("${PROJECT_NAME}" ${luabind_srcs})

enable_testing()

add_library(luabind_test "${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp")

file(GLOB luabind_tests "${CMAKE_CURRENT_SOURCE_DIR}/test/test_*.cpp")
foreach(test_file ${luabind_tests})
  get_filename_component(test "${test_file}" NAME_WE)

  add_executable("${test}" "${test_file}")
  target_link_libraries("${test}" luabind luabind_test ${LUA_LIBRARIES})

  add_test("${test}" "${CMAKE_BIANRY_DIR}/bin/${test}")
endforeach()
