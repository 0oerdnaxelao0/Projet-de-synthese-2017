#pragma once
#include "Forme.h"
#include "Visiteur.h"
#include "Visitable.h"

Forme::Forme(int couleur)
{
	_couleur = couleur;
	_groupe = false;
}

Forme::Forme(const Forme & f)
{
	_couleur = f._couleur;
	_groupe = f._groupe;
}

Forme::~Forme()
{
}

string Forme::Afficher() const
{
	return "Couleur : " + to_string(_couleur) + " Groupe : " + to_string(_groupe) + "\n";
}

ostream & operator<<(ostream & o, const Forme & f)
{
	o << f.Afficher();
	return o;
}
