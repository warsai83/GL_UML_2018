#include "Empreinte.h"



Empreinte::Empreinte()
{
	Disease = Maladie();
}

Empreinte::Empreinte(int unNoID, double unA1, double unA2, double unA3, double unA4, double unAZ51, Maladie uneDisease) : NoID(unNoID),A1(unA1),A2(unA2),A3(unA3),A4(unA4),AZ51(unAZ51),Disease(uneDisease)
{

}

Empreinte::~Empreinte()
{
}

string Empreinte::toString()
{
	string s = to_string(NoID) + ";" + to_string(A1) +";"+ to_string(A2) +";"+ to_string(A3) +";"+ to_string(A4) +";"+ to_string(AZ51) +";"+ Disease;
	return s;
}
