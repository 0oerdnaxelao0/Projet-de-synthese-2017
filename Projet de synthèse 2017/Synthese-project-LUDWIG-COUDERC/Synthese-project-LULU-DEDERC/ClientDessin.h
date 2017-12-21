#pragma once

#include <WinSock2.h>
#include <string>
#include <string.h>

using namespace std;

//!Classe ClientDessin
/*!
	Crée un client TCP/IP vers un serveur de dessin.
	Envoie des requêtes de dessin

 protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
 Chaque paramètre de la forme est séparé par un ; .

*/
class ClientDessin
{
	//! Socket
	/*!
		Informations concernant le socket à créer :
		- famille d'adresses acceptées
		- mode connecté ou non
		- protocole
	*/
	SOCKET sock;
	//! Adresse Socket
	/*!
		 Informations concernant le serveur avec lequel on va communiquer
	*/
	SOCKADDR_IN sockaddr;

public:
	//! Constructeur d'un client de dessin
	/*!
		\param adresseServeurDessin
		\param portServeurDessin
	*/
	ClientDessin(const string & adresseServeurDessin, const int portServeurDessin);
	//! Destructeur d'un client de dessin
	/*!
		Destructeur Virtuel
	*/
	virtual ~ClientDessin();
	//! Méthode dessin
	/*!
		\param titre Requete à envoyer
		Envoie la requete au serveur de dessin
	*/
	void dessin(const string & titre);
};



