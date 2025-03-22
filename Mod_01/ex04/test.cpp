#include <cstdlib>
#include <string>
#include <iostream>

void findAndReplace(std::string& s, const std::string& find, const std::string& replace, size_t pos = 0);

void replaceAll(std::string &s, const std::string &find, const std::string &replace) {
    size_t pos = 0;
    while ((pos = s.find(find, pos)) != std::string::npos) {
        s.replace(pos, find.length(), replace);
        pos += replace.length();
    }
}

void runTest(std::string &s, const std::string &find, const std::string &replace)
{
	std::string expected = s;
	std::string found = s;
	replaceAll(expected, find, replace);
	findAndReplace(found, find, replace);
	if (expected != found) {
		std::cout << "expected:\n" << expected << std::endl;
		std::cout << "found:\n" << found << std::endl;
		std::cout << "throwing up now 🤮" << std::endl;
		throw "up";
	}
	/*
	std::cerr << "~~~~~~~~~~~~~~~\n";
	std::cerr << s << "\n";
	std::cerr << find << "->" << replace << "\n";
	std::cerr << found << "\n";
	std::cerr << "~~~~~~~~~~~~~~~\n";
	*/
}


int main()
{
	std::string str;

	{
		str = "Bananananbababanan banana ba nana\n\n ananas nana\n";
		runTest(str, "an", "ok");
		runTest(str, "an", "anan");
		runTest(str, "a", "ana");
		runTest(str, "ana", "a");
		runTest(str, "\n", "NEWLINE\n");
		runTest(str, "no match", "poopoo");
	}
	std::cerr << "Great success\n";
}
