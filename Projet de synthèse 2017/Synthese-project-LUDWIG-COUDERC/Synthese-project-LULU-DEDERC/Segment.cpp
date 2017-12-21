#pragma once
#include "Vecteur2D.h"
#include "Segment.h"
#include <math.h>

Segment::Segment(int couleur, Vecteur2D x, Vecteur2D y) :Forme(couleur), debut(x), fin(y)
{
	if (x == y)
		throw ("Vecteur2Ds égaux donc pas de segment");
}

Segment::Segment(const Segment & s) :Forme(s), debut(s.debut), fin(s.fin)
{
}

Segment::~Segment()
{
}

double Segment::getLongueur() const
{
	double res = sqrt(pow((fin.getX() - debut.getX()), 2) + (pow((fin.getY() - debut.getY()), 2)));
	return res;
}

string Segment::Afficher() const
{
	return Forme::Afficher() + "\nSegment : \nX: " + debut.Afficher() + "\nY: " + fin.Afficher() + "\nLongueur : " + to_string(getLongueur());
}

Segment& Segment::Translation(const Vecteur2D & v)
{
	debut.Translation(v);
	fin.Translation(v);
	return *this;
}

Segment& Segment::Rotation(const Vecteur2D & v, double angle)
{
	debut.Rotation(v, angle);
	fin.Rotation(v, angle);
	return *this;
}

Segment& Segment::Homothetie(const Vecteur2D & v, double rapport)
{
	debut.Homothetie(v, rapport);
	fin.Homothetie(v, rapport);
	return *this;
}

double Segment::getAire() const
{
	return 0.0;
}

void Segment::accepte(Visiteur *v) const
{
	v->visite(this);
}

string Segment::toString() const
{
	return "Segment;" + getCouleur() + ';' + debut.toString() + fin.toString();
}

ostream & operator<<(ostream & o, const Segment & s)
{
	o << s.Afficher();
	return o;
}
