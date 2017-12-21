#pragma once

#pragma region Include
#include <iostream>
#include <string>
#include "Cercle.h"
#include "Triangle.h"
#include "Segment.h"
#include "DessinVisiteur.h"
#include "ExpertPolygone.h"
#include "ExpertSegment.h"
#include "ExpertCercle.h"
#include "ExpertFormeComposee.h"
#include "SauvegardeVisiteur.h"
#include "SingletonWinsock.h"
#pragma endregion


using namespace std;

int main()
{
	try {
		DessinVisiteur * dv = new DessinVisiteur();
		SauvegardeVisiteur* Sauveur = new SauvegardeVisiteur();


		Vecteur2D A(1, 0), B(4, -2), C(4, 2);
		Triangle T1(Forme::GREEN, A, B, C);

		T1.Homothetie(Vecteur2D(-10, -10), 100);
		T1.Rotation(Vecteur2D(0, 0), 45);
		T1.accepte(dv);

		Vecteur2D D(7, 0);
		Cercle C1(Forme::YELLOW, D, 2);
		C1.Homothetie(Vecteur2D(-10, -10), 100);
		C1.Rotation(Vecteur2D(0, 0), 45);
		C1.accepte(dv);


		Vecteur2D E(11, -1), F(15, -1), G(15, 1), H(11, 1);
		Polygone R1(Forme::BLUE);
		R1 = R1 + E + F + G + H;
		R1.Homothetie(Vecteur2D(-10, -10), 100);
		R1.Rotation(Vecteur2D(0, 0), 45);
		R1.accepte(dv);

		Vecteur2D I(17, 0);
		Cercle C2(Forme::YELLOW, I, 1);
		C2.Homothetie(Vecteur2D(-10, -10), 100);
		C2.Rotation(Vecteur2D(0, 0), 45);
		C2.accepte(dv);

		system("PAUSE");

		FormeComposee G1(Forme::RED);
		G1 += T1;
		G1 += C1;
		G1 += R1;
		G1 += C2;



		G1.Translation(Vecteur2D(-4, 0));
		G1.Rotation(Vecteur2D(0, 0), 45);

		cout << G1;
		cout << "Aire de G1 :" << G1.getAire() << endl;
		system("PAUSE");

		cout << "On dessine G1 :" << endl;

		G1.Homothetie(Vecteur2D(-10, -10), 100);
		G1.accepte(dv);
		system("PAUSE");

		G1.accepte(Sauveur);

		ExpertChargement* expert;
		ExpertCercle * expertCercle;
		ExpertPolygone* expertPolygone;
		ExpertFormeComposee* expertFormeComposee;
		ExpertSegment * expertSegment;

		expertSegment = new ExpertSegment(NULL);
		expertFormeComposee = new ExpertFormeComposee(expertSegment);
		expertPolygone = new ExpertPolygone(expertFormeComposee);
		expertCercle = new ExpertCercle(expertPolygone);
		expert = expertCercle;

		string requete = expert->OuvertureFichier("majoliefigure2.txt");
		Forme * G2 = expert->charge(requete);
		system("pause");

		cout << *G2 << endl;
		G2->accepte(dv);
		system("pause");
	}
		catch (exception const& e)
		{
			cerr << "Erreur : " << e.what() << endl;
			system("pause");
		}
























	/*
	//DessinVisiteur * dv = new DessinVisiteur();

	SauvegardeVisiteur* Sauveur = new SauvegardeVisiteur();

	Vecteur2D A(10, 30), B(20, 40), C(40, 50), D(60, 40), E(70, 30), F(60, 20), G(40, 10), H(20, 20), Transl(10, 10);

	cout << "Segment" << endl;

	Segment S1(0, A, B);
	//S1.accepte(dv);
	cout << S1 << endl;
	system("pause");

	try
	{
		cout << "Triangle" << endl;
		Triangle T(1, A, B, C);

		cout << T << endl;
		//T.accepte(dv);
		//T.accepte(Sauveur);
		system("pause");

		cout << "Quadrilatere" << endl;

		
		Polygone P(2);
		P = P + A + B + C + D;
		cout << P << endl;
		//P.accepte(dv);
		//P.accepte(Sauveur);
		system("pause");
		
		cout << "Cercle" << endl;
		
		Cercle Cercle1(2, E, 20.0);
		cout << Cercle1 << endl;
		//Cercle1.accepte(dv);
		//Cercle1.accepte(Sauveur);
		system("pause");

		cout << "Octogone avec le polygone precedent" << endl;

		P = P + E + F + G + H;
		cout << P << endl;

		FormeComposee fc(2);
		fc += P;
		fc += T;
		fc += Cercle1;
		//fc.accepte(dv);
		fc.accepte(Sauveur);
		//system("pause");

		ExpertChargement* expert;
		ExpertCercle * expertCercle;
		ExpertPolygone* expertPolygone;
		ExpertFormeComposee* expertFormeComposee;
		ExpertSegment * expertSegment;

		expertSegment = new ExpertSegment(NULL);
		expertFormeComposee = new ExpertFormeComposee(expertSegment);
		expertPolygone = new ExpertPolygone(expertFormeComposee);
		expertCercle = new ExpertCercle(expertPolygone);
		expert = expertCercle;

		string requete = expert->OuvertureFichier("sauv.txt");
		Forme * f = expert->charge(requete);
		system("pause");

		cout << *f << endl;

		system("pause");

	}
	catch (exception const& e)
	{
		cerr << "Erreur : " << e.what() << endl;
		system("pause");
	}
	//DessinVisiteur * dv = new DessinVisiteur();
	//Cercle2.accepte(dv);
	*/
}
