#pragma once

class Fixed {
private:
	int val;
	static const int frac = 8;
public:
	Fixed();
	Fixed(const Fixed& a);
	Fixed& operator=(const Fixed& t);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
};
