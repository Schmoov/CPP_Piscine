#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void findAndReplace(std::string& s, const std::string& find, const std::string& replace, size_t pos = 0);

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cerr << "Usage : Filename ToFind ToReplace \n";
		return EXIT_FAILURE;
	}
	if (!argv[2][0] || !argv[3][0]) {
		std::cerr << "ToFind and ToReplace cannot be empty\n";
		return EXIT_FAILURE;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open()) {
		input.clear();
		std::cerr << "Could not open \"" << argv[1] << "\"\n";
		return EXIT_FAILURE;
	}
	std::ostringstream buf;
	buf << input.rdbuf();
	std::string str = buf.str();
	input.close();

	findAndReplace(str, argv[2], argv[3]);

	std::ofstream output;
	std::string oname = std::string(argv[1]) + std::string(".replace");
	output.open(oname.c_str());
	if (!output.is_open()) {
		output.clear();
		std::cerr << "Could not create \"" << std::string(argv[1]) + ".replace \"\n";
		return EXIT_FAILURE;
	}
	output << str;
	output.close();
	return EXIT_SUCCESS;
}
