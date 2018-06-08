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
void Gestion::GetListeMaladie(vector<Maladie>& listeMaladie,std::set<string>& setMaladie) {
	for (std::vector<Maladie>::iterator i = listeMaladie.begin(); i != listeMaladie.end(); i++) {
			setMaladie.insert(i->getName());
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
	if(l.LecturePossible)
	{
        vector<vector<string>> empreintes = l.Charger();
        for (std::vector<vector<string>>::iterator i = empreintes.begin(); i != empreintes.end(); i++) {
        	Empreinte test=stringToEmpreinte(*i);
        	if(test.Disease!="ERREUR") {
				listeEmpreintes.push_back(stringToEmpreinte(*i));
			}
			else {
				c->afficherErreur("Erreur d'empreinte dans le fichier");
				vector<Empreinte> listeFausse;
				return listeFausse;
        	}
        }
    }
    return listeEmpreintes;
}

void Gestion::ChargerListeMaladies(vector<Empreinte>& listeEmpreinte, vector<Maladie>& listeMaladie) {
	if (listeMaladie.empty()) {
		c->afficherErreur("Warning, la base ne contient pas de maladie référencée");
		return;
	}
	for (std::vector<Empreinte>::iterator i = listeEmpreinte.begin(); i != listeEmpreinte.end(); i++) {
		if (i->getDisease() != "") {
			if (listeMaladie.empty()) {
				Maladie nouvelleMaladie = *(new Maladie(i->getDisease()));
				nouvelleMaladie.AjouterEmpreinte(*i);
				listeMaladie.push_back(nouvelleMaladie);
			}
			else {
				bool maladieTrouve = false;
				for (std::vector<Maladie>::iterator im = listeMaladie.begin(); im != listeMaladie.end(); im++) {
					if (im->getName() == i->getDisease()) {
						im->AjouterEmpreinte(*i);
						maladieTrouve = true;
						break;
					}
				}
				if (!maladieTrouve) {
					Maladie nouvelleMaladie = *(new Maladie(i->getDisease()));
					nouvelleMaladie.AjouterEmpreinte(*i);
					listeMaladie.push_back(nouvelleMaladie);
				}
			}
		}
	}
}

Empreinte Gestion::stringToEmpreinte(vector<string>& attributes) {
	try{
		Empreinte e = Empreinte(stoi(attributes[0]), attributes[1], stod(attributes[2]), stod(attributes[3]), stod(attributes[4]), attributes[5]);
		return e;
	}
	catch(invalid_argument i)
	{
		Empreinte eVide = Empreinte(0,"ERREUR",0,0,0,"ERREUR");
		return eVide;
	}

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


