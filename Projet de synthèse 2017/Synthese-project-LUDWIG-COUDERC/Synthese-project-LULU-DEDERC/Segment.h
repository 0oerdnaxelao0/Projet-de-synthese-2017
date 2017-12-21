#pragma once
#include <math.h>
#include "Vecteur2D.h"
#include "Forme.h"

//! Classe Segment
/*!
	Hérite de Forme puisque c'est une forme
*/

class Segment :public Forme
{
private:
	//! X
	/*!
		Premier Vecteur2D du segment
	*/
	Vecteur2D debut;
	//! Y
	/*!
		Second Vecteur2D du segment
	*/
	Vecteur2D fin;
	//! Setter X
	/*!
		Inline
		\param x X qui remplace l'ancien
	*/
	inline void setX(Vecteur2D x);
	//! Setter Y
	/*!
		Inline
		\param y Y qui remplace l'ancien
	*/
	inline void setY(Vecteur2D y);
public:
	//! Constructeur d'un Segment
	/*!
		\param couleur Couleur du Segment
		\param x Premier Vecteur2D du segment
		\param y Second Vecteur2D du segment
	*/
	Segment(int couleur, const Vecteur2D x, const Vecteur2D y);
	//! Constructeur par copie d'un segment
	/*!
		\param s Segment que l'on veut copier
	*/
	Segment(const Segment &s);
	//! Destructeur d'un segment
	/*!
		Destructeur Virtuel
	*/
	virtual ~Segment();
	//! Getter X
	/*!
		Inline
		\return Premier Vecteur2D du segment
	*/
	inline Vecteur2D getX() const;
	//! Getter Y
	/*!
		Inline
		\return Second Vecteur2D du segment
	*/
	inline Vecteur2D getY() const;
	//! getter longueur
	/*!
		\return Longueur du segment
	*/
	double getLongueur() const;
	virtual string Afficher() const;
	virtual Segment& Translation(const Vecteur2D &v);
	virtual Segment& Rotation(const Vecteur2D &v, double angle);
	virtual Segment& Homothetie(const Vecteur2D &v, double rapport);
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param c Segment affiché
		\return o Flux sortant modifié
	*/
	double getAire() const;
	friend ostream& operator<<(ostream& o, const Segment &s);
	void accepte(Visiteur*) const;
	virtual string toString() const;
};

void Segment::setX(Vecteur2D x)
{
	debut = x;
}

void Segment::setY(Vecteur2D y)
{
	fin = y;
}

Vecteur2D Segment::getX() const
{
	return debut;
}

Vecteur2D Segment::getY() const
{
	return fin;
}
