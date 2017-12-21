#include "ExpertPolygone.h"
#include <fstream>



ExpertPolygone::ExpertPolygone(ExpertChargement * suivant) :ExpertChargement(suivant)
{
}

Polygone * ExpertPolygone::handle(const string & requete) const
{
		cout << "Expert Polygone" << endl;
		vector<string> s = explode(requete, ';');
		if ((s[0] == "Polygone") || (s[0] == "Triangle"))

		{
			Polygone * res = new Polygone(stoi(s[1]));
			for (int i = 2; i < s.size() - 1; i+=2)
			{
				*res += Vecteur2D(stod(s[i]), stod(s[i + 1]));
			}
			res->ConstruirePolygone();
			return res;
		}
		else return NULL;
}
