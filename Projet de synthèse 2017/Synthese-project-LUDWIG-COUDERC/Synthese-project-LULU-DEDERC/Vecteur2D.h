#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include "Visitable.h"
#include "Visiteur.h"

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

//! Classe Vecteur2D
/*!
	Remplace les points dans ce programme
*/

class Vecteur2D
{
private:
	//! X
	/*!
		Abscisse du Vecteur2D
	*/
	double _x;
	//! Y
	/*!
		Ordonnée du Vecteur2D
	*/
	double _y;
public:
	//! Constructeur d'un Vecteur2D
	/*!
		\param x Abscisse du Vecteur2D
		\param y Ordonnée du Vecteur2D
		Par défaut, un Vecteur2D est initialisé à l'origine
	*/
	Vecteur2D(const double & x = 0, const double & y = 0);
	//! Autre Constructeur d'un Vecteur2D
	/*!
		\param s Coordonnées dans une chaine de caractères de la forme "(X; Y)"
	*/
	Vecteur2D(const char * s);
	// Destructeur d'un Vecteur2D
	/*!
		Destructeur virtuel
	*/
	virtual ~Vecteur2D();
	//! Getter X
	/*!
		\return X
		Inline
	*/
	inline double getX() const;
	//! Getter Y
	/*!
		\return Y
		Inline
	*/
	inline double getY() const;
	//! Setter X
	/*!
		\param x Nouvelle abscisse du Vetceur2D
		Inline
	*/
	inline void setX(double x);
	//! Setter Y
	/*!
		\param y Nouvelle ordonnée du Vetceur2D
		Inline
	*/
	inline void setY(double y);
	//! Surcharge operateur ==
	/*!
		\param u Vecteur2D a comparer
		\return vrai si this = u, faux sinon
	*/
	bool operator==(const Vecteur2D &u) const;
	//! Surcharge operateur =
	/*!
		Affectation de
		\param u
		a this
		\return this
	*/
	Vecteur2D operator=(const Vecteur2D &u);
	//! Surcharge operateur +
	/*!
		\param u
		\return u + this
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;
	//! Surcharge operateur +=
	/*!
		\param u
		\return this += u
	*/
	Vecteur2D& operator+= (const Vecteur2D &u);
	//! Surcharge operateur *
	/*!
		\param a
		\return this * a
	*/
	const Vecteur2D operator * (const double & a) const;
	//! Surcharge operateur - unaire
	/*
		\return -this
	*/
	const Vecteur2D operator - () const;
	//! Surcharge operateur - binaire
	/*
		\return this - u
	*/
	const Vecteur2D operator -(const Vecteur2D &u);
	//! Affichage d'un Vecteur2D
	/*!
		Fonction d'affichage d'un Vecteur2D pour la console (cout)
		\return string Chaine affichée par <<
	*/
	string Afficher() const;
	//! Translation d'un Vecteur2D
	/*!
		Effectue la translation d'un Vecteur2D à partir de
		\param Vecteur2D v Vecteur de translation
		\return *this Vecteur2D transformé
	*/
	Vecteur2D& Translation(const Vecteur2D &v);
	//! Rotation d'un Vecteur2D
	/*!
		Effectue la translation d'un Vecteur2D à partir de
		\param Vecteur2D v Vecteur de translation
		\return *this Vecteur2D transformé
	*/
	Vecteur2D& Rotation(const Vecteur2D &center, double angle);
	//! Homothetie d'un Vecteur2D
	/*!
		Effectue la translation d'un Vecteur2D à partir de
		\param Vecteur2D v Vecteur de translation
		\return *this Vecteur2D transformé
	*/
	Vecteur2D& Homothetie(const Vecteur2D &v, double rapport);
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param f Vecteur2D affiché
		\return o Flux sortant modifié
	*/
	friend ostream& operator<<(ostream &o, const Vecteur2D &v);
	//! toString
	/*!
		Fonction utilisée pour :
		- l'envoi de requete au serveur de dessin
		- la sauvegarde dans un fichier texte
		\return string Vecteur2D
	*/
	virtual string toString() const;
	void accepte(Visiteur*) const;
};

double Vecteur2D::getX() const
{
	return _x;
}

double Vecteur2D::getY() const
{
	return _y;
}

void Vecteur2D::setX(double x)
{
	_x = x;
}

void Vecteur2D::setY(double y)
{
	_y = y;
}

