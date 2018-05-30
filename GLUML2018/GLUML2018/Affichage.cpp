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

static Console* c = new Console();
//----------------------------------------------------- Méthodes publiques
void SeparerString(string* result, string* s, const char separateur=' ')
{
	size_t pos1 = s->find(separateur);
	result[0] = s->substr(0, pos1);
    result[1] = s->substr(pos1 + 1, s->length());
}

/*void initialiserEmpreintes()
{
	Maladie* mal1 = new Maladie("Rhume");
	vector<string>  s;
	string mal = "Rhume";
	s.assign(mal);
	Empreinte* h1 = new Empreinte(1, 1, 2.12, 13, 3.156,1236, s );
	mal1->AjouterEmpreinte(*h1);
	SETMALADIES.insert(*mal1);
	EMPREINTES.assign(1,*h1);

	Maladie* mal2 = new Maladie("Angine");
	s = "Angine";
	Empreinte* h2 = new Empreinte(2, false, 1.1, 14.3, 13.2, 2367, s);
	mal2->AjouterEmpreinte(*h2);
	SETMALADIES.insert(*mal2);
	EMPREINTES.assign(1, *h2);

	Maladie* mal3 = new Maladie("Grippe");
	s = "Grippe";
	Empreinte* h3 = new Empreinte(3, 0, 12, 145, 12.1, 11, s);
	mal3->AjouterEmpreinte(*h3);
	SETMALADIES.insert(*mal3);
	EMPREINTES.assign(1, *h3);

	Maladie* mal4 = new Maladie("Gastro");
	s = "Gastro";
	Empreinte* h4 = new Empreinte(4, 2, 2.14, 20, 2.102, 1836, s);
	mal4->AjouterEmpreinte(*h4);
	SETMALADIES.insert(*mal4);
	EMPREINTES.assign(1, *h4);

}*/
int main()
{
	//initialiserEmpreintes();
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
			string nomFichier = "./"+commande[1];
			set<string> res = g->AnalyseEmpreinte(EMPREINTES, nomFichier);
			for (std::set<string>::iterator it = res.begin(); it != res.end(); it++)
			{
				c->afficherMessage(*it);
			}
			
		}
		else if (commande[0].compare("LISTEMALADIES"))
		{
			c->afficherMessage("Affichage de la liste des maladies ...");
			string maladies = "";
			if (SETMALADIES.begin() == SETMALADIES.end())
			{
				c->afficherDanger("Warning, la base ne contient pas de maladie référencée");
			}
			set<Maladie> maladiesConnues = g->GetListeMaladie(EMPREINTES);
			for (std::set<Maladie>::iterator it = maladiesConnues.begin(); it != maladiesConnues.end(); it++) {
				maladies.append(it->getName() + "\r\n");
			}
			c->afficherMessage(maladies);
		}
		else if (commande[0].compare("DETAILSMALADIE"))
		{
			c->afficherMessage("Affichage des détails de la maladie ...");
			string maladie = commande[1];
			/*vector<Empreinte> detailsMaladie = g.getDetails(SETMALADIES, maladie);
			string empreintes = g->AfficherEmpreinte(detailsMaladie);
			c->afficherMessage(empreintes);*/
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
#ifdef MAP
	c->afficherMessage("Appel au constructeur de <Affichage>");
#endif
}


Affichage::~Affichage()
{
#ifdef MAP
	c->afficherMessage("Appel au destructeur de <Affichage>");
#endif
}
