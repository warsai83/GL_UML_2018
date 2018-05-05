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
#include <fstream>
#include <sstream>
#include <string>

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

 // afficherDebug(string info)
 // Algorithme :
 //      Ecrit les informations de débugage dans la console
void Console::afficherDebug(string &info)
{
	cout << &Console::debug << info << &Console::raz << endl;
}//----- Fin de afficherDebug
#endif

// ostream & erreur ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en rouge.
ostream & Console::erreur (ostream & os){
    os.write(ROUGE, sizeof(ROUGE));
    return os;
}//----- Fin de erreur

// ostream & attention( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en jaune.
ostream & Console::attention (ostream & os){
    os.write(JAUNE, sizeof(JAUNE));
    return os;
}//----- Fin de attention

// ostream & debug ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il reprenne ses
//      paramètres initiaux.
ostream & Console::raz (ostream & os){
    os.write(RESET, sizeof(RESET));
    return os;
}//----- Fin de debug


// afficherErreur(string err)
// Algorithme :
//      Affiche le message d'erreur sur la console
void Console::afficherErreur(const string &err){
	cout << &Console::erreur << err << &Console::raz << endl;
}//----- Fin de afficherErreur

// afficherDanger(string danger)
// Algorithme :
//      Affiche le message d'avertissement sur la console
void Console::afficherDanger(const string &danger) {
	cout << &Console::attention << danger << &Console::raz << endl;
}//----- Fin de afficherDanger

// afficherDanger(string danger)
// Algorithme :
//      Affiche le message sur la console
void Console::afficherMessage(const string &msg) {
	cout << msg << endl;
}//----- Fin de afficherMessage

// lireEntier()
// Algorithme :
//	Méthode pour lire un entier valide à partir du terminal
int Console::lireEntier() {
	int s;
	string lecture;
	istringstream separateur;
	bool charValide = false;
	char caracLu;
	while (lecture.empty() || !charValide)
	{
		getline(cin, lecture);
		if (!lecture.empty())
		{
			separateur.str(lecture);
			for (unsigned int i = 0; i < lecture.length(); ++i)
			{
				separateur.get(caracLu);
				//On regarde si la ligne lue est constituée d'autres caractères
				// que espace et retour chariot.
				if (caracLu<'0' || caracLu>'9')
				{
					charValide = false;
					afficherErreur("Saissisez un entier !");
					break;
				}
				else {
					charValide = true;
				}
			}
			separateur.clear();

			if (lecture.length()>6 && charValide)
			{
				lecture = "";
				afficherErreur("Entier trop grand !");
			}
		}
	}
	s = stoi(lecture);
	return s;
}//----- Fin de lireEntier

// lireChaine()
// Algorithme :
//	Permet de lire le terminal et d'éviter la saisie de caractères frauduleux
string Console::lireChaine() {
	string s;
	istringstream separateur;
	bool charValide = false;
	char caracLu;
	while (s.empty() || (!charValide))
	{
		getline(cin, s);
		if (!s.empty())
		{
			separateur.str(s);
			for (unsigned int i = 0; i < s.length(); ++i)
			{
				separateur.get(caracLu);
				//On regarde si la ligne lue est constituée d'autres caractères
				// que espace et retour chariot.
				if (caracLu != ' '&&caracLu != '\r')
				{
					charValide = true;
					//Si je trouve un /, la saisie est invalide
					if (caracLu == '/') {
						afficherErreur("Le / est interdit, recommencez la saisie !");
						charValide = false;
						break;
					}
				}
			}
			separateur.clear();
		}
	}
	return s;
}

//-------------------------------------------- Constructeurs - destructeur

Console::Console(const Console & uneConsole) {
	//INTERDIT
}

Console::Console(){

}

Console::~Console() {

}
