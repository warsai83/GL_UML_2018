/*************************************************************************
						Generateur  -  description
Classe permettant d'�crire, dans un fichier, le r�sultat de l'analyse
, dans le fichier voulu, du patient.
                            -------------------
d�but                : 23-05-2018
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
// R�le de la classe <Generateur>
//  Classe permettant de cr�er un fichier dont le contenu respectera
//  le format des maladies et des emprintes. 
//  Cette classe permettra donc d'�crire les resultats issus 
//  de la partie traitement de l'application Malad'IF.
//------------------------------------------------------------------------

class Generateur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	// void EcrireMaladie (const Maladie & maladie);
	// Mode d'emploi :
	//  Permet d'�crire au sein du fichier, l'ensemble
	//  des empreintes consitituant la maladie
	// Contrat :
	//  L'�criture au sein du fichier devra �tre possible.
	void EcrireMaladie(const Maladie & maladie);

	// void EcrireEmpreinte (Empreinte & empreinte);
	// Mode d'emploi :
	//  Permet d'�crire au sein du fichier, une empreinte
	//	dans un format ad�quat.
	// Contrat :
	//  L'�criture au sein du fichier devra �tre possible.
	void EcrireEmpreinte(Empreinte & empreinte);

	//-------------------------------------------- Constructeurs - destructeur
	Generateur(const Generateur & unGenerateur);
	// Mode d'emploi (constructeur de copie) :
	//  Appel interdit puisqu'on ne veut pas que deux instances puissent
	//  �crire dans le m�me fichier vis � vis de la coh�rence de l'ensemble.
	// Contrat :
	//  Aucun

	Generateur(string fichier);
	// Mode d'emploi :
	//  Permet de cr�er un fichier au format ad�quat vierge ayant
	//  pour nom le string fichier.
	// Contrat :
	//  L'utilisateur doit disposer des droits de modification et
	//  d'�criture au sein du r�pertoire d'ex�cution de l'application.
	//  Le nom du fichier doit contenir de pr�f�rence une extension
	//  du type dot.

	virtual ~Generateur();
	// Mode d'emploi :
	//  Permet de cl�turer l'�criture du fichier en ajoutant les
	//  �l�ments n�cessaires pour respecter le format ad�quat.
	// Contrat :
	//  Aucun

	//----------------------------------------------------- Attributs publiques
	bool EcriturePossible;

private:
	//----------------------------------------------------- Attributs priv�s
	string nomFichier;
	ofstream ecriture;
};
#endif // GENERATEUR_H
