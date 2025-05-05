#ifndef FIXED_H
#define FIXED_H

class Fixed
{
private:
	int val;
	static int other_val;
public:
	static int getVal();
	Fixed();
	~Fixed();
	Fixed(const Fixed& copied);
	
	Fixed& operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif