#pragma once
#include "Forme.h"
#include "Visitable.h"
#include "Visiteur.h"
#include "Vecteur2D.h"
#include "Segment.h"
#include <vector>

class Segment;

//! Classe Polygone
/*!
	Hérite de Forme puisque c'est une forme
*/

class Polygone : public Forme
{
private:
	//! Tableau de points
	/*!
		Vector de Vecteur2D contenant tous les points du polygone
	*/
	vector<Vecteur2D> _tabPts;
	//! Tableau de cotes
	/*!
		Vector de Segment contenant tous les segments du polygone
		Utile pour le calcul d'aire
	*/
	vector<Segment> _tabCotes;
	//! Nombre de cotes
	int _nbCotes;
	//! Setter Nombre de cotes
	/*!
		\param nbCotes nouveau nombre de cotes
	*/
	inline void setNbCotes(int nbCotes);
public:
	//! Constructeur d'un Polygone
	/*!
		Un Polygone est construit à l'aide de sa couleur.
		Lorsqu'une Forme est construite, elle n'appartient pas à un groupe, elle est donc fausse par défaut.
		\param couleur Couleur du Polygone
	*/
	Polygone(int couleur);
	//! Constructeur par copie d'un Polygone
	/*!
		\param p Polygone que l'on veut copier
	*/
	Polygone(Polygone &g);
	//! Destructeur d'un Polygone
	/*!
		Destructeur Virtuel
	*/
	~Polygone();
	//! Fonction ConstruirePolygone
	/*!
		Met a jour le tableau des segments dans :
		\sa - operator=()
		\sa - Translation()
		\sa - Rotation()
		\sa - Homothetie()
	*/
	void ConstruirePolygone();
	//! Getter Nombre de cotes
	/*!
		Inline
		\return Nombre de cotes
	*/
	virtual inline int getNbCotes() const;
	//! Getter Tableau de points
	/*!
		Inline
		\return Tableau de points
	*/
	virtual inline vector<Vecteur2D> getTabPts() const;
	//! Getter Tableau de cotes
	/*!
		Inline
		\return Tableau de cotes
	*/
	virtual inline vector<Segment> getTabCotes() const;
	//! Setter Tableau de points
	/*!
		Inline
		\param tab nouveau tableau de points
	*/
	virtual inline void setTabPts(vector<Vecteur2D> tab);
	//! Setter Tableau de cotes
	/*!
		Inline
		\param tab nouveau tableau de cotes
	*/
	virtual inline void setTabCotes(vector<Segment> tab);
	//! Getter Point du polygone
	/*!
		Inline
		\param index Emplacement du point dans le tableau de points
		\return Vecteur2D
	*/
	virtual inline Vecteur2D getPoint(int index) const;
	//! Getter Cote du polygone
	/*!
		Inline
		\param index Emplacement du coté dans le tableau de points
		\return Vecteur2D
	*/
	virtual inline Segment getCote(int index) const;
	//! Surcharge operateur =
	/*!
		Affectation de
		\param p
		à this
		\return this
	*/
	Polygone operator= (const Polygone &p);
	//! Surcharge operateur +=
	/*!
		\param p
		\return this += p
	*/
	Polygone& operator+=(const Vecteur2D &v);
	//! Surcharge operateur +
		/*!
		\param v
		\return this + v
	*/
	Polygone operator+(const Vecteur2D &v);
	//! Fonction Ajout Point
	/*!
		Ajoute un Vecteur2D dans le polygone
		\param v Vecteur2D à ajouter
	*/
	void addPoint(const Vecteur2D &v);
	//! Fonction Ajout Coté
	/*!
		Ajoute un Coté dans le polygone
		\param s Segment à ajouter
	*/
	void addSegment(const Segment &s);
	//! Getter Perimetre
	/*!
	\return Perimetre du polygone
	*/
	double getPerimetre() const;
	//! Getter Aire
	/*!
		\return Aire du polygone
	*/
	double getAire() const;
	virtual Polygone& Translation(const Vecteur2D &v);
	virtual Polygone& Rotation(const Vecteur2D &v, double angle);
	virtual Polygone& Homothetie(const Vecteur2D &v, double rapport);
	string Afficher() const;
	virtual void accepte(Visiteur *v) const;
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param c Polygone affiché
		\return o Flux sortant modifié
	*/
	friend ostream& operator<<(ostream &o, const Polygone &p);
	virtual string toString() const;
};

inline void Polygone::setNbCotes(int nbCotes)
{
	_nbCotes = nbCotes;
}

inline int Polygone::getNbCotes() const
{
	return _nbCotes;
}

inline vector<Vecteur2D> Polygone::getTabPts() const
{
	return _tabPts;
}

inline vector<Segment> Polygone::getTabCotes() const
{
	return _tabCotes;
}

inline void Polygone::setTabPts(vector<Vecteur2D> tab)
{
	_tabPts = tab;
}

inline void Polygone::setTabCotes(vector<Segment> tab)
{
	_tabCotes = tab;
}

inline Vecteur2D Polygone::getPoint(int index) const
{
	return _tabPts[index];
}

inline Segment Polygone::getCote(int index) const
{
	return _tabCotes[index];
}
