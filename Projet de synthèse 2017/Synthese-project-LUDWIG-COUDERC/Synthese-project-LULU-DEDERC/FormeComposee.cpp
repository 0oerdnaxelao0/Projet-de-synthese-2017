#pragma once
#include "FormeComposee.h"
#include "Vecteur2D.h"

FormeComposee::FormeComposee(int couleur):Forme(couleur)
{
}

FormeComposee::FormeComposee(FormeComposee & f):Forme(f)
{
}

FormeComposee::~FormeComposee()
{
	//for (int i = 0; i < _nb - 1; i++)
		//delete &_tabFormes[i];
}

/*FormeComposee FormeComposee::operator=(const FormeComposee & f)
{
	_tabFormes = f._tabFormes;
	return *this;
}*/

FormeComposee& FormeComposee::operator+=(Forme &f)
{
	_tabFormes.push_back(&f);
	if (f.estDansGroupe())
		throw new exception;
	toggleGroupe();
	return *this;
}

FormeComposee FormeComposee::operator+(Forme &f)
{
	FormeComposee res = FormeComposee(*this);
	res += f;
	return res;
}

Forme* FormeComposee::operator[](int index) const
{
	return _tabFormes[index];
}

FormeComposee & FormeComposee::Translation(const Vecteur2D & v)
{
	for (int i = 0; i < _tabFormes.size(); i++)
	{
		_tabFormes[i]->Translation(v);
	}
	return *this;
}

FormeComposee & FormeComposee::Rotation(const Vecteur2D & v, double angle)
{
	for (int i = 0; i < _tabFormes.size(); i++)
	{
		_tabFormes[i]->Rotation(v, angle);
	}
	return *this;
}

FormeComposee & FormeComposee::Homothetie(const Vecteur2D & v, double rapport)
{
	for (int i = 0; i < _tabFormes.size(); i++)
	{
		_tabFormes[i]->Homothetie(v, rapport);
	}
	return *this;
}

string FormeComposee::Afficher() const
{
	string res = "Forme Composee :\n";
	for (int i = 0; i < _tabFormes.size(); i++)
	{
		res += "----------\n" + _tabFormes[i]->Afficher() + "\n";
	}
	res += "\nAire : " + to_string(getAire()) + "\n";
	return res;
}

double FormeComposee::getAire() const
{
	double res = 0;
	for (unsigned int i = 0; i < _tabFormes.size(); i++)
	{
		res += _tabFormes[i]->getAire();
	}
	return res;
}

void FormeComposee::accepte(Visiteur * v) const
{
	v->visite(this);
}


string FormeComposee::toString() const
{
	string res = "FormeComposee|" + to_string(getCouleur());
	for (int i = 0; i < _tabFormes.size(); i++)
	{
		res += "|" + _tabFormes[i]->toString();
	}
	return res;
}

ostream & operator<<(ostream & o, const FormeComposee & f)
{
	o << f.Afficher();
	return o;
}
