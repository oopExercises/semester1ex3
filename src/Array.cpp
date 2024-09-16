#include "Array.h"

Array::Array(int size, const Zi& value) : m_size(size)
{
	m_ptr = new Zi[m_size]; // create space for array

	for (int i = 0; i < m_size; i++)
	{
		m_ptr[i] = value; // copy into object
	}

}

Array::Array(const Zi arr[], int size) : m_size(size)
{
	m_ptr = new Zi[m_size]; // create space for array

	for (int i = 0; i < m_size; i++)
	{
		m_ptr[i] = arr[i]; // copy into object
	}
}

Array::Array(const Array& arrayToCopy) : m_size(arrayToCopy.m_size)
{
	m_ptr = new Zi[m_size]; // create space for array

	for (int i = 0; i < m_size; i++)
	{
		m_ptr[i] = arrayToCopy.m_ptr[i]; // copy into object
	}

}

Array::~Array()
{
	delete[] m_ptr; //delete the space that was created
}

int Array::size() const
{
	return m_size;
}

bool Array::empty() const
{
	return (m_size == 0);
}

Zi& Array::operator[](int index)
{
	return m_ptr[index]; // reference return
}

Zi Array::operator[](int index) const
{
	return m_ptr[index]; // reference return
}

Array& Array::operator=(const Array& second)
{

	if (&second != this) {

		if (m_size != second.m_size) {
			m_size = second.m_size;
			Zi* tmp = new Zi[m_size];
			delete[] m_ptr;
			m_ptr = tmp;
		} 

		for (int i = 0; i < m_size; i++)
			m_ptr[i] = second.m_ptr[i];  // copy array into object

	}
	return *this;
}

Array Array::operator+=(const Array& v1)
{
	*this = *this + v1;
	return *this;
}

bool operator==(const Array& first, const Array& second)
{
	if (first.size() != second.size())
		return false;    // arrays of different sizes

	for (int i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i])
			return false; // arrays are not equal
	}

	return true;        // arrays are equal
}

bool operator!=(const Array& first, const Array& second)
{
	return !(first == second);
}

Array operator+(const Array& first, const Array& second)
{
	int max_size = std::max(first.size(), second.size());
	Array sum(max_size, 0);

	//if the arrays are not the same size
	if (first.size() != second.size())
	{
		if (first.size() > second.size()) {

			for (int i = 0; i < second.size(); i++) {
				sum[i] = first[i] + second[i];
			}

			for (int i = second.size(); i < first.size(); i++) {
				sum[i] = first[i];
			}
		}

		else {

			
			for (int i = 0; i < first.size(); i++) {
				sum[i] = first[i] + second[i];
			}

			for (int i = first.size(); i < second.size(); i++) {
				sum[i] = second[i];
			}
		}
		return sum;
	}

	//if the arrays are the same size
	for (int i = 0; i < max_size; i++)
	{
		sum[i] = first[i] + second[i];
	}

	return sum;
}