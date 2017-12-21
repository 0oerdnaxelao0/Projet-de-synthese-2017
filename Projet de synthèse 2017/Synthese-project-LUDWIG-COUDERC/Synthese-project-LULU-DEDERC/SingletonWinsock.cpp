#include "SingletonWinsock.h"
#include <iostream>
#include <string.h>
#include <WinSock2.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "SingletonWinsock.h"
#include "Erreur.h"     // ma petite classe d'erreur personnelle

#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++

#define L 200 // longueur max d'une cha�ne de caract�res


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
	requete += "\r\n";     // pour que le serveur r�ceptionne bien le message
	int l = requete.length();
	const char * requeteChar = requete.c_str();
	cout << "J'envoie " << requeteChar << endl;
	SingletonWinsock::r = send(sock, requeteChar, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
											   // envoie au plus  l octets
	if (SingletonWinsock::r == SOCKET_ERROR)
		throw Erreur("�chec de l'envoi de la requ�te");
}

SingletonWinsock::SingletonWinsock()
{
	cout << "Initialisation de la connexion:" << endl;
	try
	{
		//-------------- initialisation ressources librairie winsock -------------------------------
		//initialisationWinsock();
		//---------------------- cr�ation socket -------------------------------------------------
		//creerSocket();
		//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------

		//creerRepresentantServeur();

		try
		{
			SingletonWinsock::r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

															/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

			if (SingletonWinsock::r) throw Erreur("L'initialisation a �chou�");

			cout << "client vers le serveur de majuscule" << endl;
			cout << "initialisation effectu�e" << endl;

			//---------------------- cr�ation socket -------------------------------------------------

			SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole

			int familleAdresses = AF_INET;         // IPv4
			int typeSocket = SOCK_STREAM;           // mode connect� TCP
			int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
													// pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

			sock = socket(familleAdresses, typeSocket, protocole);

			if (sock == INVALID_SOCKET)
			{
				ostringstream oss;
				oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
				throw Erreur(oss.str().c_str());
			}

			cout << "socket cr��" << endl;

			//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------

			char adresseServeur[L];
			short portServeur;

			cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
			cin >> adresseServeur;
			cout << "tapez le port du serveur du serveur de majuscule : " << endl;
			cin >> portServeur;

			SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

			sockaddr.sin_family = AF_INET;
			sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
			sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

																	//-------------- connexion du client au serveur ---------------------------------------

			SingletonWinsock::r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																			// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

			if (SingletonWinsock::r == SOCKET_ERROR)
				throw Erreur("La connexion a �chou�");

			cout << "connexion au serveur de majuscule r�ussie" << endl;


/*
			SingletonWinsock::r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
																	// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

			if (SingletonWinsock::r == SOCKET_ERROR)
				throw Erreur("la coupure de connexion a �chou�");


			SingletonWinsock::r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
			if (SingletonWinsock::r) throw Erreur("La fermeture du socket a �chou�");

			WSACleanup();
			cout << "arr�t normal du client" << endl;
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
	SingletonWinsock::r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
													/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

	if (SingletonWinsock::r) throw Erreur("L'initialisation a �chou�");

	cout << "client vers le serveur de majuscule" << endl;
	cout << "initialisation effectu�e" << endl;
}

void SingletonWinsock::creerSocket()
{
	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket cr��" << endl;
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
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

															//-------------- connexion du client au serveur ---------------------------------------

	SingletonWinsock::r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																	// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

	if (SingletonWinsock::r == SOCKET_ERROR)
		throw Erreur("La connexion a �chou�");

	cout << "connexion au serveur de majuscule r�ussie" << endl;
}
