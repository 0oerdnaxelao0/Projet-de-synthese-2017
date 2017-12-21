#pragma once
//!Classe MaWinsock
/*!
singleton contenant l'initialisation de la librairie winsock2.

Assure que la DLL de la winsock est initialisée une unique fois

*/

//Bibliothèque Winsock utilisée
#include <WinSock2.h>

class MaWinsock
{
	//! wsaData
	/*!
		structure contenant les données de la librairie winsock à initialiser. 
		représente la DLL.
	*/
	WSADATA wsaData;
	//!Constructeur Par défaut
	MaWinsock(void);

	//!Instance de la winsock
	/*!
		Instance unique de la winsock
	*/
	static MaWinsock * instanceUnique;
public:
	//!get Instance
	/*!
		Retourne l'instance de la classe MAWinsock
	*/
	static MaWinsock * getInstance();
	//! Destructeur de MaWinsock
	~MaWinsock(void);
};

