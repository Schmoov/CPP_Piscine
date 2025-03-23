#include "Fixed.hpp"
#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	float e = 1.f/(1<<8);
	std::cout << "a is " << Fixed::epsilon << std::endl;
	std::cout << "b is " << b.getEpsilon() << std::endl;
	std::cout << "c is " << e << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << reinterpret_cast<int>(a.getRawBits()) << " as integer" << std::endl;
	std::cout << "b is " << reinterpret_cast<int>(b.getEpsilon().getRawBits()) << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
