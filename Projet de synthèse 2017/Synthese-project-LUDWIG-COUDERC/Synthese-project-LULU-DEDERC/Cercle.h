#pragma once
#include "Vecteur2D.h"
#include "Forme.h"
#include "Visitable.h"
#include "Visiteur.h"
#include <math.h>

#define M_PI acos(-1)

//! Classe Cercle
/*!
	Hérite de Forme puisque c'est une forme
*/

class Cercle : public Forme
{
private:
	//! Centre
	/*!
		Centre du cercle
	*/
	Vecteur2D _centre;
	//! Rayon
	/*!
		Rayon du cercle
	*/
	double _rayon;
public:
	//! Constructeur d'une cercle
	/*!
		Un cercle est construit à l'aide de
		\param couleur Couleur du cercle
		\param centre Centre du cercle
		\param rayon Rayon du cercle
		Lorsqu'une forme est construite, elle n'appartient pas à un groupe, elle est donc fausse par défaut.
	*/
	Cercle(int couleur, Vecteur2D centre, double rayon);
	//! Constructeur par copie d'un cercle
	/*!
		\param c Cercle que l'on veut copier
	*/
	Cercle(Cercle &c);
	//! Destructeur d'un cercle
	/*!
		Destructeur Virtuel
	*/
	virtual ~Cercle();
	//! Getter Centre
	/*!
		Inline
		\return centre Centre du Cercle
	*/
	inline Vecteur2D getCentre() const;
	//! Getter Rayon
	/*!
		Inline
		\return rayon Rayon du Cercle
	*/
	inline double getRayon() const;
	//! Setter Centre
	/*!
		Inline
		\param centre Centre qui remplace l'ancien
	*/
	inline void setCentre(Vecteur2D p);
	//! Setter Rayon
	/*!
		Inline
		\param rayon Rayon qui remplace l'ancien
	*/
	inline void setRayon(double rayon);
	//! Getter Perimetre
	/*!
		\return Perimetre du cercle
	*/
	double getPerimetre();
	//! Getter Aire
	/*!
		\return Aire du cercle
	*/
	double getAire() const;
	string Afficher() const;
	Cercle& Translation(const Vecteur2D &v);
	Cercle& Rotation(const Vecteur2D &v, double angle);
	Cercle& Homothetie(const Vecteur2D &v, double rapport);
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param c Cercle affiché
		\return o Flux sortant modifié
	*/
	friend ostream& operator<<(ostream& o, Cercle &c);
	void accepte(Visiteur*) const;
	string toString() const;
};

Vecteur2D Cercle::getCentre() const
{
	return _centre;
}

double Cercle::getRayon() const
{
	return _rayon;
}

void Cercle::setCentre(Vecteur2D v)
{
	_centre = v;
}

void Cercle::setRayon(double rayon)
{
	_rayon = rayon;
}