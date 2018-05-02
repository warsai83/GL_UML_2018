#include "Maladie.h"



Maladie::Maladie()
{
}


Maladie::~Maladie()
{
}

void Maladie::AjouterEmpreinte(Empreinte emp)
{
	list<Empreinte>::iterator it = ListeEmpreintes.begin();
	ListeEmpreintes.insert(it,emp);
}

string Maladie::toString()
{
	string s = Name + " :\r\n";
	list<Empreinte>::iterator it;
	for (it = ListeEmpreintes.begin(); it != ListeEmpreintes.end(); ++it)
	{
		s += (*it).toString() + "\r\n";
	}
	return s;
}