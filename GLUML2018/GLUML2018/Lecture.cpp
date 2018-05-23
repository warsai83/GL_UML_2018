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
// void Lecture::Charger ()
// Algorithme :
//      S'il est possible de lire une ligne du fichier,
//          On lit la ligne, on regarde si on a atteint la fin du fichier
//          Si on atteint la fin du fichier,
//               on rend les lectures suivantes impossibles
//          Fin SI
//          On passe la ligne lue à la méthode Decouper de l'objet Decoupeur.
//          On incrémente l'Indice pour connaître le nombre de lignes lues
//          depuis le début de l'existance de notre objet.
//      Fin SI

/*void Lecture::Charger() {
	vector<string> tabString;
	string ligne;
	while (getline(IfFichier, ligne))
	{
		tabString.push_back(ligne);

		cout << ligne << endl;

	}

	cout << ligne << endl;

	vector<string>::iterator it = tabString.begin();
	cout << "tabString contient:";
	for (it = tabString.begin(); it<tabString.end(); it++)
	{
	cout << ' ' << *it <<endl;
	}
}//Fin de Charger*/

void Lecture::Charger()
{
	cout <<"charger"<< endl;
    	if (LecturePossible)
	{
		cout <<"if1"<< endl;
		string ligne;
		getline(IfFichier,ligne);
		if (IfFichier.eof())
		{
			cout <<"if2"<< endl;
			LecturePossible=false;
		 	IfFichier.close();
		    	return;
        	}
	cout <<"decoupeur"<< endl;
	Decoupeur->Decouper(ligne);
		Indice = Indice +1;
	#ifdef DEBUG_LECTURE
		cout <<"Ligne numéro "<< Indice << endl << ligne << endl;
	#endif
    	}
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
