#include "Point.hpp"
#include <iostream>

int main()
{
	float p[3][2];
	std::cout << "Enter 3 coordinates:\n";
	std::cin >> p[0][0] >> p[0][1];
	std::cin >> p[1][0] >> p[1][1];
	std::cin >> p[2][0] >> p[2][1];

	Point a(p[0][0], p[0][1]);
	Point b(p[1][0], p[1][1]);
	Point c(p[2][0], p[2][1]);
	for (float y = 10.0; y >= -10.0; y--) {
		for (float x = -10.0; x <= 10.0; x++) {
			std::cout << (bsp(a, b, c, Point(x,y)) ? "X|" : "_|");
		}
		std::cout << "\n";
	}
}
