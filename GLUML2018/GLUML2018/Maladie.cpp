/*************************************************************************
Maladie  -  description
Classe repr�sentant une maladie connue, elle poss�de en attribut les
empreintes lui correspondant
-------------------
d�but                :	02-05-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
mathilde.moureau@insa-lyon.fr
stanley.cheah@insa-lyon.fr
william.occelli@insa-lyon.fr

*************************************************************************/
//--- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp)--------

//---------------------------------------------------------------- INCLUDE
#include "Maladie.h"


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- M�thodes publiques

void Maladie::AjouterEmpreinte(Empreinte emp)
{
	vector<Empreinte>::iterator it = ListeEmpreintes.begin();
	ListeEmpreintes.insert(it, emp);
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

vector<Empreinte> Maladie::getListeEmpreintes() const
{
	return ListeEmpreintes;
}

string Maladie::toString()
{
	string s = Name + " :\r\n";
	vector<Empreinte>::iterator it;
	for (it = ListeEmpreintes.begin(); it != ListeEmpreintes.end(); ++it)
	{
		s += (*it).toString() + "\r\n";
	}
	s += "~";
	return s;
}

//-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie()
{
}

Maladie::~Maladie()
{
}