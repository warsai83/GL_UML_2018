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
private: 
	string Name;
	list <Empreinte> ListeEmpreintes; 
};

