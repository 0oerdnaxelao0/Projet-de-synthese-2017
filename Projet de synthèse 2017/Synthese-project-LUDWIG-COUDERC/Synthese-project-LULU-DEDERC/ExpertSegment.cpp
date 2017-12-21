#include "ExpertSegment.h"
#include <fstream>



ExpertSegment::ExpertSegment(ExpertChargement * suivant):ExpertChargement(suivant)
{
}

Segment * ExpertSegment::handle(const string & requete) const
{
		cout << "Expert Segment" << endl;
		vector<string> s = explode(requete, ';');
		if (s[0] == "Segment")
		{
			Segment * res = new Segment(stoi(s[1]), Vecteur2D(stod(s[2]), stod(s[3])), Vecteur2D(stod(s[4]), stod(s[5])));
			//delRequete(0);
			return res;
		}
		else return NULL;
}
