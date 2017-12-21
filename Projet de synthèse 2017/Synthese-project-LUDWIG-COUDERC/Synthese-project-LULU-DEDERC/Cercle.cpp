#pragma once
#include "Cercle.h"
#include "Vecteur2D.h"
#include <math.h>

Cercle::Cercle(int couleur, Vecteur2D centre, double rayon):Forme(couleur), _centre(centre)
{
	if (rayon == 0.0)
		throw ("Rayon du cercle nul !");
	else if (rayon < 0.0)
		throw("Rayon du cercle négatif");
	_rayon = rayon;
}

Cercle::Cercle(Cercle & c):Forme(c),_centre(c._centre)
{
	_rayon = c._rayon;
}

Cercle::~Cercle()
{
}

double Cercle::getPerimetre()
{
	return 2 * M_PI *_rayon;
}

double Cercle::getAire() const
{
	return pow(_rayon, 2) * M_PI;
}

string Cercle::Afficher() const
{
	return Forme::Afficher() + "\nCercle :\nCentre : " + _centre.Afficher() + "\nRayon : " + to_string(_rayon);
}

Cercle& Cercle::Translation(const Vecteur2D &v)
{
	_centre.Translation(v);
	return *this;
}

Cercle& Cercle::Rotation(const Vecteur2D &v, double angle)
{
	_centre.Rotation(v, angle);
	return *this;
}

Cercle& Cercle::Homothetie(const Vecteur2D &v, double rapport)
{
	_centre.Homothetie(v, rapport);
	_rayon *= rapport;
	return *this;
}

void Cercle::accepte(Visiteur * v) const
{
	v->visite(this);
}

string Cercle::toString() const
{
	return "Cercle;" + to_string(getCouleur()) + ';' + _centre.toString() + to_string(_rayon) + ";";
}

ostream & operator<<(ostream & o, Cercle & c)
{
	o << c.Afficher();
	return o;
}
