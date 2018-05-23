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
#include "Console.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

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
		

		//ecriture << << endl;
#ifdef DEBUG
		cout << "Ecriture du noeud " << id << " de nom " << url << endl;
#endif
	}
	return;
}//----- Fin de EcrireNoeud

 // void Generateur::EcrireEmpreinte(const Empreinte & empreinte)
 // Algorithme :
 //              Ecrit l'empreinte corresondante si
 //              le fichier est accessible en écriture.
void Generateur::EcrireEmpreinte(const Empreinte & empreinte) {
	if (EcriturePossible)
	{
		//ecriture << "node" << idRef << " -> node" << idCible;
		//ecriture << " [label=" << '"' << occurence << '"' << "];" << endl;
#ifdef DEBUG
		cout << "Ecriture de lien " << idRef << " vers " << idCible << endl;
#endif
	}
	return;
}//----- Fin de EcrireLien

Generateur::Generateur(const Generateur & unGenerateur) :nomFichier(unGenerateur.nomFichier)
// Algorithme :
//  Appel interdit - Copie du nom du fichier.
//                   Impossible d'utiliser le constructeur
//                   de copie de l'ofstream (conduit à sa destruction).
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Generateur>" << endl;
#endif
	EcriturePossible = false;
}//----- Fin de Generateur (constructeur de copie)

Generateur::Generateur(string fichier) :nomFichier(fichier), ecriture(fichier, ofstream::out)
// Algorithme :
//  Initialise les attributs de l'objet et écrit, si c'est possible, l'entête
//  du fichier pour qu'il respecte le format GraphViz.
{
#ifdef MAP
	cout << "Appel au constructeur de <Generateur>" << endl;
#endif
	if (ecriture.fail())
	{
		EcriturePossible = false;
		cerr << "Fichier introuable ou impossible à ouvrir : " << nomFichier << endl;
		ecriture.close();
	}
	else
	{
		EcriturePossible = true;
		ecriture << "digraph {" << endl;
		ecriture << "node [shape=box, color=blue, style=filled]" << endl;
	}

} //----- Fin de Generateur


Generateur::~Generateur()
// Algorithme :
//  Ecrit, si possible, le caractère '}' afin de terminer propement
//  le fichier au format GraphViz.
{
#ifdef MAP
	cout << "Appel au destructeur de <Generateur>" << endl;
#endif
	if (EcriturePossible) {
		ecriture << "}" << endl;
	}
} //----- Fin de ~Generateur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

