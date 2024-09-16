#pragma once
#include "Zi.h"

class Array
{
private:
	int m_size;
	Zi* m_ptr;

public:
	//constructors
	explicit Array(int size = 0, const Zi& value = Zi());
	Array(const Zi arr[], int size);
	Array(const Array&);  // copy constructor

	//destructor
	~Array();

	//returning functions
	int size()const;
	bool empty()const;

	//access operators
	Zi& operator[](int);
	Zi operator[](int) const;

	//plus equal operator
	Array operator+=(const Array& v1);

	Array& operator=(const Array&);


};
//global operators

// equality operator
bool operator==(const Array&, const Array&);

// inequality operator; 
bool operator!=(const Array&, const Array&);

//plus operator
Array operator+(const Array& first, const Array& second);