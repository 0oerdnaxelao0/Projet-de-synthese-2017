#pragma once
#include <string>
#include "Visitable.h"

class Vecteur2D;

using namespace std;

typedef void (Visiteur::*APointeurFonction)(int);

//! Classe Forme
/*!
	Classe abstraite
	Classe Mère de toutes les formes.
	Hérite de Visitable pour les classes filles qui seront déssinées.
*/
class Forme: public Visitable
{
private:
	//! Couleur
	/*!
		Couleur de la Forme déssinée
	*/
	int _couleur;
	//! Groupe
	/*!
		Vrai si la Forme appartient à une forme composée, faux sinon
	*/
	bool _groupe;
public:
	//! Constantes pour les couleurs
	/*!
		 0 : Rouge
		 1 : Vert
		 2 : Bleu
		 3 : Noir
		 4 : Jaune
		 5 : Cyan
	*/
	static const int RED = 0, GREEN = 1, BLUE = 2, BLACK = 3, YELLOW = 4, CYAN = 5;;
	//! Constructeur d'une Forme
	/*!
		Une Forme est construite à l'aide de sa couleur.
		Lorsqu'une Forme est construite, elle n'appartient pas à un groupe, elle est donc fausse par défaut.
		\param couleur Couleur de la forme
	*/
	Forme(int couleur);
	//! Constructeur par copie d'une Forme
	/*!
		\param f Forme que l'on veut copier
	*/
	Forme(const Forme &f);
	//! Destructeur d'une Forme
	/*!
		Destructeur Virtuel
	*/
	virtual ~Forme();
	//! Getter Couleur
	/*!
		Inline
		\return Couleur
	*/
	inline virtual int getCouleur() const;
	//! Setter Couleur
	/*!
		Inline
		\param couleur Couleur qui remplace celle existante
	*/
	inline virtual void setCouleur(int couleur);
	//! Getter groupe
	/*!
		Inline
		Retourne si la forme est dans un groupe ou non
		\return Groupe
	*/
	inline virtual bool estDansGroupe() const;
	//! Toggle groupe
	/*!
		Inline
		Change l'appartenance à un groupe de la forme
	*/
	inline virtual void toggleGroupe();
	//! Translation d'une forme
	/*!
		Effectue la translation d'une forme à partir de
		\param Vecteur2D v Vecteur de translation
		\return *this Forme transformée
	*/
	virtual Forme& Translation(const Vecteur2D &v) = 0;
	//! Rotation d'une forme
	/*!
		Effectue la rotation d'une forme à partir de
		\param Vecteur2D v Vecteur de rotation
		\param angle Angle de rotation en degrés
		return *this Forme transformée
	*/
	virtual Forme& Rotation(const Vecteur2D &v, double angle) const = 0;
	//! Homothétie d'une forme
	/*!
		Effectue l'homothétie d'une forme à partir de
		\param Vecteur2D v Vecteur d'homothétie
		\param rapport Rapport d'homothétie
		return *this Forme transformée
	*/
	virtual Forme& Homothetie(const Vecteur2D &v, double rapport) = 0;
	//! Affichage d'une forme
	/*!
		Fonction d'affichage d'une forme pour la console (cout)
		\return string Chaine affichée par cout
	*/
	virtual string Afficher() const;
	//! Surcharge operateur <<
	/*!
		\param o Flux sortant
		\param f Forme affichée
		\return o Flux sortant modifié
	*/
	friend ostream& operator<<(ostream& o, const Forme &f);
	virtual void accepte(Visiteur *v) const = 0;
	//! toString
	/*!
		Fonction utilisée pour :
		- l'envoi de requete au serveur de dessin
		- la sauvegarde dans un fichier texte
		\return string Forme
	*/
	virtual string toString() const = 0;
	virtual double getAire() const = 0;
};

int Forme::getCouleur() const
{
	return _couleur;
}

void Forme::setCouleur(int couleur)
{
	_couleur = couleur;
}

bool Forme::estDansGroupe() const
{
	return _groupe;
}

void Forme::toggleGroupe()
{
	_groupe = !_groupe;
}


