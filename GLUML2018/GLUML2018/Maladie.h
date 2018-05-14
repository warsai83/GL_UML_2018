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
//---  Interface du module <Maladie> (fichier Maladie.h)--------
#if ! defined ( Maladie_H )
#define Maladie_H

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include syst�me
#pragma once
#include <vector>
#include <string>
//--------------------------------------------------- Interfaces utilis�es
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


class Maladie
{
	//------------------------------------------------- Surcharge d'op�rateurs

	//////////////////////////////////////////////////////////////////  PUBLIC
public:
	//---------------------------------------------------- Fonctions publiques
	Maladie();
	~Maladie();
	void AjouterEmpreinte(Empreinte emp);
	string toString();
	string getName()const;
	vector <Empreinte> getListeEmpreintes() const;

	////////////////////////////////////////////////////////////////// PRIVATE
private:
	//------------------------------------------------------ Attributs private
	string Name;
	vector <Empreinte> ListeEmpreintes;
};
#endif

bool operator==(Maladie const &, Maladie const &);