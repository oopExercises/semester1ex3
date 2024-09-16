#pragma once
#include <iosfwd>
#include <iostream>


class Zi
{
private:
	int m_real;
	int m_imag;
public:
	//constructor
	Zi(int real = 0, int imag = 0);

	//returning functions
	int real()const;
	int imag()const;
	int norm()const;
	Zi conj() const;
	bool dividedBy(const Zi& divisor) const;

	//local operators
	//arthmatic operators with equal
	Zi& operator+=(const Zi& z);
	Zi& operator-=(const Zi& z);
	Zi& operator*=(const Zi& multiple);
	Zi& operator/=(const Zi& down);
	Zi& operator%=(const Zi& down);

};
	//global operators
	// 
	//arthmatic operators 
	Zi operator+(const Zi& z1, const Zi& z2);
	Zi operator-(const Zi& z1, const Zi& z2);
	Zi operator*(const Zi& z1, const Zi& z2);
	Zi operator/(const Zi& z1, const Zi& z2);
	Zi operator%(const Zi& up, const Zi& down);

	//unary minus operator
	Zi operator-(const Zi& z1);

	//equality operator
	bool operator==(const Zi& z1, const Zi& z2);
	//inequality operator
	bool operator!=(const Zi& z1, const Zi& z2);
	//printing operator
	std::ostream& operator <<(std::ostream& os, const Zi& z);
