#pragma once
#include "Forme.h"
#include <vector>

class Vecteur2D;

//! Classe FormeComposee
/*!
	Hérite de Forme puisque c'est une forme (composée)
*/
class FormeComposee : public Forme
{
private:
	//! Tableau de formes
	/*!
		Vector de Forme (s) contenant toutes les Forme (s) de la FormeComposee
	*/
	vector<Forme*> _tabFormes;
public:
	//! Constructeur d'une forme
	/*!
		Une forme composée est construite à l'aide de sa couleur.
		Lorsqu'une forme est construite, elle n'appartient pas à un groupe, elle est donc fausse par défaut.
		\param couleur Couleur de la forme composée
	*/
	FormeComposee(int couleur);
	//! Constructeur par copie d'une FormeComposee
	/*!
		\param f FormeComposee que l'on veut copier
	*/
	FormeComposee(FormeComposee &f);
	//! Destructeur d'une FormeComposee
	/*!
		Destructeur Virtuel
	*/
	~FormeComposee();
	//! Getter Tableau de Forme (s)
	/*!
		Inline
		\return Tableau de Forme (s)
	*/
	inline vector<Forme*> getTabFormes() const;
	//! Surcharge operateur +=
	/*!
		\param f
		\return this += f
	*/
	FormeComposee& operator+=(Forme &f);
	//! Surcharge operateur +
	/*!
		\param f
		\return this + v
	*/
	FormeComposee operator+(Forme &f);
	//! Surcharge operateur []
	/*!
		\param index Emplacement de la Forme que l'on désire
		\return Forme
	*/
	Forme* operator[](int index) const;
	FormeComposee& Translation(const Vecteur2D &v);
	FormeComposee& Rotation(const Vecteur2D &v, double angle);
	FormeComposee& Homothetie(const Vecteur2D &v, double rapport);
	virtual string Afficher() const;
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param f FormeComposee affichée
		\return o Flux sortant modifié
	*/
	double getAire() const;
	friend ostream& operator<<(ostream& o, const FormeComposee &f);
	virtual void accepte(Visiteur *v) const;
	string toString() const;
};

inline vector<Forme*> FormeComposee::getTabFormes() const
{
	return _tabFormes;
}