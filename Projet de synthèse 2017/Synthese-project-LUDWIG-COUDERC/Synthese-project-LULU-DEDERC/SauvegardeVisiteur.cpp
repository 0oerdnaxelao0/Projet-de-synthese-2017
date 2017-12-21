#include "SauvegardeVisiteur.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Segment.h"
#include"FormeComposee.h"
#include "Triangle.h"
#include <fstream>

SauvegardeVisiteur::SauvegardeVisiteur() {}

void SauvegardeVisiteur::visite(const Cercle * circle)
{
	ofstream fichier("majoliefigure2.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << circle->toString() << "#";
		fichier.close();
	}
}

void SauvegardeVisiteur::visite(const Polygone * q)
{
	ofstream fichier("majoliefigure2.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << q->toString() << "#";
		fichier.close();
	}
}

void SauvegardeVisiteur::visite(const Segment * s)
{
	ofstream fichier("majoliefigure2.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << s->toString() << "#";
		fichier.close();
	}
}

void SauvegardeVisiteur::visite(const FormeComposee *fc)
{
	ofstream fichier("majoliefigure2.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << fc->toString() << "#";
		fichier.close();
	}
}

void SauvegardeVisiteur::visite(const Triangle *t)
{
	ofstream fichier("majoliefigure2.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << t->toString() << "#";
		fichier.close();
	}
}

void SauvegardeVisiteur::visite(const Vecteur2D * v)
{
}
