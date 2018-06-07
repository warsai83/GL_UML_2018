/*************************************************************************
						Empreinte  -  description
Classe représentant l'objet Empreinte qui posséde les caractéristiques du
patient en attributs ainsi que la maladie diagnostiquée
							-------------------
début                :	02-05-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
									Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
						mathilde.moureau@insa-lyon.fr
						stanley.cheah@insa-lyon.fr
						william.occelli@insa-lyon.fr

*************************************************************************/

//--- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp)--------

//---------------------------------------------------------------- INCLUDE
#include "Empreinte.h"
#include "Console.h"
//----------------------------------------------------------------- PUBLIC
extern Console* c;

string Empreinte::toString()
{
	string s = to_string(NoID) + ";" + A1 + ";" + to_string(A2) + ";" + to_string(A3) + ";" + to_string(A4) + ";" + Disease;
	return s;
}

string Empreinte::getDisease() const{
	return Disease;
}

//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte(int unNoID, string unA1, double unA2, double unA3, double unA4, string disease) : NoID(unNoID), A1(unA1), A2(unA2), A3(unA3), A4(unA4), Disease(disease)
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Empreinte>");
#endif
}

Empreinte::Empreinte()
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur vide de <Empreinte>");
#endif
}

Empreinte::Empreinte(const Empreinte & uneEmpreinte): NoID(uneEmpreinte.NoID), A1(uneEmpreinte.A1), A2(uneEmpreinte.A2), A3(uneEmpreinte.A3), A4(uneEmpreinte.A4), Disease(uneEmpreinte.Disease)
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de copie de <Empreinte>");
#endif
}

Empreinte::~Empreinte()
{
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Empreinte>");
#endif
}


