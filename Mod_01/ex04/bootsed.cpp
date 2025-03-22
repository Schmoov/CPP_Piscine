#include <cstdlib>
#include <string>

void findAndReplace(std::string& s, const std::string& find, const std::string& replace, size_t pos = 0)
{
	size_t match = s.find(find, pos);
	if (match == std::string::npos)
		return;
	findAndReplace(s, find, replace, match + find.length());
	s = s.substr(0, match) + replace + s.substr(match + find.length());
}
