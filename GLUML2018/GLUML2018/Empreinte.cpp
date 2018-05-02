#include "Empreinte.h"



Empreinte::Empreinte()
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
