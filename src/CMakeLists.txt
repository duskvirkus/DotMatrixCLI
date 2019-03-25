cmake_minimum_required (VERSION 3.8)

add_executable (
	DotMatrixCli
	"CLI.cpp" 
	"CLI.h" 
	"DotMatrixCli.cpp" 
	"DotMatrixCli.h" 
	"TestConfig.h" 
	"${DOCTEST_PATH}/doctest.h"
)

add_executable (
	DotMatrixCliTest 
	"DotMatrixCli.cpp" 
	"DotMatrixCli.h" 
	"TestConfig.h"
	"${DOCTEST_PATH}/doctest.h"
)
target_compile_definitions(DotMatrixCliTest PRIVATE TESTING)

