/*************************************************************************
                           Lecture -  description
    Classe permettant de lire un fichier (log d'un serveur apache)
    et d'invoquer un objet du type Formateur pour pouvoir extraire
    les informations contenues dans chaque requêtes (/lignes).
    Cela dans le but de pouvoir les exploiter avec l'outil Analog.
                             -------------------
    début                : 07-02-2018
    copyright            : (C) 2018 par Halunka Matthieu, Augustin Bodet
    e-mail               : matthieu.halunka@insa-lyon.fr
                           augustin.bodet@insa-lyon.fr
*************************************************************************/
//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------

#if ! defined ( LECTURE_H )
#define LECTURE_H

using namespace std;
#include <iostream>
#include <string>
#include <fstream>


//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//  Classe permettant d'ouvrir le fichier souhaité et se charge de le lire
//  ligne par ligne à l'aide de la méthode Charger().
//  L'appel de cette méthode conduit à transmettre la ligne lue
//  à un objet du type Formateur afin d'extraire et
//  de stocker les informations de la ligne lue.
//------------------------------------------------------------------------

class Lecture {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    void Charger();

//-------------------------------------------- Constructeurs - destructeur


    Lecture (string fichier);
    // Mode d'emploi :
    //  Permet de créer l'objet et d'initialiser ses attributs.
    //  Procède à l'ouverture du fichier pour le rendre prêt à la lecture.
    // Contrat :
    //  Le fichier à lire doit lisible, doit respecter un format
    //  compréhensible et cohérent pour la classe Formateur.
    //  Le fichier doit être correctement formée.

    virtual ~Lecture();
    // Mode d'emploi :
    //  Permet de fermer le flux de lecture et de détruire l'objet Decoupeur.
    // Contrat :
    //  Aucun

//----------------------------------------------------- Attributs publiques
    bool LecturePossible;
    int Indice;
    ifstream IfFichier;
    Formateur* Decoupeur;
//----------------------------------------------------- Attributs protégés
protected :
    string nomFichier;
};

#endif // LECTURE_H