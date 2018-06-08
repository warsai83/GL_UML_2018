/*************************************************************************
						Generateur  -  description
Classe permettant d'écrire, dans un fichier, le résultat de l'analyse
, dans le fichier voulu, du patient.
                            -------------------
début                : 23-05-2018
copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu,
									Moureau Mathilde, Occelli William
e-mail               :  stanley.cheah@insa-lyon.fr
						matthieu.halunka@insa-lyon.fr
						mathilde.moureau@insa-lyon.fr
						william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Generateur> (fichier Generateur.h) ----------------
#if ! defined ( GENERATEUR_H )
#define GENERATEUR_H
using namespace std;

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "../ObjetsMetiers/Maladie.h"
#include "../ObjetsMetiers/Empreinte.h"
//------------------------------------------------------------------------
// Rôle de la classe <Generateur>
//  Classe permettant de créer un fichier dont le contenu respectera
//  le format des maladies et des emprintes. 
//  Cette classe permettra donc d'écrire les resultats issus 
//  de la partie traitement de l'application Malad'IF.
//------------------------------------------------------------------------

class Generateur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	// void EcrireMaladie (const Maladie & maladie);
	// Mode d'emploi :
	//  Permet d'écrire au sein du fichier, l'ensemble
	//  des empreintes consitituant la maladie
	// Contrat :
	//  L'écriture au sein du fichier devra être possible.
	void EcrireMaladie(const Maladie & maladie);

	// void EcrireEmpreinte (Empreinte & empreinte);
	// Mode d'emploi :
	//  Permet d'écrire au sein du fichier, une empreinte
	//	dans un format adéquat.
	// Contrat :
	//  L'écriture au sein du fichier devra être possible.
	void EcrireEmpreinte(Empreinte & empreinte);

	//-------------------------------------------- Constructeurs - destructeur
	Generateur(const Generateur & unGenerateur);
	// Mode d'emploi (constructeur de copie) :
	//  Appel interdit puisqu'on ne veut pas que deux instances puissent
	//  écrire dans le même fichier vis à vis de la cohérence de l'ensemble.
	// Contrat :
	//  Aucun

	Generateur(string fichier);
	// Mode d'emploi :
	//  Permet de créer un fichier au format adéquat vierge ayant
	//  pour nom le string fichier.
	// Contrat :
	//  L'utilisateur doit disposer des droits de modification et
	//  d'écriture au sein du répertoire d'exécution de l'application.
	//  Le nom du fichier doit contenir de préférence une extension
	//  du type dot.

	virtual ~Generateur();
	// Mode d'emploi :
	//  Permet de clôturer l'écriture du fichier en ajoutant les
	//  éléments nécessaires pour respecter le format adéquat.
	// Contrat :
	//  Aucun

	//----------------------------------------------------- Attributs publiques
	bool EcriturePossible;

private:
	//----------------------------------------------------- Attributs privés
	string nomFichier;
	ofstream ecriture;
};
#endif // GENERATEUR_H
