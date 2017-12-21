#pragma once
#include <vector>
#include <string>
#include "Forme.h"


using namespace std;
class Forme;

//! Classe ExpertChargementPere
/*!
	Classe abstraite <br />
	Classe "Mere" de tous les experts pour le chargement des formes dans un fichier texte
*/

class ExpertChargementPere
{
	//! Fonction charge
	/*!
		\param d : donnée du problème à résoudre
		\return la solution ou NULL en cas déchec
	*/
	virtual  Forme * charge(const string & requete) const = 0;
};


