#pragma once
#include "ExpertChargement.h"
#include "FormeComposee.h"

//! Classe ExpertFormeComposee
/*!
	Classe expertCOR pour le chargement des FormeComposee (s) dans un fichier texte
*/

class ExpertFormeComposee : public ExpertChargement
{
private:
	//! Fonction initExpert
	/*!
		Initialisation des experts pour les differentes Formes (s) de façon à ce que tout type de Forme puisse être construit.
	*/
	ExpertChargement* initExpert() const;
public:
	//! Constructeur ExpertSegment
	/*!
		Un ExpertFormeComposee est construit avec son suivant
		\param expertSuivant
	*/
	ExpertFormeComposee(ExpertChargement * suivant);
protected:
	FormeComposee * handle(const string & requete) const;
};

