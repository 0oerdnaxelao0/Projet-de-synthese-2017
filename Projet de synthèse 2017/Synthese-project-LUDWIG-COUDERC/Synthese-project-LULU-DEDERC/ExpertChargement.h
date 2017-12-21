#pragma once
#include<string>
#include<vector>
#include "Forme.h"
#include "ExpertChargementPere.h"

using namespace std;

//! Classe ExpertChargement
/*!
	Classe abstraite <br/>
	Classe Mere de tous les experts COR pour le chargement des formes dans un fichier texte
*/

class ExpertChargement : ExpertChargementPere
{
private:
	//! Suivant
	/*!
		Pointeur vers l'expert suivant
	*/
	ExpertChargement *_suivant;
protected:
	//! Constructeur ExpertChargement
	/*!
		Un ExpertChargement est construit avec son suivant
		\param expertSuivant
	*/
	ExpertChargement(ExpertChargement * expertSuivant);
	//! Fonction handle
	/*!
		Construit une forme a partir d'une requete sous forme de chaine de caractère
		\param requete
		\return Forme construite
	*/
	virtual Forme * handle(const string & requete) const = 0;
	vector<string> explode(const string s, const char& c) const;
public:
	//! Destructeur ExpertChargement
	/*!
		Destructeur Virtuel
	*/
	~ExpertChargement();
	//! Ouverture Fichier
	/*
		Ouvre le fichier et renvoie la chaine de caractère correspondant a toute la premiere ligne
		\param fichier
	*/
	string OuvertureFichier(string fichier);
	virtual Forme* charge(const string & requete) const;
};