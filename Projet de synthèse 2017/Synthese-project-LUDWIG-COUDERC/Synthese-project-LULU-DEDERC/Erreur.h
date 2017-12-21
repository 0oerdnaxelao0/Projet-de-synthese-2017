/**
classe Erreur
*/
#ifndef ERREUR
#define ERREUR

using namespace std;

#include <string>
#include <iostream>
//! Classe Erreur
/*!
	Affiche une erreur
*/
class Erreur
{
public:
	//! Longueur du message
	/*!
	Longueur maximale du message d'erreur (100 caractères)
	*/
	const static int LONGUEURMESSAGE = 100;
	//! Message
	/*!
		Message à afficher
	*/
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	//!Constructeur
	/*!
	\param messageErreur message à afficher
	Affiche le message de l'erreur à l'écran
	*/
	Erreur(const char * messageErreur);

	operator string() const;
};
//! surcharge opérateur ostream
ostream & operator << (ostream & os, const Erreur & erreur);

#endif

