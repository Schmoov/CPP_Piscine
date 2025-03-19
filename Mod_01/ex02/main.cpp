#include <string>
#include <iostream>

int main()
{
	std::string s("HI THIS IS BRAIN");
	std::string* stringPTR = &s;
	std::string& stringREF = s;
	
	std::cout << "Address is : " << &s << "\n";
	std::cout << "Address is : " << stringPTR << "\n";
	std::cout << "Address is : " << &stringREF << "\n";

	std::cout << "Value is : " << s << "\n";
	std::cout << "Value is : " << *stringPTR << "\n";
	std::cout << "Value is : " << stringREF << "\n";
}
