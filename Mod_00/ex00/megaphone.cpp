#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			std::string s = argv[i];
			for (std::string::iterator it=s.begin(); it != s.end(); it++) {
				std::cout << static_cast<char> (std::toupper(*it));
			}
		}
		std::cout << std::endl;
	}
}
