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
#include <cstdlib>
#include <cmath>

//------------------------------------------------------ Include personnel
#include "Gestion.h"
#include "Lecture.h"

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
		for (std::vector<string>::iterator j = i->getDisease().begin(); j != i->getDisease().end(); j++) {
			setMaladie.insert(*j);
		}
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

set<string> Gestion::AnalyseEmpreinte(vector<Empreinte>& references, string path) {
	Empreinte e = LectureBase(path).front;
	set<string> setMaladies;
	for (std::vector<Empreinte>::iterator i = references.begin(); i != references.end(); i++) {
		//TODO
		double ecartMoyenne = (abs(e.A1 - i->A1)+ abs(e.A2 - i->A2)+ abs(e.A3 - i->A3)+ abs(e.A4 - i->A4)+ abs(e.AZ51 - i->AZ51))/5;
		double ecartType = sqrt((pow(abs(e.A1 - i->A1)-ecartMoyenne,2) + pow(abs(e.A2 - i->A2) - ecartMoyenne, 2) + 
			pow(abs(e.A3 - i->A3) - ecartMoyenne, 2) + pow(abs(e.A4 - i->A4) - ecartMoyenne, 2) + pow(abs(e.AZ51 - i->AZ51) - ecartMoyenne, 2)) / 5);
		if (ecartMoyenne < 10 && ecartType < 3) {
			for (std::vector<string>::iterator j = i->getDisease().begin(); j != i->getDisease().end(); j++) {
				setMaladies.insert(*j);
			}
		}
	}
	return setMaladies;
}

vector<Empreinte> Gestion::LectureBase(string path) {
	Lecture l (path);
	vector<Empreinte> listeEmpreintes;
	vector<vector<string>> empreintes = l.Charger();
	for (std::vector<vector<string>>::iterator i = empreintes.begin(); i != empreintes.end(); i++) {
		listeEmpreintes.push_back(stringToEmpreinte(*i));
	}
	return listeEmpreintes;
}


Empreinte Gestion::stringToEmpreinte(vector<string> attributes) {
	vector<string> maladies;
	if (attributes.size > 6) {
		for (std::vector<string>::iterator i = attributes.begin()+6; i != attributes.end(); i++) {
			maladies.push_back(*i);
		}
	}
	return Empreinte(stoi(attributes[0]), stod(attributes[1]), stod(attributes[2]), stod(attributes[3]), stod(attributes[4]), stod(attributes[5]), maladies);
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


