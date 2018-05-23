/*************************************************************************
Empreinte  -  description
Classe repr�sentant l'objet Empreinte qui poss�de les caract�ristiques du
patient en attributs ainsi que la maladie diagnostiqu�e
-------------------
d�but                :	02-05-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
mathilde.moureau@insa-lyon.fr
stanley.cheah@insa-lyon.fr
william.occelli@insa-lyon.fr

*************************************************************************/

//----- Interface du module <Empreinte> (fichier Empreinte.h) -------------
#if ! defined ( Empreinte_H )
#define Empreinte_H


/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#pragma once
#include <string>
#include <set>
//--------------------------------------------------- Interfaces utilis�es
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Empreinte
{
	//////////////////////////////////////////////////////////////////  PUBLIC
public:
	//---------------------------------------------------- Fonctions publiques
	string toString();
	Empreinte();
	Empreinte(int, double, double, double, double, double, vector<string>);
	friend class Gestion;
	~Empreinte();
	vector<string> getDisease() const;

	////////////////////////////////////////////////////////////////// PRIVATE
private:
	//------------------------------------------------------ Attributs private
	int NoID;
	double A1, A2, A3, A4, AZ51;
	vector<string> Disease;
};
#endif

