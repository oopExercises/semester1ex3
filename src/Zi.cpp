#include "Zi.h"
#include <ostream>
#include <cmath>

Zi::Zi(int real, int imag) : m_real(real), m_imag(imag) { }

int Zi::real() const
{
	return m_real;
}

int Zi::imag() const
{
	return m_imag;
}

int Zi::norm() const
{
	return ((m_real * m_real) + (m_imag * m_imag));
}

Zi Zi::conj() const
{
	return Zi(m_real, -(m_imag));
}
bool Zi::dividedBy(const Zi& divisor) const
{
	Zi afterDivide = Zi(m_real, m_imag) / divisor;
	if (divisor * afterDivide == Zi(m_real, m_imag))
		return true;
	return false;
}

Zi& Zi::operator+=(const Zi& z)
{
	m_real += z.m_real;
	m_imag += z.m_imag;
	return*this;
}

Zi& Zi::operator-=(const Zi& z)
{
	m_real -= z.m_real;
	m_imag -= z.m_imag;
	return*this;
}

Zi& Zi::operator*=(const Zi& multiple)
{
	Zi num = Zi(m_real, m_imag);
	num = num * multiple;

	m_real = num.m_real;
	m_imag = num.m_imag;

	return *this;
}

Zi& Zi::operator/=(const Zi& down)
{
	Zi up = Zi(m_real, m_imag);
	up = up / down;

	m_real = up.m_real;
	m_imag = up.m_imag;

	return *this;

}

Zi& Zi::operator%=(const Zi& down)
{
	Zi up = Zi(m_real, m_imag);
	up = up % down;

	m_real = up.m_real;
	m_imag = up.m_imag;

	return *this;
}


Zi operator+(const Zi& z1, const Zi& z2)
{
	return Zi(z1.real() + z2.real(), z1.imag() + z2.imag());
}

Zi operator-(const Zi& z1, const Zi& z2)
{
	return Zi(z1.real() - z2.real(), z1.imag() - z2.imag());
}

Zi operator*(const Zi& z1, const Zi& z2)
{
	int real = z1.real() * z2.real() - z1.imag() * z2.imag();
	int imag = z1.real() * z2.imag() + z1.imag() * z2.real();

	return Zi(real, imag);
}

Zi operator/(const Zi& up, const Zi& down)
{
	Zi mul = up * down.conj();
	int norma = down.norm();

	int new_real = std::round(((double)mul.real()) / norma);
	int new_imag = std::round(((double)mul.imag()) / norma);

	return Zi(new_real, new_imag);
}

Zi operator%(const Zi& up, const Zi& down)
{
	Zi afterDivide = up / down;
	Zi mul = afterDivide * down;

	return up - mul;
}


Zi operator-(const Zi& z1)
{
	return Zi(-z1.real(), -z1.imag());
}

bool operator==(const Zi& z1, const Zi& z2)
{
	return(z1.real() == z2.real() && z1.imag() == z2.imag());
}

bool operator!=(const Zi& z1, const Zi& z2)
{
	return !(z1 == z2);
}

std::ostream& operator<<(std::ostream& os, const Zi& z)
{
	if (z.imag() >= 0)
		os << z.real() << "+" << z.imag() << "i";

	else
		os << z.real() << z.imag() << "i";

	return os;
}

