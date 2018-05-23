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

//---------- Réalisation de la classe <Formateur> (fichier Formateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Formateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// void Formateur::Decouper(string ligneLue="")
// Algorithme :
//      Décompose la trame obtenue en éléments simples
//      puis formate certains éléments pour les rendre exploitables
//      par la classe Analog.
void Formateur::Decouper(string ligneLue="") {
	cout <<"decoupeur de form"<< endl;
    if (ligneLue=="")
    {
	cout <<"if decoup vide"<< endl;
        return;
    }
	cout <<"sep"<< endl;
    istringstream separateur(ligneLue);

    string time1;
    string time2;
    string time3;
    string request1;
    string request2;
    string request3;
    string idNav1;

    separateur >> IP >> userLog >> authUser
               >> time1 >> time2  >> request1 >> request2 >> request3
               >> code >> length >> referer
               >> idNav1;

    idNav1.erase(0, 1);
    idNav = idNav1;
    // on gère le cas ou l'idNav est de la forme "idNav" et non "idNav blabla"
    if (idNav1[idNav1.size()-1]=='"') {
	cout <<"if decoup"<< endl;
        idNav.erase(idNav1.size()-1, 1);
    } else {
	cout <<"else decoup"<< endl;
        separateur >> idNav1;
        while (idNav1[idNav1.size()-1]!='"'){
		cout <<"while"<< endl;
            idNav = idNav + ' ' + idNav1;
            separateur >> idNav1;
        }
cout <<"fin while"<< endl;
        idNav1.erase(idNav1.size()-1, 1);
        idNav = idNav + ' ' + idNav1;
    }
cout <<"fin meth"<< endl;
    time = time1 + ' ' + time2; // on enleve les caractères '[' et ']'
    time.erase(0, 1);
    time.erase(time.size()-1, 1);

    // on efface les caractères '"'
    referer.erase(0, 1);
    referer.erase(referer.size()-1, 1);

    request1.erase(0, 1); // efface "
    request3.erase(request3.size()-1, 1);

    typeRequest = request1;
    target = request2;
    httpEnd = request3;

#ifdef DEBUG_FORMATEUR
    cout << IP << endl << userLog <<endl<< authUser << endl
         << time << endl << typeRequest << endl << target << endl
         << httpEnd << endl << code << endl << length << endl << referer << endl
         << idNav << endl;
#endif

    return;
}//Fin de Decouper

//-------------------------------------------- Constructeurs - destructeur
Formateur::Formateur ( const Formateur & unFormateur )
// Algorithme :
//      Copie la valeur de chaque attributs dans le nouvel objet
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Formateur>" << endl;
#endif
    IP=unFormateur.IP;
    userLog=unFormateur.userLog;
    authUser=unFormateur.authUser;
    time=unFormateur.time;
    typeRequest=unFormateur.typeRequest;
    target=unFormateur.target;
    httpEnd=unFormateur.httpEnd;
    code=unFormateur.code;
    length=unFormateur.length;
    referer=unFormateur.referer;
    idNav=unFormateur.idNav;
} //----- Fin de Formateur (constructeur de copie)


Formateur::Formateur ()
// Algorithme :
//      Initialise les attributs de notre objet
{
#ifdef MAP
    cout << "Appel au constructeur de <Formateur>" << endl;
#endif
    IP="";
    userLog="";
    authUser="";
    time="";
    typeRequest="";
    target="";
    httpEnd="";
    code="";
    length="";
    referer="";
    idNav="";
} //----- Fin de Formateur


Formateur::~Formateur ( )
// Algorithme :
//      Aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Formateur>" << endl;
#endif
} //----- Fin de ~Formateur
