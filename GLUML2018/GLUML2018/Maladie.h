#pragma once
#include <list>
#include "Empreinte.h"

class Maladie
{
public:
	Maladie();
	~Maladie();
	void AjouterEmpreinte(Empreinte emp);
	string toString();
	//surcharge d'opérateur
	bool operator==(Maladie const &M1, Maladie const &M2);
	string getName()const ;
private:
	string Name;
	list <Empreinte> ListeEmpreintes; 
};

