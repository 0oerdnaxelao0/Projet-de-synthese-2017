#pragma once
#include "ExpertChargement.h"
#include "Cercle.h"

//! Classe ExpertCercle
/*!
	Classe expertCOR pour le chargement des Cercle (s) dans un fichier texte
*/

class ExpertCercle : public ExpertChargement
{
public:
	//! Constructeur ExpertCercle
	/*!
		Un ExpertCercle est construit avec son suivant
		\param expertSuivant
	*/
	ExpertCercle(ExpertChargement * suivant);
protected:
	Cercle * handle(const string & requete) const;
};

