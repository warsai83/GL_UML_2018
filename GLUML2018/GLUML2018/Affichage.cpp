/*************************************************************************
Affichage  -  description
Classe gérant l'interaction avec l'utilisateur
-------------------
début                : 02-05-2018
copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
Stanley Cheah, William Occelli
e-mail               : matthieu.halunka@insa-lyon.fr
mathilde.moureau@insa-lyon.fr
stanley.cheah@insa-lyon.fr
william.occelli@insa-lyon.fr

*************************************************************************/

//--- Réalisation de la classe <Affichage> (fichier Affichage.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Affichage.h"
#include "Console.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
string* SeparerString(string s, const char separateur=' ' )
{
	string res[2];
	size_t pos1 = s.find(separateur);
	res[0] = s.substr(0, pos1);
	res[1] = s.substr(pos1 + 1, s.length());
	return res;
}

int main()
{
	Console* c = new Console();
	c->afficherMessage("Bienvenu sur le service Malad'If ! \r\n Saisir une action à effectuer : \r\n");
	string commandeUtilisateur = c->lireChaine();
	string* commande = SeparerString(commandeUtilisateur);

	//debug ----------
	cout << "res 0 : " << commande[0] << endl << "res 1  : " << commande[1];

	//-----------
	if (commande[0].compare("ANALYSE") == 0)
	{
		c->afficherMessage("Demande d'analyse ...");
	}
	else if (commande[0].compare("LISTEMALADIES"))
	{
		c->afficherMessage("Affichage de la liste des maladies ...");
	}
	else if (commande[0].compare("DETAILSMALADIE"))
	{
		c->afficherMessage("Affichage des détails de la maladie ...");
	}
	else if (commande[0].compare("CHARGER")) 
	{
		c->afficherMessage("Chargement du fichier ..");
	}
	else
	{
		c->afficherDanger("Commande inconnue");
	}
	//----------
	return 0;
}
//-------------------------------------------- Constructeurs - destructeur
Affichage::Affichage()
{
}


Affichage::~Affichage()
{
}
