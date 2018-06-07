/*************************************************************************
                           Formateur -  description
    Classe permettant de lire un fichier log d'un serveur apache
    et d'en extraire les informations contenues dans chaque requêtes
    afin de pouvoir les exploiter avec l'outil Analog.
                             -------------------
    début                : 02-05-2018
    copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu,
                                        Moureau Mathilde, Occelli William
    e-mail               : stanley.cheah@insa-lyon.fr
						   matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Formateur> (fichier Formateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Formateur.h"
#include "Console.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
extern Console* c;

//----------------------------------------------------- Méthodes publiques
// void Formateur::Decouper(string ligneLue="")
// Algorithme :
//      Décompose la trame obtenue en éléments simples
//      puis formate certains éléments pour les rendre exploitables
//      par la classe Analog.
void Formateur::Decouper(string ligneLue="") {
	if (ligneLue == "") {
		return;
	}
	string temp;
	stringstream ss(ligneLue);
	listeAttributs v = *(new vector<string>());
	getline(ss, NoID, ';');
	getline(ss, A1, ';');
	getline(ss, A2, ';');
	getline(ss, A3, ';');
	getline(ss, A4, ';');

	v.push_back(NoID);
	v.push_back(A1);
	v.push_back(A2);
	v.push_back(A3);
	v.push_back(A4);
	tabEmp.push_back(v);

	/*cout << "empreinte brute --------------------------------" << endl;
    	cout << NoID << endl;
	cout << A1 << endl;
	cout << A2 << endl;
	cout << A3 << endl;
	cout << A4 << endl;
	cout << AZ51<< endl;
	cout << "vecteurGen----------------------------------------------" << endl;*/
	//delete(v); A FAIRE PLUS TARD
	//return NULL;

}//Fin de Decouper

//-------------------------------------------- Constructeurs - destructeur
Formateur::Formateur ( const Formateur & unFormateur )
// Algorithme :
//      Copie la valeur de chaque attributs dans le nouvel objet
{
#ifdef MAP 
    cout << "Appel au constructeur de copie de <Formateur>" << endl;
#endif
    	NoID=unFormateur.NoID;
   	A1=unFormateur.A1;
    	A2=unFormateur.A2;
    	A3=unFormateur.A3;
    	A4=unFormateur.A4;
} //----- Fin de Formateur (constructeur de copie)


Formateur::Formateur ()
// Algorithme :
//      Initialise les attributs de notre objet
{
#ifdef MAP
    c->afficherMessage("Appel au constructeur de <Formateur>");
#endif
	
	NoID="";
	A1="";
	A2="";
	A3="";
	A4="";
} //----- Fin de Formateur


Formateur::~Formateur ( )
// Algorithme :
//      Aucun
{
#ifdef MAP
    c->afficherMessage("Appel au destructeur de <Formateur>");
#endif
} //----- Fin de ~Formateur
