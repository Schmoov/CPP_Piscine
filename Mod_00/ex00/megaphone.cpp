#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			const std::string& s = argv[i];
			for (std::string::const_iterator it=s.begin(); it != s.end(); it++) {
				std::cout << static_cast<char> (std::toupper(*it));
			}
		}
	}
	std::cout << '\n';
}
