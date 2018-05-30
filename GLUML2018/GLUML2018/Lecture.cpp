/*************************************************************************
                           Formateur -  description
    Classe permettant de lire un fichier log d'un serveur apache
    et d'en extraire les informations contenues dans chaque requêtes
    afin de pouvoir les exploiter avec l'outil Analog.
                             -------------------
    début                : 02-05-2018
    copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu, Moureau Mathilde, Occelli William 
    e-mail               : stanley.cheah@insa-lyon.fr
						   matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Generateur> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Lecture.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


vector<vector<string>> Lecture::Charger()
{
	string ligne;
	while(getline(IfFichier,ligne))
	{
	tabEmp=Decoupeur->Decouper(ligne);
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
    	return tabEmp;
}//Fin de Charger


Lecture::Lecture(string fichier) : IfFichier(fichier, ios::in) {
	// Algorithme :
	//  Crée l'ifstream associé au fichier à lire.
	//  Regarde si la lecture est possible, si non, on renvoie une
	//  erreur sur le terminal et on empêche la lecture.
#ifdef MAP
	cout << "Appel au constructeur de <Lecture>" << endl;
#endif
	nomFichier = fichier;
	Indice = 0;
	cout << "Appel au constructeur de <Lecture>" << endl;
	Decoupeur = new Formateur();
	cout << "Appel Decoupeur fini" << endl;
	
	if (IfFichier.fail())
	{
		LecturePossible = false;
		cerr << "Fichier introuvable ou impossible à ouvrir : " << nomFichier << endl;
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
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
	delete Decoupeur;
}//----- Fin de ~Lecture
