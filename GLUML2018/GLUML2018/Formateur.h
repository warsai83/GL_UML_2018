/*************************************************************************
                           Formateur -  description
    Transforme string en empreinte
                             -------------------
    début                : 02-05-2018
    copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu, Moureau Mathilde, Occelli William 

    e-mail               : stanley.cheah@insa-lyon.fr
						   matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   william.occelli@insa-lyon.fr

*************************************************************************/
//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------

#if ! defined ( Formateur_H )
#define FORMATEUR_H

using namespace std;
#include <iostream>
#include <string>
#include <fstream>

//------------------------------------------------------------------------
// Rôle de la classe <Formateur>

//------------------------------------------------------------------------

class Formateur {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    void Charger();

//-------------------------------------------- Constructeurs - destructeur

    Formateur (const Formateur & uneFormateur);

    Formateur (string fichier);

    virtual ~Formateur();

//----------------------------------------------------- Attributs publiques
    bool FormateurPossible;
    int Indice;
    ifstream IfFichier;
    Formateur* Decoupeur;
//----------------------------------------------------- Attributs protégés
protected :
    string nomFichier;
};

#endif // FORMATEUR_H