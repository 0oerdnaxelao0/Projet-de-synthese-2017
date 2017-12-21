#pragma once
#include <string>
class Visiteur;

using namespace std;

//!Classe Visitable
/*!
	On est visitable si on peut accepter un visiteur
*/

class Visitable {
public:
	//! Fonction accepte qui rentre des les formes
	/*!
		\param Visiteur
	*/
	virtual void accepte(Visiteur*) const  = 0;
};
