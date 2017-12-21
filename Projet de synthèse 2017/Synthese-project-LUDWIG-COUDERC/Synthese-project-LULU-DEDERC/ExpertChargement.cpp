#include "ExpertChargement.h"
#include <fstream>
#include <exception>
#include "ExpertCercle.h"
#include "ExpertSegment.h"
#include "ExpertPolygone.h"
#include "ExpertFormeComposee.h"

ExpertChargement::ExpertChargement(ExpertChargement * expert)
{
	_suivant = expert;
}


vector<string> ExpertChargement::explode(const string s, const char& c) const
{
	string buff = "";
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else
			if (n == c && buff != "")
			{
				v.push_back(buff);
				buff = "";
			}
	}
	if (buff != "")
		v.push_back(buff);
	return v;
}

ExpertChargement::~ExpertChargement()
{
}

string ExpertChargement::OuvertureFichier(string fichier)
{
	std::ifstream f(fichier, ios::in);
	if (f)
	{
		string res;
		getline(f, res);
		return res;
	}
	else
		throw new exception;
}

Forme * ExpertChargement::charge(const string& requete) const
{
	Forme * f = this->handle(requete);

	if (f != NULL) return f;

	else
	{
		if (this->_suivant != NULL) return this->_suivant->charge(requete);
		else return NULL;
	}
}
