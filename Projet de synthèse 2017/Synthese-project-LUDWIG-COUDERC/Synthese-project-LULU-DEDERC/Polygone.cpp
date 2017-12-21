#pragma once
#include "Vecteur2D.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Segment.h"

Polygone::Polygone(int couleur):Forme(couleur)
{
	_nbCotes = 0;
}

Polygone::Polygone(Polygone & g):Forme(g)
{
	_nbCotes = g._nbCotes;
	_tabPts = g._tabPts;
	_tabCotes = g._tabCotes;
}

Polygone::~Polygone()
{
}

void Polygone::ConstruirePolygone()
{
	if (_tabPts.size() < 2)
		throw new exception;
	if (_nbCotes != 0)
	{
		_tabCotes.clear();
		_nbCotes = 0;
	}
	if(_nbCotes == 0)
	{
		for (int i = 1; i < _tabPts.size(); i++)
		{
			_tabCotes.push_back(Segment(getCouleur(), _tabPts[i - 1], _tabPts[i]));
			_nbCotes++;
		}
		_tabCotes.push_back(Segment(getCouleur(), _tabPts[_tabPts.size() - 1], _tabPts[0]));
		_nbCotes++;
	}
}

Polygone Polygone::operator=(const Polygone & p)
{
	_tabPts = p._tabPts;
	_tabCotes = p._tabCotes;
	_nbCotes = p._nbCotes;
	this->ConstruirePolygone();
	return *this;
}

Polygone& Polygone::operator+=(const Vecteur2D &v)
{
	_tabPts.push_back(v);
	return *this;
}

Polygone Polygone::operator+(const Vecteur2D & v)
{
	Polygone res = Polygone(*this);
	res += v;
	return res;
}

void Polygone::addPoint(const Vecteur2D & v)
{
	_tabPts.push_back(v);
}

void Polygone::addSegment(const Segment & s)
{
	_tabCotes.push_back(s);
}

double Polygone::getPerimetre() const
{
	double res = 0.0;
	for (int i = 0; i < _nbCotes; i++)
	{
		res += _tabCotes[i].getLongueur();
	}
	return res;
}

double Polygone::getAire() const
{
	double res = 0.0;
	for (int i = 2; i < _nbCotes; i++)
	{
		res +=(Triangle(getCouleur(), _tabPts[0], _tabPts[i - 1], _tabPts[i])).getAire();
	}
	return res;
}

Polygone& Polygone::Translation(const Vecteur2D & v)
{
	if (_tabPts.size() == 0)
		throw new exception;
	else
		for (int i = 0; i < _tabPts.size(); i++)
		{
			_tabPts[i].Translation(v);
		}
	ConstruirePolygone();
	return *this;
}

Polygone& Polygone::Rotation(const Vecteur2D & v, double angle)
{
	if (_tabPts.size() == 0)
		throw new exception;
	else
		for (int i = 0; i < _tabPts.size(); i++)
		{
			_tabPts[i].Rotation(v, angle);
		}
	ConstruirePolygone();
	return *this;
}

Polygone& Polygone::Homothetie(const Vecteur2D & v, double rapport)
{
	if (_tabPts.size() == 0)
		throw new exception;
	else
		for (int i = 0; i < _tabPts.size(); i++)
		{
			_tabPts[i].Homothetie(v, rapport);
		}
	ConstruirePolygone();
	return *this;
}

string Polygone::Afficher() const
{
	string res = Forme::Afficher() + "\n";
	for (int i = 0; i < _tabPts.size(); i++)
	{
		res += "Point " + to_string(i) + ' ' + _tabPts[i].Afficher() + "\n";
	}
	for (int i = 0; i < _nbCotes; i++)
	{
		if (&_tabPts[i] == NULL)
			throw new exception;
		res += "Segment " + to_string(i) + ' ' + _tabCotes[i].Afficher() + "\n";
	}
	res += "Perimetre : " + to_string(getPerimetre()) + "\nAire : " + to_string(getAire());
	return res;
}

void Polygone::accepte(Visiteur * v) const
{
	v->visite(this);
}
string Polygone::toString() const
{
	string res = "Polygone;" + to_string(getCouleur()) + ';';
	for (int i = 0; i < _tabPts.size(); i++)
	{
		res += getPoint(i).toString();
	}
	return res;
}

ostream & operator<<(ostream & o, const Polygone & p)
{
	o << p.Afficher();
	return o;
}
