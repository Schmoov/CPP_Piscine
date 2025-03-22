#include <ostream>
#define FIXED_MAX (INT_MAX >> frac)
#define FIXED_MIN (-((INT_MAX >> frac) + 1))

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

	//new
	Fixed(const int n);
	Fixed(const float n);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed n);
