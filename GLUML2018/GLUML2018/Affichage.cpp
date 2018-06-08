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


int main()
{
	//const string CHEMIN_RACINE="../GLUML2018/GLUML2018/";
	//const string CHEMIN_RACINE ="C:\\Users\\William\\Desktop\\Jeux (2)\\GitHub\\GL_UML_2018\\GLUML2018\\GLUML2018\\" ;
    //const string CHEMIN_RACINE="./";
    const string CHEMIN_RACINE="../../GLUML2018/GLUML2018/";
	//initialiserEmpreintes();
	c->afficherMessage("Bienvenue sur le service Malad'If ! \r\n");
	bool continuer=true;
	while (continuer)
	{

		c->afficherMessage(" Saisir une action a effectuer : \r\n");
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

			string nomFichier = CHEMIN_RACINE+commande[1];
			string format;
            format=commande[1].substr((commande[1].length())-4,commande[1].length());
            if(format==".txt") {
                c->afficherMessage("Demande d'analyse ...");
                vector<Empreinte> res = Gestion::AnalyseEmpreinte(listeEmpreinte, nomFichier);
                c->afficherMessage(Gestion::AfficherEmpreinte(res));
            }
            else
            {
                c->afficherErreur("Erreur, le format de l'empreinte n'est pas valide");
            }

		}
		else if (commande[0]=="LISTEMALADIES")
		{
			c->afficherMessage("Affichage de la liste des maladies ...");
			set<string> maladiesConnues;
            if (listeMaladie.begin() == listeMaladie.end())
            {
                c->afficherDanger("Warning, la base ne contient pas de maladie référencée");
            }else{
                Gestion::GetListeMaladie(listeMaladie, maladiesConnues);
                for (std::set<string>::iterator it = maladiesConnues.begin(); it != maladiesConnues.end(); it++) {
                    c->afficherMessage(*it + "\r\n");
                }
            }
		}
		else if (commande[0]=="DETAILSMALADIE")
		{
			c->afficherMessage("Affichage des détails de la maladie ...");
			string nomMaladie = commande[1];
			vector<Empreinte> detailsMaladie = Gestion::GetDetail(listeMaladie, nomMaladie);
			string listeEmpreinte = Gestion::AfficherEmpreinte(detailsMaladie);
			c->afficherMessage(listeEmpreinte);
		}
		else if (commande[0] == "LOAD")
		{

			string format;
			format=commande[1].substr((commande[1].length())-4,commande[1].length());
			if(format==".txt")
			{
				string nomFichier = CHEMIN_RACINE + commande[1];
			    listeEmpreinte = Gestion::LectureBase(nomFichier);
			    if(listeEmpreinte.begin()!=listeEmpreinte.end())
                {
                    c->afficherMessage("Succes de l'envoi du fichier d'empreintes");
                    c->afficherMessage("Chargement de BD...");
                    //Traitement des listeEmpreinte
					if(!listeEmpreinte.empty()){
						Gestion::ChargerListeMaladies(listeEmpreinte, listeMaladie);
					}
                    c->afficherMessage("Chargement termine");
                }
			}

			else
			{
				c->afficherErreur("Erreur, le format de l'empreinte n'est pas valide");
			}
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
