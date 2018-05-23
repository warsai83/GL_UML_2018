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

//---------- Interface de la classe <Formateur> (fichier Formateur.h) ----------------
#if ! defined ( FORMATEUR_H )
#define FORMATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
//------------------------------------------------------------------------
// Rôle de la classe <Formateur>
//      Permet de découper les requêtes provenant du log du serveur apache
//      afin de les stocker dans un ensemble d'attributs connus
//      et de les rendres ainsi lisibles pour la classe Analog.
//------------------------------------------------------------------------

class Formateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // void Decouper(string ligneLue);
    // Mode d'emploi :
    //     Cette méthode découpe une requête/ligne de fichier de log
    //     de serveur Apache pour ensuite stocker les informations
    //     obtenues dans les attributs de notre objet.
    // Contrat :
    //     La requête proposée en entrée sera supposé comme étant
    //     correctement formée et entière.
    vector<vector<string>> Decouper(string ligneLue);

//-------------------------------------------- Constructeurs - destructeur
    Formateur ( const Formateur & unFormateur );
    // Mode d'emploi (constructeur de copie) :
    //      Copie l'ensemble des attributs de l'objet
    //      passé par référence.
    // Contrat :
    //      Aucun

    Formateur ();
    // Mode d'emploi :
    //      Crée et d'initialise notre objet.
    // Contrat :
    //      Aucun

    virtual ~Formateur ( );
    // Mode d'emploi :
    //      Détruit l'objet.
    // Contrat :
    //      Aucun

    	string NoID;
	string A1;
	string A2;
	string A3;
	string A4;
	string AZ51;
	vector<vector<string>> tabEmp;

};

//-------------------------------- Autres définitions dépendantes de <Formateur>

#endif // FORMATEUR_H
