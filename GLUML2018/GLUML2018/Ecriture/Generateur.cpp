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

//---------- Réalisation de la classe <Generateur> (fichier Generateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


//------------------------------------------------------ Include personnel
#include "Generateur.h"
#include "../Vue/Console.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
extern Console* c;
//----------------------------------------------------- Méthodes publiques
// void Generateur::EcrireMaladie (const Maladie & maladie)
// Algorithme :
//              Ecrit l'ensemble des empreintes correspondantes
//				dans le fichier si le fichier 
//              est accessible en écriture.
void Generateur::EcrireMaladie(const Maladie & maladie) {
	if (EcriturePossible)
	{
		vector<Empreinte> tabEmpreinte = maladie.getListeEmpreintes();
		vector<Empreinte>::iterator it;
		for (it = tabEmpreinte.begin(); it != tabEmpreinte.end(); ++it)
		{

#ifdef DEBUG
			c->afficherDebug("ECRITURE DE MALADIE "+it->toString());
#endif
			ecriture << it->toString() << endl;
		}
	}
}//----- Fin de EcrireNoeud

 // void Generateur::EcrireEmpreinte(Empreinte & empreinte)
 // Algorithme :
 //              Ecrit l'empreinte corresondante si
 //              le fichier est accessible en écriture.
void Generateur::EcrireEmpreinte(Empreinte & empreinte) {
	if (EcriturePossible)
	{
		ecriture << empreinte.toString() << endl;
#ifdef DEBUG
		c->afficherDebug("ECRITURE DE EMPRINTE "+empreinte.toString());
#endif
	}
}//----- Fin de EcrireLien

Generateur::Generateur(const Generateur & unGenerateur) :nomFichier(unGenerateur.nomFichier)
// Algorithme :
//  Appel interdit - Copie du nom du fichier.
//                   Impossible d'utiliser le constructeur
//                   de copie de l'ofstream (conduit à sa destruction).
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de copie de <Generateur>");
#endif
	EcriturePossible = false;
}//----- Fin de Generateur (constructeur de copie)

Generateur::Generateur(string fichier) :nomFichier(fichier), ecriture(fichier, ofstream::out)
// Algorithme :
//  Initialise les attributs de l'objet et écrit, si c'est possible, l'entête
//  du fichier pour qu'il respecte le format.
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Generateur>");
#endif
	if (ecriture.fail())
	{
		EcriturePossible = false;
		c->afficherErreur("Fichier introuable ou impossible à ouvrir : "+nomFichier);
		ecriture.close();
	}
	else
	{
		EcriturePossible = true;
	}

} //----- Fin de Generateur


Generateur::~Generateur()
// Algorithme :
//  Détruit l'objet et la console d'affichage.
{
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Generateur>");
#endif
} //----- Fin de ~Generateur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

