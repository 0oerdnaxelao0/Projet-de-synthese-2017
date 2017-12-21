#include "SingletonWinsock.h"
#include <iostream>
#include <string.h>
#include <WinSock2.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "SingletonWinsock.h"
#include "Erreur.h"     // ma petite classe d'erreur personnelle

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

#define L 200 // longueur max d'une chaîne de caractères


using namespace std;

int SingletonWinsock::r;
SOCKET SingletonWinsock::sock;
SOCKADDR_IN sockaddr;

//SingletonWinsock SingletonWinsock::m_instance = SingletonWinsock();

SingletonWinsock & SingletonWinsock::Instance()
{
	static SingletonWinsock m_instance = SingletonWinsock();
	return m_instance;
}

void SingletonWinsock::envoiRequete(string requete)
{
	requete += "\r\n";     // pour que le serveur réceptionne bien le message
	int l = requete.length();
	const char * requeteChar = requete.c_str();
	cout << "J'envoie " << requeteChar << endl;
	SingletonWinsock::r = send(sock, requeteChar, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
											   // envoie au plus  l octets
	if (SingletonWinsock::r == SOCKET_ERROR)
		throw Erreur("échec de l'envoi de la requête");
}

SingletonWinsock::SingletonWinsock()
{
	cout << "Initialisation de la connexion:" << endl;
	try
	{
		//-------------- initialisation ressources librairie winsock -------------------------------
		//initialisationWinsock();
		//---------------------- création socket -------------------------------------------------
		//creerSocket();
		//------------------------------ création du représentant du serveur ----------------------------------------

		//creerRepresentantServeur();

		try
		{
			SingletonWinsock::r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

															/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

			if (SingletonWinsock::r) throw Erreur("L'initialisation a échoué");

			cout << "client vers le serveur de majuscule" << endl;
			cout << "initialisation effectuée" << endl;

			//---------------------- création socket -------------------------------------------------

			SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole

			int familleAdresses = AF_INET;         // IPv4
			int typeSocket = SOCK_STREAM;           // mode connecté TCP
			int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
													// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

			sock = socket(familleAdresses, typeSocket, protocole);

			if (sock == INVALID_SOCKET)
			{
				ostringstream oss;
				oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
				throw Erreur(oss.str().c_str());
			}

			cout << "socket créé" << endl;

			//------------------------------ création du représentant du serveur ----------------------------------------

			char adresseServeur[L];
			short portServeur;

			cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
			cin >> adresseServeur;
			cout << "tapez le port du serveur du serveur de majuscule : " << endl;
			cin >> portServeur;

			SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

			sockaddr.sin_family = AF_INET;
			sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
			sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

																	//-------------- connexion du client au serveur ---------------------------------------

			SingletonWinsock::r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																			// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

			if (SingletonWinsock::r == SOCKET_ERROR)
				throw Erreur("La connexion a échoué");

			cout << "connexion au serveur de majuscule réussie" << endl;


/*
			SingletonWinsock::r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
																	// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

			if (SingletonWinsock::r == SOCKET_ERROR)
				throw Erreur("la coupure de connexion a échoué");


			SingletonWinsock::r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
			if (SingletonWinsock::r) throw Erreur("La fermeture du socket a échoué");

			WSACleanup();
			cout << "arrêt normal du client" << endl;
*/
		}
		catch (exception e)
		{
			cerr << "Echec lors de la coupure de connexion : "<<e.what();
		}
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}
}


SingletonWinsock::~SingletonWinsock()
{
	cout << "Deconnexion..." << endl;
}

void SingletonWinsock::initialisationWinsock()
{
	SingletonWinsock::r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2
													/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

	if (SingletonWinsock::r) throw Erreur("L'initialisation a échoué");

	cout << "client vers le serveur de majuscule" << endl;
	cout << "initialisation effectuée" << endl;
}

void SingletonWinsock::creerSocket()
{
	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket créé" << endl;
}

void SingletonWinsock::creerRepresentantServeur()
{
	cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
	cin >> adresseServeur;
	cout << "tapez le port du serveur du serveur de majuscule : " << endl;
	cin >> portServeur;

	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

															//-------------- connexion du client au serveur ---------------------------------------

	SingletonWinsock::r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																	// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (SingletonWinsock::r == SOCKET_ERROR)
		throw Erreur("La connexion a échoué");

	cout << "connexion au serveur de majuscule réussie" << endl;
}
