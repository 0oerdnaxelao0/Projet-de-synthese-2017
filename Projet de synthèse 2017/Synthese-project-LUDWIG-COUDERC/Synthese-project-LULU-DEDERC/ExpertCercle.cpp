#include "ExpertCercle.h"
#include <fstream>




ExpertCercle::ExpertCercle(ExpertChargement * suivant):ExpertChargement(suivant)
{
}

Cercle * ExpertCercle::handle(const string & requete) const
{
		cout << "Expert Cercle" << endl;
		vector<string> s = explode(requete, ';');
		if (s[0] == "Cercle")
		{
			Cercle * res = new Cercle(stoi(s[1]), Vecteur2D(stod(s[2]), stod(s[3])), stod(s[4]));
			return res;
		}
		else return NULL;
}
