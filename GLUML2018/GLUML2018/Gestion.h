/*************************************************************************
Gestion  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Gestion> (fichier Gestion.h) ----------------
#if ! defined ( GESTIONEMPREINTE_H )
#define GESTIONEMPREINTE_H

//--------------------------------------------------- Interfaces utilisées
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
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	static string AfficherEmpreinte(vector<Empreinte> listeEmpreinte);
	static set<Maladie> GetListeMaladie(vector<Empreinte> listeEmpreinte);
	static vector<Empreinte> GetDetail(string nomMaladie);
	static Maladie analyseEmpreinte(vector<Empreinte>,Empreinte);



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
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GestionEmpreinte>

#endif // GESTIONEMPREINTE_H
