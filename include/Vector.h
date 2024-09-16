#pragma once
#include "Zi.h"
#include "Array.h"
#include <iostream>

class Vector
{
private:
	Array m_ziArray;

public:

	explicit Vector(int size = 0, const Zi& init = {});
	Vector(const Zi arr[], int size);

	int size()const;
	Array getArray() const; //return the private member (the array)

	//local operators
	//arthmatic operators with equal
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector& operator*=(const Vector& multiple);
	Vector& operator*=(int num); //multiply with a number

	//access operators
	Zi& operator[](int);
	Zi operator[](int) const;
};
	//global operators
	//arthmatic operators
	Vector operator-(const Vector& v);
	Vector operator+(const Vector& v1, const Vector& v2);
	Vector operator-(const Vector& v1, const Vector& v2);
	Vector operator*(const Vector& v1, const Vector& v2);
	//multiply with numbers
	Vector operator*( Vector& v, int num);
	Vector operator*(int num, Vector& v);
	//equality operator
	bool operator==(const Vector&, const Vector&);
	//inequality operator
	bool operator!=(const Vector&, const Vector&);
	//printing operator
	std::ostream& operator <<(std::ostream& os, const Vector& v);