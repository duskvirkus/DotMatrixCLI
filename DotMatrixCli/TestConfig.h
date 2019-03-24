#pragma once
#ifdef TESTING
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
int main(int argc, char** argv) {
	int returnValue = doctest::Context(argc, argv).run();
	std::cin.get();
	return returnValue;
}
#else
#define DOCTEST_CONFIG_DISABLE
#include "doctest.h"
#endif // !TESTING