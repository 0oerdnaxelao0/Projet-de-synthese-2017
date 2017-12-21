#pragma once
#include"Visiteur.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//! Classe SauvegardeVisiteur
/*!
Hérite de Visiteur <br />
Gère la sauvegarde dans un fichier texte des differents types de Forme (s)
*/
class SauvegardeVisiteur : public Visiteur
{
private:

public:
	//! Constructeur d'un SauvegardeVisiteur
	SauvegardeVisiteur();
	void visite(const Cercle * circle);
	void visite(const Polygone *q);
	void visite(const Segment *s);
	void visite(const FormeComposee* fc);
	void visite(const Triangle* t);
	void visite(const Vecteur2D* v);
};

