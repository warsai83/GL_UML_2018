/*************************************************************************
Gestion  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Gestion> (fichier Gestion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Gestion.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Gestion::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Gestion::AfficherEmpreinte(vector<Empreinte> listeEmpreinte) {
	string empreintes = "";
	for (std::vector<Empreinte>::iterator i = listeEmpreinte.begin(); i != listeEmpreinte.end(); i++) {
		empreintes.append(i->toString + "\r\n");
	}
	return empreintes;
}
set<Maladie> Gestion::GetListeMaladie(vector<Empreinte> listeEmpreinte) {
	std::set<Maladie> setMaladie;
	for (std::vector<Empreinte>::iterator i = listeEmpreinte.begin(); i != listeEmpreinte.end(); i++) {
		setMaladie.insert(i->getDisease());
	}
}
vector<Empreinte> Gestion::GetDetail(set<Maladie> setMaladie, string nomMaladie) {
	for (std::set<Maladie>::iterator i = setMaladie.begin(); i != setMaladie.end(); i++) {
		if (i->getName() == nomMaladie) {
			return i->getListeEmpreintes();
		}
	}
	vector<Empreinte> ListeEmpreintes;
	return ListeEmpreintes;
}
set<Maladie> Gestion::analyseEmpreinte(vector<Empreinte> references, Empreinte e ) {
	set<Maladie> setMaladies;
	for (std::vector<Empreinte>::iterator i = references.begin(); i != references.end(); i++) {
		//TODO
		if (true) {
			setMaladies.insert(i->getDisease());
		}
	}
	return setMaladies;
}

//-------------------------------------------- Constructeurs - destructeur

Gestion::Gestion()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Gestion>" << endl;
#endif
} //----- Fin de Gestion


Gestion::~Gestion()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Gestion>" << endl;
#endif
} //----- Fin de ~Gestion


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées


