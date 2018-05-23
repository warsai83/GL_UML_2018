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

void initialiserEmpreintes()
{
	Maladie* mal1 = new Maladie("Rhume");
	Empreinte* h1 = new Empreinte(1, 1, 2.12, 13, 3.156,1236, mal1 );
	SETMALADIES.insert(*mal1);
	EMPREINTES.assign(1,*h1);

	Maladie* mal2 = new Maladie("Angine");
	Empreinte* h2 = new Empreinte(2, false, 1.1, 14.3, 13.2, 2367, mal2);
	SETMALADIES.insert(*mal2);
	EMPREINTES.assign(1, *h2);

	Maladie* mal3 = new Maladie("Grippe");
	Empreinte* h3 = new Empreinte(3, 0, 12, 145, 12.1, 11, mal3);
	SETMALADIES.insert(*mal3);
	EMPREINTES.assign(1, *h3);

	Maladie* mal4 = new Maladie("Gastro");
	Empreinte* h4 = new Empreinte(4, 2, 2.14, 20, 2.102, 1836, mal4);
	SETMALADIES.insert(*mal4);
	EMPREINTES.assign(1, *h4);

}
int main()
{
	initialiserEmpreintes();
	Console* c = new Console();
	Gestion* g = new Gestion();
	c->afficherMessage("Bienvenu sur le service Malad'If ! \r\n");
	while (true)
	{

		c->afficherMessage(" Saisir une action à effectuer : \r\n");
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
			string maladies = "";
			for (std::set<Maladie>::iterator i = SETMALADIES.begin(); i != SETMALADIES.end(); i++) {
				maladies.append(i->toString + "\r\n");
			}
			c->afficherMessage(maladies);
		}
		else if (commande[0].compare("DETAILSMALADIE"))
		{
			c->afficherMessage("Affichage des détails de la maladie ...");
			string maladie = commande[1];
			vector<Empreinte> detailsMaladie = g.getDetails(SETMALADIES, maladie);
			string empreintes = g->AfficherEmpreinte(detailsMaladie);
			c->afficherMessage(empreintes);
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
	}
	return 0;
}
//-------------------------------------------- Constructeurs - destructeur
Affichage::Affichage()
{
}


Affichage::~Affichage()
{
}
