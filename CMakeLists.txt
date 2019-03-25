
cmake_minimum_required (VERSION 3.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project ("DotMatrixCLI")

set(DOCTEST_PATH ${PROJECT_SOURCE_DIR}/dependencies/doctest/doctest)

include_directories(${DOCTEST_PATH})

add_subdirectory ("src")
