/*************************************************************************
                           Lecture -  description
    Classe permettant de lire un fichier log d'un serveur apache
    et d'en extraire les informations contenues dans chaque requêtes
    afin de pouvoir les exploiter avec l'outil Analog.
                             -------------------
    début                : 07-02-2018
    copyright            : (C) 2018 par Halunka Matthieu, Augustin Bodet
    e-mail               : matthieu.halunka@insa-lyon.fr
                           augustin.bodet@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Generateur> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "Formateur.h"
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
void Lecture::Charger(){
    if (LecturePossible){
        string ligne;
        getline(IfFichier,ligne);
        if (IfFichier.eof()){
            LecturePossible=false;
            IfFichier.close();
            return;
        }
        Decoupeur->Decouper(ligne);
        Indice = Indice +1;
#ifdef DEBUG_LECTURE
        cout <<"Ligne numéro "<< Indice << endl << ligne << endl;
#endif
    }
}//Fin de Charger

Lecture::Lecture(const Lecture & uneLecture) : IfFichier(uneLecture.nomFichier, ios::in) {
// Algorithme :
//  Usage Interdit !
//  Copie les attributs copiables et tente d'ouvrir un flux de lecture identique.
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
    nomFichier=uneLecture.nomFichier;
    Indice = 0;

    Decoupeur=new Formateur();
    Decoupeur->IP=uneLecture.Decoupeur->IP;
    Decoupeur->userLog=uneLecture.Decoupeur->userLog;
    Decoupeur->authUser=uneLecture.Decoupeur->authUser;
    Decoupeur->time=uneLecture.Decoupeur->time;
    Decoupeur->typeRequest=uneLecture.Decoupeur->typeRequest;
    Decoupeur->target=uneLecture.Decoupeur->target;
    Decoupeur->httpEnd=uneLecture.Decoupeur->httpEnd;
    Decoupeur->code=uneLecture.Decoupeur->code;
    Decoupeur->length=uneLecture.Decoupeur->length;
    Decoupeur->referer=uneLecture.Decoupeur->referer;
    Decoupeur->idNav=uneLecture.Decoupeur->idNav;

    //Remise de l'ifstream à la même position
    //int pos=(uneLecture.IfFichier).tellg();
    //IfFichier.seekg(pos);
    if (!uneLecture.LecturePossible||IfFichier.fail())
    {
        LecturePossible=false;
        cerr<<"Fichier introuable ou impossible à ouvrir : "<<nomFichier<<endl;
        IfFichier.close();
    }else
    {
        LecturePossible=true;
    }
    Indice=uneLecture.Indice;
}//----- Fin de Lecture (constructeur de copie)

Lecture::Lecture(string fichier) : IfFichier(fichier, ios::in) {
// Algorithme :
//  Crée l'ifstream associé au fichier à lire.
//  Regarde si la lecture est possible, si non, on renvoie une
//  erreur sur le terminal et on empêche la lecture.
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
    nomFichier=fichier;
    Indice = 0;
    Decoupeur=new Formateur();
    if (IfFichier.fail())
    {
        LecturePossible=false;
        cerr<<"Fichier introuable ou impossible à ouvrir : "<<nomFichier<<endl;
        IfFichier.close();
    }else
    {
        LecturePossible=true;
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

