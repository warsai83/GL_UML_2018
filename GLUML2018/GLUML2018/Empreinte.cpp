/*************************************************************************
Empreinte  -  description
Classe représentant l'objet Empreinte qui possède les caractéristiques du
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

//--- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp)--------

//---------------------------------------------------------------- INCLUDE
#include "Empreinte.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Empreinte::toString()
{
	string s = to_string(NoID) + ";" + to_string(A1) + ";" + to_string(A2) + ";" + to_string(A3) + ";" + to_string(A4) + ";" + to_string(AZ51) + ";" + Disease;
	return s;
}

//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte(int unNoID, double unA1, double unA2, double unA3, double unA4, double unAZ51, Maladie uneDisease) : NoID(unNoID), A1(unA1), A2(unA2), A3(unA3), A4(unA4), AZ51(unAZ51), Disease(uneDisease)
{

}

Empreinte::Empreinte()
{
	Disease = Maladie();
}

Empreinte::~Empreinte()
{
}


