#pragma once
#include <list>
#include <string>
#include "Empreinte.h"


class Maladie
{
public:
	Maladie();
	~Maladie();
	void AjouterEmpreinte(Empreinte emp);
	string toString();
	//surcharge d'opérateur
	string getName()const ;
private:
	string Name;
	list <Empreinte> ListeEmpreintes; 
};

bool operator==(Maladie const &, Maladie const &);

