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

//---------- Réalisation de la classe <Generateur> (fichier Formateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Formateur.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Formateur::Charger(){
    if (FormateurPossible){
        string ligne;
        getline(IfFichier,ligne);
        if (IfFichier.eof()){
			FormateurPossible=false;
            IfFichier.close();
            return;
        }
        Decoupeur->Decouper(ligne);
        Indice = Indice +1;
#ifdef DEBUG_FORMATEUR
        cout <<"Ligne numéro "<< Indice << endl << ligne << endl;
#endif
    }
}//Fin de Charger

Formateur::Formateur(const Formateur & uneFormateur) : IfFichier(uneFormateur.nomFichier, ios::in) {
// Algorithme :
//  Usage Interdit !
//  Copie les attributs copiables et tente d'ouvrir un flux de Formateur identique.
#ifdef MAP
    cout << "Appel au constructeur de copie de <Formateur>" << endl;
#endif
    nomFichier=uneFormateur.nomFichier;
    Indice = 0;

    Decoupeur=new Formateur();
    Decoupeur->IP=uneFormateur.Decoupeur->IP;
    Decoupeur->userLog=uneFormateur.Decoupeur->userLog;
    Decoupeur->authUser=uneFormateur.Decoupeur->authUser;
    Decoupeur->time=uneFormateur.Decoupeur->time;
    Decoupeur->typeRequest=uneFormateur.Decoupeur->typeRequest;
    Decoupeur->target=uneFormateur.Decoupeur->target;
    Decoupeur->httpEnd=uneFormateur.Decoupeur->httpEnd;
    Decoupeur->code=uneFormateur.Decoupeur->code;
    Decoupeur->length=uneFormateur.Decoupeur->length;
    Decoupeur->referer=uneFormateur.Decoupeur->referer;
    Decoupeur->idNav=uneFormateur.Decoupeur->idNav;

    //Remise de l'ifstream à la même position
    //int pos=(uneFormateur.IfFichier).tellg();
    //IfFichier.seekg(pos);
    if (!uneFormateur.FormateurPossible||IfFichier.fail())
    {
		FormateurPossible=false;
        cerr<<"Fichier introuable ou impossible à ouvrir : "<<nomFichier<<endl;
        IfFichier.close();
    }else
    {
		FormateurPossible=true;
    }
    Indice=uneFormateur.Indice;
}//----- Fin de Formateur (constructeur de copie)

Formateur::Formateur(string fichier) : IfFichier(fichier, ios::in) {
// Algorithme :
//  Crée l'ifstream associé au fichier à lire.
//  Regarde si la Formateur est possible, si non, on renvoie une
//  erreur sur le terminal et on empêche la Formateur.
#ifdef MAP
    cout << "Appel au constructeur de <Formateur>" << endl;
#endif
    nomFichier=fichier;
    Indice = 0;
    Decoupeur=new Formateur();
    if (IfFichier.fail())
    {
		FormateurPossible=false;
        cerr<<"Fichier introuable ou impossible à ouvrir : "<<nomFichier<<endl;
        IfFichier.close();
    }else
    {
		FormateurPossible=true;
    }
}//----- Fin de Formateur

Formateur::~Formateur() {
// Algorithme :
//  On supprime l'objet Decoupeur.
#ifdef MAP
    cout << "Appel au destructeur de <Formateur>" << endl;
#endif
    delete Decoupeur;
}//----- Fin de ~Formateur

