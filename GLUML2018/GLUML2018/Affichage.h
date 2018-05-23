
/*************************************************************************
Affichage  -  description
Classe g�rant les interactions avec l'utilisateur
-------------------
d�but                : 02-05-2018
copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
Stanley Cheah, William Occelli
e-mail               : matthieu.halunka@insa-lyon.fr
mathilde.moureau@insa-lyon.fr
stanley.cheah@insa-lyon.fr
william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Affichage> (fichier Affichage.h) -------------------
#if ! defined ( Affichage_H )
#define Affichage_H

#pragma once
//------------------------------------------------------------------------
// R�le du module <Affichage>
//	Permet de g�rer les interactions avec l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de param�tres );
// Mode d'emploi :
//
// Contrat :
//
class Affichage
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques
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

	//----------------------------------------------------- Attributs prot�g�s
};
#endif // Affichage_H

