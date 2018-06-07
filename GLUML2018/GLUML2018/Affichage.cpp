/*************************************************************************
                            Affichage  -  description
            Classe gérant l'interaction avec l'utilisateur
                            -------------------
début                : 02-05-2018
copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
                                    Stanley Cheah, William Occelli
e-mail               :  matthieu.halunka@insa-lyon.fr
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
	const string CHEMIN_RACINE="../GLUML2018/GLUML2018/";
	//const string CHEMIN_RACINE ="C:\\Users\\William\\Desktop\\Jeux (2)\\GitHub\\GL_UML_2018\\GLUML2018\\GLUML2018\\" ;
	//initialiserEmpreintes();
	c->afficherMessage("Bienvenu sur le service Malad'If ! \r\n");
	bool continuer=true;
	while (continuer)
	{

		c->afficherMessage(" Saisir une action à effectuer : \r\n");
		string commandeUtilisateur = c->lireChaine();
		string commande[2] ;
		SeparerString(commande,&commandeUtilisateur);

#ifdef DEBUG
		c->afficherDebug("res 0 : "+commande[0]);
		c->afficherDebug("res 1  : "+commande[1]);
#endif
		//-----------
		if (commande[0]=="ANALYSE")
		{
			c->afficherMessage("Demande d'analyse ...");
			string nomFichier = CHEMIN_RACINE+commande[1];

			vector<Empreinte> res = Gestion::AnalyseEmpreinte(EMPREINTES, nomFichier);
			c->afficherMessage(Gestion::AfficherEmpreinte(res));
			
		}
		else if (commande[0]=="LISTEMALADIES")
		{
			c->afficherMessage("Affichage de la liste des maladies ...");
			/*if (SETMALADIES.begin() == SETMALADIES.end())
			{
				c->afficherDanger("Warning, la base ne contient pas de maladie référencée");
			}*/
			set<string> maladiesConnues;
			Gestion::GetListeMaladie(EMPREINTES, maladiesConnues);
			for (std::set<string>::iterator it = maladiesConnues.begin(); it != maladiesConnues.end(); it++) {
				c->afficherMessage(*it + "\r\n");
			}
		}
		else if (commande[0]=="DETAILSMALADIE")
		{
			c->afficherMessage("Affichage des détails de la maladie ...");
			string nomMaladie = commande[1];
			vector<Empreinte> detailsMaladie = Gestion::GetDetail(SETMALADIES, nomMaladie);
			string empreintes = Gestion::AfficherEmpreinte(detailsMaladie);
			c->afficherMessage(empreintes);
		}
		else if (commande[0] == "LOAD")
		{
			c->afficherMessage("Chargement de BD...");
			string nomFichier = CHEMIN_RACINE+commande[1];
			EMPREINTES = Gestion::LectureBase(nomFichier);

			c->afficherMessage("Chargement terminé");
		}
		else if (commande[0] == "QUITTER")
		{
			continuer = false;
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
