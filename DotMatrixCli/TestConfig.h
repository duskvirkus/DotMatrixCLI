#pragma once
#ifdef TESTING
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
int main(int argc, char** argv) {
	int returnValue = doctest::Context(argc, argv).run();
	std::system("Pause");
	return returnValue;
}
#else
#define DOCTEST_CONFIG_DISABLE
#include "doctest.h"
#endif // !TESTING