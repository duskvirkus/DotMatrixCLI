#include "DotMatrixCli.h"

namespace DotMatrixCli {
	void start() {
		std::cout << "Dot Matrix CLI" << std::endl;
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
		std::cout << "Creator: Fi Graham" << std::endl;
		std::cout << "Description: This is a utility for creating dot matrix style designs. It will " << std::endl;
		std::cout << "export in XML format for use in other projects." << std::endl;
		std::cout << "License: MIT" << std::endl;
		std::cout << "===============================================================================" << std::endl;
	}

	void run() {
		DotMatrixSettings settings;
		settings = getSettings();
	}

	void end() {
		std::system("PAUSE");
	}

	DotMatrixSettings getSettings() {
		bool getUserInput = true;
		DotMatrixSettings settings;
		while (getUserInput) {
			std::cout << "Enter Dot Matrix Width and Height:" << std::endl;
			settings.width = getUShort();
			settings.height = getUShort();
			std::cout << std::endl;

			std::cout << "Dot Matrix Size:" << std::endl;
			std::cout << "Width = " << settings.width << std::endl;
			std::cout << "Height = " << settings.height << std::endl;
			if (settings.width > 20 || settings.height > 20) {
				std::cout << "Using a matrix with dimensions larger than 20 is not recommended." << std::endl;
			}

			getUserInput = !checkInput();
		}
		return settings;
	}

	unsigned short getUShort() {
		unsigned short input;
		while (!(std::cin >> input) || input == 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

			std::cout << "Invalid input! Expected whole number between ";
			std::cout << static_cast<int>(std::numeric_limits<unsigned short>::min() + 1);
			std::cout << " and ";
			std::cout << static_cast<int>(std::numeric_limits<unsigned short>::max());
			std::cout << ". Please enter a new number:" << std::endl;
		}
		return input;
	}

	bool checkInput() {
		char input;
		std::cout << "Is this correct? (y/n)" << std::endl;
		while (!(std::cin >> input) || !(input == 'y' || input == 'n')) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
			std::cout << "Is this correct? (y/n)" << std::endl;
			break;
		}
		std::cout << std::endl;
		if (input == 'y') {
			return true;
		}
		return false;
	}
}

// Doctest Unit Testing

TEST_CASE("Test for getUShort function.") {
	REQUIRE(std::numeric_limits<unsigned short>::min() == 0);
	for (unsigned short i = 1; i < std::numeric_limits<unsigned short>::max(); i++) {
		std::istringstream fakeInput(std::to_string(i) + '\n');
		std::cin.rdbuf(fakeInput.rdbuf());
		CHECK(DotMatrixCli::getUShort() == i);
	}
}

TEST_CASE("Test for checkInput function") {
	SUBCASE("Testing \"y\\n\" input.") {
		std::istringstream fakeInput("y\n");
		std::cin.rdbuf(fakeInput.rdbuf());
		REQUIRE(DotMatrixCli::checkInput());
	}
	SUBCASE("Testing \"n\\n\" input.") {
		std::istringstream fakeInput2("n\n");
		std::cin.rdbuf(fakeInput2.rdbuf());
		REQUIRE_FALSE(DotMatrixCli::checkInput());
	}
}
