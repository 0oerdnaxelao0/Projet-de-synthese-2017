#pragma once
#include "ExpertChargement.h"
#include "Segment.h"

//! Classe ExpertSegment
/*!
	Classe expertCOR pour le chargement des Segment (s) dans un fichier texte
*/

class ExpertSegment : public ExpertChargement
{
public:
	//! Constructeur ExpertSegment
	/*!
		Un ExpertSegment est construit avec son suivant
		\param expertSuivant
	*/
	ExpertSegment(ExpertChargement * suivant);
protected:
	Segment * handle(const string & requete) const;
};