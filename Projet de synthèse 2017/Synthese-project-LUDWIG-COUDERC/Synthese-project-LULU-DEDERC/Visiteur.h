#pragma once

class Forme;
class FormeComposee;
class Vecteur2D;
class Cercle;
class Triangle;
class Segment;
class Polygone;

//! Classe Visiteur
/*!
	Classe abstraite
	Visiteur pour :
	- Envoyer les requetes de dessin
	- Sauvegarde des formes dans un fichier texte
*/

class Visiteur {
public:
	//! Fonction visite
	/*!
		\param Cercle
	*/
	virtual void visite(const Cercle*) = 0;
	//! Fonction visite
	/*!
		\param Triangle
	*/
	virtual void visite(const Triangle*) = 0;
	//! Fonction visite
	/*!
		\param Polygone
	*/
	virtual void visite(const Polygone*) = 0;
	//! Fonction visite
	/*!
		\param Vecteur2D
		Inutile mais nécessaire pour l'héritage
	*/
	virtual void visite(const Vecteur2D*) = 0;
	//! Fonction visite
	/*!
		\param Segment
	*/
	virtual void visite(const Segment*) = 0;
	//! Fonction visite
	/*!
		\param FormeComposee
	*/
	virtual void visite(const FormeComposee*) = 0;
};