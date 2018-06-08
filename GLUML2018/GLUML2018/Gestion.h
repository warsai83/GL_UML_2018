/*************************************************************************
                        Gestion  - description

    Classe réalisant l'ensemble des services client de l'application.

                          -------------------
début                :	07-06-2018
copyright            :	(C) 2018 par Halunka Matthieu, Mathilde Moureau
                                     Stanley Cheah, William Occelli
e-mail               :	matthieu.halunka@insa-lyon.fr
                        mathilde.moureau@insa-lyon.fr
                        stanley.cheah@insa-lyon.fr
                        william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Gestion> (fichier Gestion.h) ----------------
#if ! defined ( GESTIONEMPREINTE_H )
#define GESTIONEMPREINTE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <vector>
#include <set>

#include "Empreinte.h"
#include "Maladie.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gestion>
//
//
//------------------------------------------------------------------------

class Gestion
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	static string AfficherEmpreinte(vector<Empreinte>& listeEmpreinte);
	static void GetListeMaladie(vector<Maladie>& listeMaladie,std::set<string>& setMaladie);
	static vector<Empreinte> GetDetail(vector<Maladie>& setMaladie, string nomMaladie);
	static vector<Empreinte> AnalyseEmpreinte(vector<Empreinte>&,string );
	static vector<Empreinte> LectureBase(string);
	static void chargerListeMaladies(vector<Empreinte>, vector<Maladie>);
	static Empreinte stringToEmpreinte(vector<string>&);



	//-------------------------------------------- Constructeurs - destructeur
	Gestion();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Gestion();
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
};

//-------------------------------- Autres d�finitions d�pendantes de <GestionEmpreinte>

#endif // GESTIONEMPREINTE_H
