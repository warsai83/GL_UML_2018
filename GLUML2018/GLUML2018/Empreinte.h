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

//----- Interface du module <Empreinte> (fichier Empreinte.h) -------------
#if ! defined ( Empreinte_H )
#define Empreinte_H


/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#pragma once
#include <string>
#include <set>
//--------------------------------------------------- Interfaces utilisées
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

