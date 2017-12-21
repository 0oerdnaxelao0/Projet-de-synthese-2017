#pragma once
#include <math.h>
#include "Polygone.h"
#include "Visitable.h"
#include "Visiteur.h"
#include <vector>

class Vecteur2D;
class Segment;

//! Classe Triangle
/*!
	Hérite de Polygone puisqu'un Triangle est un Polygone
*/

class Triangle : public Polygone
{
public:
	//! Constructeur d'un Triangle
	/*!
		Un Triangle est construit à l'aide de :
		\param couleur Couleur du Triangle
		\param u1 Premier Vecteur2D (point) du triangle
		\param u2 Deuxième Vecteur2D (point) du triangle
		\param u3 Troisième Vecteur2D (point) du triangle
		Lorsqu'une Forme est construite, elle n'appartient pas à un groupe, elle est donc fausse par défaut.
	*/
	Triangle(int couleur, const Vecteur2D &u1, const Vecteur2D &u2, const Vecteur2D &u3);
	//! Constructeur par copie d'un Triangle
	/*!
		\param t Triangle que l'on veut copier
	*/
	Triangle(Triangle &t);
	//! Destructeur d'un Triangle
	/*!
		Destructeur Virtuel
	*/
	virtual ~Triangle();
	//! Getter Perimetre
	/*!
		\return Perimetre du polygone
	*/
	double getPerimetre() const;
	//! Getter Aire
	/*!
		L'aire d'un triangle est calculée grâce à aux determinants de 2 cotés adjacents
		Aire = det(AB/AC)/2
		\return Aire du polygone
	*/
	double getAire() const;
	string Afficher() const;
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param c Triangle affiché
		\return o Flux sortant modifié
	*/
	friend ostream& operator<<(ostream &o, const Triangle &t);
	void accepte(Visiteur*) const;
	virtual string toString() const;
};

