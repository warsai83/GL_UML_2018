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
#include "Lecture.h"


int main()
{
	Lecture * maLecture = new Lecture("empreinte_texte.txt");
	maLecture->Charger();
	int a;
	cin >> a;
}
