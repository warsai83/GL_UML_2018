/*************************************************************************
							Maladie  -  description
		Classe représentant une maladie connue, elle posséde
			en attribut les empreintes lui correspondant
							-------------------
début                :	02-05-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
									 Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
						mathilde.moureau@insa-lyon.fr
						stanley.cheah@insa-lyon.fr
						william.occelli@insa-lyon.fr

*************************************************************************/
//--- Réalisation de la classe <Maladie> (fichier Empreinte.cpp)--------

//---------------------------------------------------------------- INCLUDE
#include "Maladie.h"
#include "Console.h"
//----------------------------------------------------------------- PUBLIC
extern Console* c;

//----------------------------------------------------- M�thodes publiques

void Maladie::AjouterEmpreinte(Empreinte emp)
{
	vector<Empreinte>::iterator it = ListeEmpreintes.begin();
	ListeEmpreintes.insert(it, emp);
}

bool operator==(Maladie const &M1, Maladie const &M2)
{
	return (M1.getName()==M2.getName());
}

bool operator<(Maladie const &M1, Maladie const &M2)
{
	return (M1.getName() < M2.getName());
}

bool operator>(Maladie const &M1, Maladie const &M2)
{
	return (M1.getName() > M2.getName());
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
Maladie::Maladie(string name) : Name(name)
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Maladie>");
#endif
}

Maladie::~Maladie()
{
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Maladie>");
#endif
}