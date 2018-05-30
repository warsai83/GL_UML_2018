/*************************************************************************
Main -  description
test méthode lecture
-------------------
début                : 02-05-2018
copyright            : (C) 2018 par Cheah Stanley, Halunka Matthieu, Moureau Mathilde, Occelli William

e-mail               : stanley.cheah@insa-lyon.fr
						matthieu.halunka@insa-lyon.fr
						mathilde.moureau@insa-lyon.fr
						william.occelli@insa-lyon.fr
*************************************************************************/

using namespace std;

#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include "Console.h"
#include "Lecture.h"
#include "Gestion.h"
#include "Empreinte.h"


int main()
{

	//TEST Gestion Lecture

	vector<Empreinte> ListeEmpreinte = Gestion.LectureBase("empreinte_texte.txt");
	cout << Gestion.AfficherEmpreinte(ListeEmpreinte);

	/*Lecture * maLecture = new Lecture("empreinte_texte.txt");
	maLecture->Charger();
	int a;
	cin >> a;*/

	//TEST Console.cpp
	/*Console* c = new Console();
	c->afficherMessage("Ceci est un message");
	c->afficherErreur("Ceci est une erreur");
	c->afficherDanger("Ceci est un avertissement");
	string s = c->lireChaine();
	int i = c->lireEntier();
	cout << s << endl;
	cout << i << endl;*/
	return 0;
}
