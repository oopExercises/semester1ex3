#include "Vector.h"
#include <new>       
#include <cstdlib> 

Vector::Vector(int size, const Zi& init) : m_ziArray(Array(size, init)) { }

Vector::Vector(const Zi arr[], int size) : m_ziArray(Array(arr, size)) { }

int Vector::size() const
{
	return m_ziArray.size();
}

Array Vector::getArray() const
{
	return m_ziArray;
}

Vector& Vector::operator+=(const Vector& v)
{
	m_ziArray += v.getArray();
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	int size;
	Vector vector;

	//to check if the arrays are not the same size and which array is longer
	if (m_ziArray.size() >= v.size())
	{
		size = v.size();
		vector = Vector(m_ziArray.size(), 0);
	}
	else
	{
		size = m_ziArray.size();
		vector = Vector(v.size(), 0);
	}
	//substract the values until the size of the small array
	for (int i = 0; i < size; i++)
	{
		vector.m_ziArray[i] = m_ziArray[i] - v.m_ziArray[i];
	}
	//to substract the other numbers in the long array
	if (size == m_ziArray.size())
	{
		for (int i = size; i < v.size(); i++)
		{
			vector.m_ziArray[i] = -v.m_ziArray[i];
		}
	}
	else
	{
		for (int i = size; i < m_ziArray.size(); i++)
		{
			vector.m_ziArray[i] = m_ziArray[i];
		}
	}
	m_ziArray = vector.m_ziArray;
	return *this;
}

Vector& Vector::operator*=(const Vector& multiple)
{
	int size;
	Vector vector;

	//to check if the arrays are not the same size and which array is longer
	if (m_ziArray.size() >= multiple.size())
	{
		size = multiple.size();
		vector = Vector(m_ziArray.size(), 0);
	}
	else
	{
		size = m_ziArray.size();
		vector = Vector(multiple.size(), 0);
	}
	//multiply the values until the size of the small array
	for (int i = 0; i < size; i++)
	{
		vector.m_ziArray[i] = m_ziArray[i] * multiple.m_ziArray[i];
	}
	//to multiply the other numbers in the long array with 0 so we get 0
	if (size == m_ziArray.size())
	{
		for (int i = size; i < multiple.size(); i++)
		{
			vector.m_ziArray[i] = Zi(0, 0);
		}
	}
	else
	{
		for (int i = size; i < m_ziArray.size(); i++)
		{
			vector.m_ziArray[i] = Zi(0, 0);
		}
	}
	m_ziArray = vector.m_ziArray;
	return *this;
}

Vector& Vector::operator*=(int num)
{
	for (int i = 0; i < m_ziArray.size(); i++)
	{
		m_ziArray[i] = Zi(num * m_ziArray[i].real(), num * m_ziArray[i].imag());
	}
	return *this;

}

Zi& Vector::operator[](int index)
{	// check if the index is out of range 
	if (index < 0 || index >= m_ziArray.size())
	{
		std::cout << "\nError: index " << index
			<< " out of range" << std::endl;
		exit(1);  
	} 

	return m_ziArray[index];
}

Zi Vector::operator[](int index) const
{
	// check if the index is out of range 
	if (index < 0 || index >= m_ziArray.size())
	{
		std::cout << "\nError: index " << index
			<< " out of range" << std::endl;
		exit(1);
	}

	return m_ziArray[index];
}

Vector operator-(const Vector& v)
{
	Vector vector(v.size(), 0);

	vector -= v;

	return vector;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	Vector v3(v1);
	v3 += v2;
	return v3;
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	Vector v3(v1);
	v3 -= v2;
	return v3;
}

Vector operator*(const Vector& v1, const Vector& v2)
{
	Vector v3(v1);
	v3 *= v2;
	return v3;
}

Vector operator*( Vector& v, int num)
{
	Vector v3(v);
	v3 *= num;
	return v3;
}

Vector operator*(int num, Vector& v)
{
	Vector v3(v);
	v3 *= num;
	return v3;
}

bool operator==(const Vector& v1, const Vector& v2)
{
	return (v1.getArray() == v2.getArray());
}

bool operator!=(const Vector& v1, const Vector& v2)
{
	return !(v1 == v2);
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		os << v[i] << " ";
	}
	return os;
}
