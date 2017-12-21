#pragma once
#include "Vecteur2D.h"
#include "Segment.h"
#include <math.h>

#define M_PI acos(-1)


const Vecteur2D operator *(const double & a, const Vecteur2D & u)
{
	return u*a;
}

Vecteur2D::Vecteur2D(const double & x, const double & y) : _x(x), _y(y)
{
}

Vecteur2D::Vecteur2D(const char * s)
{
	sscanf(s, "(%lf; %lf)", &_x, &_y);
}

Vecteur2D::~Vecteur2D()
{
}

bool Vecteur2D::operator==(const Vecteur2D &u) const
{
	return _x == u._x && _y == u._y;
}

Vecteur2D Vecteur2D::operator=(const Vecteur2D &u)
{
	if (this != &u)
	{
		_x = u._x;
		_y = u._y;
	}
	return *this;
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(_x + u._x, _y + u._y);
}

Vecteur2D & Vecteur2D::operator+=(const Vecteur2D & u)
{
	_x += u._x;
	_y += u._y;
	return *this;
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(_x*a, _y*a);
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x, -_y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D & u)
{
	return Vecteur2D(_x - u._x, _y - u._y);
}

string Vecteur2D::Afficher() const
{
	return "(x: " + to_string(_x) + ", y : " + to_string(_y) + ")\n";
}

Vecteur2D& Vecteur2D::Translation(const Vecteur2D &v)
{
	*this += v;
	return *this;
}

/*Vecteur2D& Vecteur2D::Rotation(const Vecteur2D &v, double angle)
{
	angle *= M_PI / 180;
	_x = v._x + _x * cos(angle) - v._y * sin(angle);
	_y = v._x + _x * sin(angle) + v._y * cos(angle);
	return *this;
}*/

Vecteur2D& Vecteur2D::Rotation(const Vecteur2D &center, double angle) {

	angle *= M_PI / 180;
	double dirP1 = atan2(center.getY() - _y, center.getX() - _x);
	double dirP2 = dirP1 + angle;
	double dist = Segment(0, *this, center).getLongueur();   //  suspect ???????????????????????????????????
	_x = center._x + dist*cos(dirP2);
	_y = center._y + dist*sin(dirP2);
	return *this;
}

Vecteur2D& Vecteur2D::Homothetie(const Vecteur2D &v, double rapport)
{
	_x = (_x - v._x)*rapport + v._x;
	_y = (_y - v._y)*rapport + v._y;
	return *this;
}

void Vecteur2D::accepte(Visiteur *v) const
{
	v->visite(this);
}

string Vecteur2D::toString() const
{
	return to_string(getX()) + ";" + to_string(getY()) + ";";
}

ostream& operator<<(ostream & o, const Vecteur2D & v)
{
	o << v.Afficher();
	return o;
}
