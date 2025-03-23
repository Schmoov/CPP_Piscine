#include <ostream>

class Fixed {
private:
	int val;
	static const int frac = 8;
public:
	Fixed();
	Fixed(const Fixed& a);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed& operator=(const Fixed& t);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	//new
	bool operator>(const Fixed& n) const;
	bool operator<(const Fixed& n) const;
	bool operator>=(const Fixed& n) const;
	bool operator<=(const Fixed& n) const;
	bool operator==(const Fixed& n) const;
	bool operator!=(const Fixed& n) const;
	Fixed operator+(const Fixed& n) const;
	Fixed operator-() const;
	Fixed operator-(const Fixed& n) const;
	Fixed operator*(const Fixed& n) const;
	Fixed operator/(const Fixed& n) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	static const Fixed epsilon;
	static const Fixed& getEpsilon();
};

std::ostream& operator<<(std::ostream& os, const Fixed& n);
