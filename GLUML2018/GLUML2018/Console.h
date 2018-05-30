/*************************************************************************
					Console  -  description
		Classe permettant l'affichage sur la console de visual studio
							-------------------
	début                : 02-05-2018
	copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
										Stanley Cheah, William Occelli
    e-mail               : matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   stanley.cheah@insa-lyon.fr
						   william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Console> (fichier Console.h) -------------------
#if ! defined ( Console_H )
#define Console_H

using namespace std;
//------------------------------------------------------------------------
// Rôle du module <Console>
//	Permet d'utiliser la sortie console pour intérargir avec l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <cstring>
#include <string>

#include <fstream>
#include <sstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
class Console {

#ifdef DEBUG
	// ostream & debug ( ostream & os )
	//ostream & debug(ostream & os);
#endif

	 // ostream & erreur ( ostream & os )
	/*ostream & erreur(ostream & os);

	 // ostream & attention( ostream & os )
	ostream & attention(ostream & os);

	 // ostream & debug ( ostream & os )
	ostream & raz(ostream & os);*/

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

#ifdef DEBUG
	void afficherDebug(string &info);
#endif

	void afficherErreur(const string &err);

	void afficherDanger(const string &danger);

	void afficherMessage(const string &msg);

	int lireEntier();

	string lireChaine();
	//-------------------------------------------- Constructeurs - destructeur

	Console(const Console & uneConsole);
	// Mode d'emploi (constructeur de copie) :
	//  Usage interdit !
	// Contrat :
	//  Aucun

	Console();
	// Mode d'emploi :
	//  Permet de créer l'objet et d'initialiser ses attributs.
	// Contrat :
	//	Aucun

	virtual ~Console();
	// Mode d'emploi :
	//  Permet de détruire l'objet console.
	// Contrat :
	//  Aucun

	//----------------------------------------------------- Attributs publiques

	//----------------------------------------------------- Attributs protégés
protected:
	/*ostream sortieConsole;
	ostream erreurConsole;
	istream entreeConsole;*/
};


#endif // Console_H



