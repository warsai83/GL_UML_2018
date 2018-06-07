/*************************************************************************
                        Gestion  - description

    Classe réalisant l'ensemble des services client de l'application.

                          -------------------
début                :	07-06-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
                                     Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
                        mathilde.moureau@insa-lyon.fr
                        stanley.cheah@insa-lyon.fr
                        william.occelli@insa-lyon.fr
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
#include "Console.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
extern Console* c;

//----------------------------------------------------- Méthodes publiques
// type Gestion::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Gestion::AfficherEmpreinte(vector<Empreinte>& listeEmpreinte) {
	string empreintes = "";
	for (std::vector<Empreinte>::iterator i = listeEmpreinte.begin(); i != listeEmpreinte.end(); i++) {
		empreintes.append(i->toString() + "\r\n");
	}
	return empreintes;
}
set<string>& Gestion::GetListeMaladie(vector<Empreinte>& listeEmpreinte,std::set<string>& setMaladie) {
	for (std::vector<Empreinte>::iterator i = listeEmpreinte.begin(); i != listeEmpreinte.end(); i++) {
			setMaladie.insert(i->Disease);
	}
}
vector<Empreinte> Gestion::GetDetail(vector<Maladie>& setMaladie, string nomMaladie) {
	for (std::vector<Maladie>::iterator i = setMaladie.begin(); i != setMaladie.end(); i++) {
		if (i->getName() == nomMaladie) {
			return i->getListeEmpreintes();
		}
	}
	return vector<Empreinte>();
}

vector<Empreinte> Gestion::AnalyseEmpreinte(vector<Empreinte>& references, string path) {
	vector <Empreinte> e = LectureBase(path);
	//cout << e.toString();
	string maladieSupposee;
	double ecartMoyenneMin = 10000, ecartTypeMin = 10000;
	for (std::vector<Empreinte>::iterator j = e.begin(); j != e.end(); j++) {
		for (std::vector<Empreinte>::iterator i = references.begin(); i != references.end(); i++) {
			//TODO
			double ecartMoyenne = (abs(j->A2 - i->A2) + abs(j->A3 - i->A3) + abs(j->A4 - i->A4)) / 3.0;
				/*double ecartType = sqrt((pow(abs(j->A2 - i->A2) - ecartMoyenne, 2) +
					pow(abs(j->A3 - i->A3) - ecartMoyenne, 2) + pow(abs(j->A4 - i->A4) - ecartMoyenne, 2) - ecartMoyenne, 2) / 4.0);*/
				if (ecartMoyenne < ecartMoyenneMin && i->Disease != "" ) {
					ecartMoyenneMin = ecartMoyenne;
					//ecartTypeMin = ecartType;
					maladieSupposee = i->Disease; 
				}
		}
		if ( ecartMoyenneMin < 10) {
			j->setDisease(maladieSupposee);
		}
		else {
			j->setDisease("None");
		}
		ecartMoyenneMin = 10000, ecartTypeMin = 10000;
	}
	return e;
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


Empreinte Gestion::stringToEmpreinte(vector<string>& attributes) {
	return Empreinte(stoi(attributes[0]), attributes[1], stod(attributes[2]), stod(attributes[3]), stod(attributes[4]), attributes[5]);
}

//-------------------------------------------- Constructeurs - destructeur

Gestion::Gestion()
// Algorithme :
//
{
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Gestion>");
#endif
} //----- Fin de Gestion


Gestion::~Gestion()
// Algorithme :
//
{
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Gestion>");
#endif
} //----- Fin de ~Gestion


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées


