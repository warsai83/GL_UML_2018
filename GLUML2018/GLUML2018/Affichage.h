/*************************************************************************
                        Affichage  -  description
            Classe gérant les interactions avec l'utilisateur
                            -------------------
début                : 02-05-2018
copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
									Stanley Cheah, William Occelli
e-mail               :  matthieu.halunka@insa-lyon.fr
						mathilde.moureau@insa-lyon.fr
						stanley.cheah@insa-lyon.fr
						william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Affichage> (fichier Affichage.h) -------------------
#if ! defined ( Affichage_H )
#define Affichage_H

#pragma once
//------------------------------------------------------------------------
// Rôle du module <Affichage>
//	Permet de gérer les interactions avec l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Console.h"
#include "Maladie.h"
#include "Gestion.h"
using namespace std;
//------------------------------------------------------------- Constantes
Console* c = new Console();
//------------------------------------------------------------------ Types
set<Maladie> SETMALADIES;
vector<Empreinte> EMPREINTES;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
class Affichage
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	//static string* SeparerString(string s, const char separateur = ' ');
	// Mode d'emploi :
	// Contrat :
	//  Aucun

	Affichage();
	// Mode d'emploi (constructeur de copie) :
	//  Usage interdit !
	// Contrat :
	//  Aucun
	~Affichage();
	//----------------------------------------------------- Attributs publiques

	//----------------------------------------------------- Attributs protégés
};


#endif // Affichage_H

