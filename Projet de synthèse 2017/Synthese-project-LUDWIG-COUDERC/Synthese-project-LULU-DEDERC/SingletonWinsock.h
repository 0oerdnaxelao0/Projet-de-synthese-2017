#pragma once
#include <iostream>
#include <string.h>
#include <WinSock2.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "SingletonWinsock.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

#define L 200 // longueur max d'une chaîne de caractères

using namespace std;
//!Classe SingletonWinsock
/*!
		OBSOLETE ET INUTILE
*/

class SingletonWinsock
{
public:
	SingletonWinsock();
	~SingletonWinsock();
	static SingletonWinsock& Instance();
	static void envoiRequete(string requete);
private:
	// structure contenant les données de la librairie winsock à initialiser
	static int r;
	WSADATA wsaData;
	static SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole
	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
											// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock
	char adresseServeur[L];
	short portServeur;
	static SingletonWinsock m_instance;
	

	void initialisationWinsock();
	void creerSocket();
	void creerRepresentantServeur();
};
