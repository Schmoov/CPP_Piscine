#include <string>
#include <iostream>

class Contact {
	public :
		std::string	info[5];

	void	print()
	{
		for (int i = 0; i < 5; i++) {
			std::cout << info[i] << '\n';
		}
	}
};
