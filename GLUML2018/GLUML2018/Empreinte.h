#pragma once
#include <string>
#include "Maladie.h"

using namespace std;

class Empreinte
{
public:
	Empreinte();
	~Empreinte();
	Empreinte(int, double, double, double, double, double, Maladie);

	string toString();

private:
	int NoID;
	double A1, A2, A3, A4, AZ51;
	Maladie Disease; 
};

