#pragma once
#include "ExpertChargement.h"
#include "Polygone.h"

//! Classe ExpertPolygone
/*!
	Classe expertCOR pour le chargement des Polygone (s) dans un fichier texte
*/

class ExpertPolygone : public ExpertChargement
{
public:
	//! Constructeur ExpertPolygone
	/*!
		Un ExpertPolygone est construit avec son suivant
		\param expertSuivant
	*/
	ExpertPolygone(ExpertChargement * suivant);
protected:
	Polygone * handle(const string & requete) const;
};

