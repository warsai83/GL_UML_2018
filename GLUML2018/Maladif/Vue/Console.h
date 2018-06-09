/*************************************************************************
					       Console  -  description
                Classe permettant l'affichage sur l'IHM texte
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
class Console {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

#ifdef DEBUG
	// void afficherDebug(const string &info);
	// Mode d'emploi :
	//		Affiche le string passé en paramètre sur cout
	// Contrat :
	//		Aucun
	void afficherDebug(const string &info);
#endif
	// void afficherErreur(const string &err);
	// Mode d'emploi :
	//		Affiche le string passé en paramètre sur cerr
	// Contrat :
	//		Aucun
	void afficherErreur(const string &err);

	// void afficherDanger(const string &danger);
	// Mode d'emploi :
	//		Affiche le string passé en paramètre sur cout
	// Contrat :
	//		Aucun
	void afficherDanger(const string &danger);

	// void afficherMessage(const string &msg);
	// Mode d'emploi :
	//		Affiche le string passé en paramètre sur cout
	// Contrat :
	//		Aucun
	void afficherMessage(const string &msg);

	// void afficherTaille(const size_t &taille);
	// Mode d'emploi :
	//		Affiche le string passé en paramètre sur cout
	// Contrat :
	//		Aucun
	void afficherTaille(const size_t &taille);

	// int lireEntier();
	// Mode d'emploi :
	//		Permet de retourner un entier saisit sur la console
	// Contrat :
	//		Aucun
	int lireEntier();

	// string lireChaine();
	// Mode d'emploi :
	//		Permet de retourner un string saisit sur la console
	//		(Ce dernier sera différent du caractère \r et non-vide)
	// Contrat :
	//		Aucun
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
	static ostream & erreur (ostream & os);
	static ostream & attention (ostream & os);
#ifdef DEBUG
	static ostream & debug (ostream & os);
#endif
	static ostream & raz (ostream & os);
};


#endif // Console_H



