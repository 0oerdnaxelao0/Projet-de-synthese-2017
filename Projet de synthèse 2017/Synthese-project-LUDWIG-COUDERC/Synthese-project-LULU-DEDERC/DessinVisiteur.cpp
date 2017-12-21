#include "DessinVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Vecteur2D.h"
#include "FormeComposee.h"
#include <iostream>
#include <string>

using namespace std;

DessinVisiteur::DessinVisiteur() 
{
	ExistingFrame = false;
	client = new ClientDessin("127.0.0.1", 16000);
}

void DessinVisiteur::toogleExistingFrame()
{
	ExistingFrame = !ExistingFrame;
}

void DessinVisiteur::visite(const Cercle * circle)
{
	// Envoie l'ordre de créer une nouvelle fenêtre
	if (!ExistingFrame)
	{
		client->dessin("NewFrame\r\n");
		toogleExistingFrame();
		requete = "";
	}
		

	//Création de la requête et envoi
	cout << "je Dessin un cercle ";
	double x = circle->getCentre().getX() - circle->getRayon();
	double y = circle->getCentre().getY() + circle->getRayon();
	double diam = circle->getRayon() * 2;
	string typ = "Cercle;";


	cout << "Requête à envoyer : " << typ + to_string(circle->getCouleur()) + ";" + to_string(x) + ";" + to_string(y) + ";" + to_string(diam);

	client->dessin(typ + to_string(circle->getCouleur()) + ";" + to_string(x) + ";" + to_string(y) + ";" + to_string(diam)+"\r\n");
}

void DessinVisiteur::visite(const Polygone * q)
{
	if (!ExistingFrame)
	{
		client->dessin("NewFrame\r\n");
		toogleExistingFrame();
		requete = "";
	}
	requete = "Polygone;" + to_string(q->getCouleur());
	for each (Vecteur2D point in q->getTabPts())
	{
		requete += ";" + to_string(point.getX()) + ";" + to_string(point.getY());
	}
	requete += "\r\n";
	cout << "Requête à envoyer : " << requete;
	client->dessin(requete);
	requete = "";
}

void DessinVisiteur::visite(const Segment *s)
{
	if (!ExistingFrame)
	{
		client->dessin("NewFrame\r\n");
		toogleExistingFrame();
		requete = "";
	}
	double x1 = s->getX().getX();
	double y1 = s->getX().getY();
	double x2 = s->getY().getX();
	double y2 = s->getY().getY();

	requete = "Segment;" + to_string(s->getCouleur()) + ";" + to_string(x1) + ";" + to_string(y1) + ";" + to_string(x2) + ";" + to_string(y2)+"\r\n";
	cout << "Requête à envoyer : " << requete;
	client->dessin(requete);
	requete = "";
}

void DessinVisiteur::visite(const FormeComposee *fc)
{
	if (!ExistingFrame || (ExistingFrame == NULL))
	{
		client->dessin("NewFrame\r\n");
		toogleExistingFrame();
		requete = "";
	}
	cout << "je Dessin une forme compose";
	requete = "Composee;" + to_string(fc->getCouleur())+";"+"\r\n";
	client->dessin(requete);
	int taille = fc->getTabFormes().size();
	for (int i = 0; i < taille; i++)
	{
		(*fc)[i]->accepte((Visiteur*) this);
	}
	//client->dessin("Color\r\n");
}

void DessinVisiteur::visite(const Triangle * t)
{
	visite((Polygone*)t);
}

void DessinVisiteur::visite(const Vecteur2D * v)
{
}
