#pragma once
#include <string>

using namespace std;

class Empreinte
{
public:
	Empreinte();
	~Empreinte();

	string toString();

private:
	int NoID;
	double A1, A2, A3, A4, AZ51;
	string Disease; 
};

