/*************************************************************************
                           Lecture -  description
    Classe permettant de lire un fichier contenant des empreintes
    et d'en extraire les informations contenues dans chaque requêtes
    afin de pouvoir les exploiter avec l'outil Malad'IF.
                             -------------------
    début                : 07-06-2018
    copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu,
    									Moureau Mathilde, Occelli William
    e-mail               : stanley.cheah@insa-lyon.fr
						   matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "../Vue/Console.h"
//----------------------------------------------------------------- PUBLIC
extern Console* c;

//----------------------------------------------------- Méthodes publiques


vector<vector<string>> Lecture::Charger()
{
	string ligne;
	while(getline(IfFichier,ligne))
	{
		Decoupeur->Decouper(ligne);
		Indice = Indice +1;
	
	/* //AFFICHAGE DU GROS TABLEAU
	for(vector<string> vLigne:tabEmp)
	{
		//vector<string> vLigne = tabEmp[i];
		for(string s: vLigne) {
			cout << s << endl;
		}	
	} */
	
	/*vector<string> vLigne = tabEmp[0];
	cout <<vLigne[0]<<endl;
	vector<string> vLigne1 = tabEmp[1];
	cout <<vLigne1[0]<<endl;*/

	/*
	cout <<&tabEmp[0][0]<<endl;
	cout <<&tabEmp[1][2]<<endl;*/
	//cout <<"Ligne numéro "<< Indice << endl << ligne << endl;
    	}
    	return Decoupeur->tabEmp;
}//Fin de Charger


Lecture::Lecture(string fichier) : IfFichier(fichier, ios::in) {
	// Algorithme :
	//  Crée l'ifstream associé au fichier à lire.
	//  Regarde si la lecture est possible, si non, on renvoie une
	//  erreur sur le terminal et on empêche la lecture.
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Lecture>");
#endif
	nomFichier = fichier;
	Indice = 0;
	Decoupeur = new Formateur();
	
	if (IfFichier.fail())
	{
		LecturePossible = false;
		c->afficherErreur("Fichier introuvable ou impossible à ouvrir : "+nomFichier);
		IfFichier.close();
	}
	else
	{
		LecturePossible = true;
	}
}//----- Fin de Lecture


Lecture::~Lecture() {
	// Algorithme :
	//  On supprime l'objet Decoupeur.
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Lecture>");
#endif
	delete Decoupeur;
}//----- Fin de ~Lecture
