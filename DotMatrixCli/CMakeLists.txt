
cmake_minimum_required (VERSION 3.8)

add_executable (
	DotMatrixCli
	"CLI.cpp" 
	"CLI.h" 
	"doctest.h" 
	"DotMatrixCli.cpp" 
	"DotMatrixCli.h" 
	"TestConfig.h"
)

add_executable (
	DotMatrixCliTest 
	"doctest.h" 
	"DotMatrixCli.cpp" 
	"DotMatrixCli.h" 
	"TestConfig.h"
)
target_compile_definitions(DotMatrixCliTest PRIVATE TESTING)

