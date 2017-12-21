#pragma once
#include"Visiteur.h"
#include <iostream>
#include <string>
#include <sstream>
#include "SingletonWinsock.h"
#include "ClientDessin.h"
using namespace std;

//! Classe DessinVisiteur
/*!
	Hérite de Visiteur <br />
	Gère l'envoi des requêtes (chaînes de caractères) au serveur de dessin des differents types de Forme (s)
*/


class DessinVisiteur : public Visiteur 
{
	//classe concrete avec un .cpp
private:
	//! ExistingFrame
	/*!
		Définit si une fenêtre a déjà été créée et initialisée côté serveur
	*/
	bool ExistingFrame;
	//! Requete
	/*!
		Requete envoyée au serveur
	*/
	string requete;
	//! Client
	/*!
		Client de dessin utilisé
	*/
	ClientDessin * client;
	//! Méthode toogleExistingFrame
	/*!
		Change l'état binaire de ExistingFrame
	*/
	void toogleExistingFrame();
public:
	DessinVisiteur();
	//! Méthodes visite
	/*!
	\param titre Requete à envoyer
	Envoie la requete au serveur de dessin en fonction de la forme choisie
	*/
	void visite(const Cercle * circle);
	void visite(const Polygone *q);
	void visite(const Segment *s);
	void visite(const FormeComposee*);
	void visite(const Triangle* t);
	void visite(const Vecteur2D * v);
};