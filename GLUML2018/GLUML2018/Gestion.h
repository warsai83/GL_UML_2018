/*************************************************************************
Gestion  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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
// R�le de la classe <Gestion>
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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <GestionEmpreinte>

#endif // GESTIONEMPREINTE_H
