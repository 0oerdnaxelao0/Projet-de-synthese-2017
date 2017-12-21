#include "ExpertFormeComposee.h"
#include "ExpertCercle.h"
#include "ExpertSegment.h"
#include "ExpertPolygone.h"
#include <fstream>


ExpertChargement* ExpertFormeComposee::initExpert() const
{
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
	return expert;
}

ExpertFormeComposee::ExpertFormeComposee(ExpertChargement * suivant) :ExpertChargement(suivant)
{
}

FormeComposee * ExpertFormeComposee::handle(const string & requete) const
{

	cout << "Expert Composee" << endl;
		vector<string> s = explode(requete, '|');
		if (s[0] == "FormeComposee")
		{
			FormeComposee * fc = new FormeComposee(stoi(s[1]));
			ExpertChargement * expert = initExpert();
			for (int i = 2; i < s.size(); i++)
			{
				Forme * f = expert->charge(s[i]);
					*fc += *f;
				f = NULL;
			}
			return fc;
		}
		else return NULL;
}
