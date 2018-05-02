/*************************************************************************
                           Console  -  description
    Classe permettant l'affichage sur la console de visual studio
                             -------------------
    début                : 02-05-2018
    copyright            : (C) 2018 par Halunka Matthieu, Mathilde Moureau
										Stanley Cheah, William Occelli
    e-mail               : matthieu.halunka@insa-lyon.fr
                           mathilde.moureau@insa-lyon.fr
						   stanley.cheah@insa-lyon.fr
						   william.occelli@insa-lyon.fr

*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Console.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <utility>
#include <deque>
#include <map>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Console.h"

//------------------------------------------------------------- Constantes
const char BLEU [] = {033,'[','3','4','m'};
const char ROUGE [] = {033,'[','3','1','m'};
const char JAUNE [] = {033,'[','3','3','m'};
const char RESET [] = {033,'[','m',017};
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

#ifdef DEBUG
// ostream & debug ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en bleu.
ostream & debug (ostream & os){
    os.write(BLEU, sizeof(BLEU));
    return os;
}//----- Fin de debug
#endif

// ostream & erreur ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en rouge.
ostream & erreur (ostream & os){
    os.write(ROUGE, sizeof(ROUGE));
    return os;
}//----- Fin de erreur

// ostream & attention( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en jaune.
ostream & attention (ostream & os){
    os.write(JAUNE, sizeof(JAUNE));
    return os;
}//----- Fin de attention

// ostream & debug ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il reprenne ses
//      paramètres initiaux.
ostream & raz (ostream & os){
    os.write(RESET, sizeof(RESET));
    return os;
}//----- Fin de debug

void afficherErreur(string err){
	cout << erreur << err << raz << endl;
}

void afficherDanger(string danger) {
	cout << attention << danger << raz << endl;
}

void afficherMessage(string msg) {

}

int lireEntier() {
}

string lireChaine() {
	string lecture;
	cin>>lecture;
	return lecture;
}



//-------------------------------------------- Constructeurs - destructeur

Console::Console(const Console & uneConsole) {
	//INTERDIT
}

Console::Console(){

}

Console::~Console() {

}