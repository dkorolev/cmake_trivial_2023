cmake_minimum_required(VERSION 3.14.1)

project(cmake_trivial_2023 C CXX)

set (CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

include(FetchContent)

if (EXISTS "${CMAKE_SOURCE_DIR}/../current" AND IS_DIRECTORY "${CMAKE_SOURCE_DIR}/../current")
  set(FETCHCONTENT_QUIET FALSE)
  message("Using 'CMAKE_SOURCE_DIR/../current' instead of cloning it via `FetchContent`.")
  set(current_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../current")
elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../current" AND IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../current")
  message("Using 'CMAKE_CURRENT_SOURCE_DIR/../current' instead of cloning it via `FetchContent`.")
  set(current_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../current")
else()
  FetchContent_Declare(current
                       GIT_REPOSITORY https://github.com/c5t/current
                       GIT_TAG stable
                       GIT_SHALLOW TRUE)
  FetchContent_MakeAvailable(current)
endif()

include_directories(${current_SOURCE_DIR})

# Declare libraries as library targets. And add them into the `ALL_LIBRARIES` list.
set(ALL_LIBRARIES "Threads::Threads")
file(GLOB_RECURSE LIBRARY_SOURCE_FILES "src/lib_*.cc")
foreach(LIBRARY_SOURCE_FILE ${LIBRARY_SOURCE_FILES})
  get_filename_component(LIBRARY_TARGET_NAME "${LIBRARY_SOURCE_FILE}" NAME_WE)
  add_library(${LIBRARY_TARGET_NAME} "${LIBRARY_SOURCE_FILE}") 
  list(APPEND ALL_LIBRARIES "${LIBRARY_TARGET_NAME}")
endforeach()

# Declare binaries as binary targets. And link them against all the libraries.
file(GLOB_RECURSE BINARY_SOURCE_FILES "src/bin_*.cc")
set(BLAH "Threads::Threads lib_mul")
foreach(BINARY_SOURCE_FILE ${BINARY_SOURCE_FILES})
  get_filename_component(BINARY_TARGET_NAME "${BINARY_SOURCE_FILE}" NAME_WE)
  add_executable(${BINARY_TARGET_NAME} "${BINARY_SOURCE_FILE}") 
  target_link_libraries(${BINARY_TARGET_NAME} PRIVATE "${ALL_LIBRARIES}")
endforeach()

# Declare tests as test targets. And link them against all the libraries.
enable_testing()
file(GLOB_RECURSE TEST_SOURCE_FILES "src/test_*.cc")
foreach(TEST_SOURCE_FILE ${TEST_SOURCE_FILES})
  get_filename_component(TEST_TARGET_NAME "${TEST_SOURCE_FILE}" NAME_WE)
  add_executable(${TEST_TARGET_NAME} "${TEST_SOURCE_FILE}") 
  target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${ALL_LIBRARIES}")
  add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})
endforeach()
