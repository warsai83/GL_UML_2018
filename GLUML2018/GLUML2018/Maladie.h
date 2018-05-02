/*************************************************************************
Maladie  -  description
Classe représentant une maladie connue, elle possède en attribut les
empreintes lui correspondant
-------------------
début                :	02-05-2018
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
//-------------------------------------------------------- Include système
#pragma once
#include <list>
#include <string>
//--------------------------------------------------- Interfaces utilisées
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


class Maladie
{
	//------------------------------------------------- Surcharge d'opérateurs
	bool operator==(Maladie const &, Maladie const &);

	//////////////////////////////////////////////////////////////////  PUBLIC
public:
	//---------------------------------------------------- Fonctions publiques
	Maladie();
	~Maladie();
	void AjouterEmpreinte(Empreinte emp);
	string toString();
	string getName()const;

	////////////////////////////////////////////////////////////////// PRIVATE
private:
	//------------------------------------------------------ Attributs private
	string Name;
	list <Empreinte> ListeEmpreintes;
};
#endif
