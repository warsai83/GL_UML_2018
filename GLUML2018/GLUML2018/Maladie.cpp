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

bool operator==(Maladie const &M1, Maladie const &M2)
{
	if (M1.getName().compare(M2.getName()) != 0)
	{
		return false;
	}
	else {
		return true;
	}
}

string Maladie::getName() const
{
	return Name;
}

string Maladie::toString()
{
	string s = Name + " :\r\n";
	list<Empreinte>::iterator it;
	for (it = ListeEmpreintes.begin(); it != ListeEmpreintes.end(); ++it)
	{
		s += (*it).toString() + "\r\n";
	}
	s += "~";
	return s;
}