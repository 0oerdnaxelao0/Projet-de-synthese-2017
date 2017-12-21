#pragma once
#include "Triangle.h"
#include "Segment.h"

Triangle::Triangle(int couleur, const Vecteur2D &u1, const Vecteur2D &u2, const Vecteur2D &u3):Polygone(couleur)
{
	addPoint(u1);
	addPoint(u2);
	addPoint(u3);
	addSegment(Segment(1, u1, u2));
	addSegment(Segment(1, u2, u3));
	addSegment(Segment(1, u3, u1));
}

Triangle::Triangle(Triangle & t):Polygone(t)
{
	setTabPts(t.getTabPts());
	setTabCotes(t.getTabCotes());
}

Triangle::~Triangle()
{
}

double Triangle::getPerimetre() const
{
	double res = 0.0;
	for (int i = 0; i < 3; i++)
	{
		res += getCote(i).getLongueur();
	}
	return res;
}

double Triangle::getAire() const
{
	double 
		x1 = getPoint(1).getX() - getPoint(0).getX(),
		y1 = getPoint(1).getY() - getPoint(0).getY(),

		x2 = getPoint(2).getX() - getPoint(1).getX(),
		y2 = getPoint(2).getY() - getPoint(1).getY();

	return abs(x1 * y2 - y1 * x2)/2;
}

string Triangle::Afficher() const
{
	return Forme::Afficher()
		+ "\nA: " + getPoint(0).Afficher()
		+ "\nB: " + getPoint(1).Afficher()
		+ "\nC: " + getPoint(2).Afficher()
		+ "\nAB: " + getCote(0).Afficher()
		+ "\nBC: " + getCote(1).Afficher()
		+ "\nCA (aka AC): " + getCote(2).Afficher()
		+ "\nPerimetre : " + to_string(getPerimetre())
		+ "\nAire : " + to_string(getAire());
	
}

void Triangle::accepte(Visiteur * v) const
{
	v->visite(this);
}

ostream & operator<<(ostream & o, const Triangle & t)
{
	o << t.Afficher();
	return o;
}

string Triangle::toString() const
{
	string res = "Triangle;" + to_string(getCouleur()) + ";";
	for (int i = 0; i < getTabPts().size(); i++)
	{
		res += getPoint(i).toString();
	}
	return res;
}
