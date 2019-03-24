#pragma once
#include <iostream>
#include "TestConfig.h"

namespace DotMatrixCli {

	struct DotMatrixSettings {
		unsigned short width;
		unsigned short height;
	};

	void start();
	void run();
	void end();

	DotMatrixSettings getSettings();
	unsigned short getUShort();
	bool checkInput();

}
