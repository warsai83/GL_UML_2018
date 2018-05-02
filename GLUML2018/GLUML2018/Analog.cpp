/*************************************************************************
                           Analog  -  description
    Classe permettant la lecture des options et de réaliser la partie
    traitement de l'application.
    Prends au moins un fichier log en paramètre, renvoie les dix
    hits, filtrés ou non, les plus fréquents.
    Si l'option -g est saisit et qu'un nom de fichier .dot est saisit,
    la classe génèrera un graphique qui sera contenu dans le fichier .dot.

    La compilation de l'application avec l'option -DDEBUG permet
    d'afficher des informations supplémentaires sur le traitement
    réalisé au sein de l'application.
                             -------------------
    début                : 07-02-2018
    copyright            : (C) 2018 par Halunka Matthieu, Augustin Bodet
    e-mail               : matthieu.halunka@insa-lyon.fr
                           augustin.bodet@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

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
#include "Generateur.h"
#include "Lecture.h"
#include "Formateur.h"
//------------------------------------------------------------- Constantes
const char BLEU [] = {033,'[','3','4','m'};
const char ROUGE [] = {033,'[','3','1','m'};
const char JAUNE [] = {033,'[','3','3','m'};
const char RESET [] = {033,'[','m',017};
const string ADRESSE_SERVEUR="intranet-if.insa-lyon.fr";
const string EXTENSION_A_EXCLURE []={".jpg",".jpeg",".ico",".gif",".png",
                                     ".css",".js",".tiff",".svg",".bmp"};
const int NB_EXTENSION_EXCLUSION=10;
//----------------------------------------------------------------- PUBLIC

struct optionsExecution
{
    bool defaut=true;
    string nomFichierLog="";
    bool genererDot=false;
    string nomFichierDot="";
    bool exclureExtension=false;
    bool filtrerHeure=false;
    string heureDebut="";
    string heureFin="";
};
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

//-------------------------------------------- Constructeurs - destructeur

int main2(int n, char *params[]){
    /**********************
        Lecture des options d'exécution.
    **********************/
    optionsExecution lectureOptions;
    //On prépare le flux de sortie pour écrire une erreur.
    cerr<<erreur;
    if (n<2 || n>7)
    {
        cerr<<"Usage non conforme de analog ! Référez vous au manuel !"<<raz<<endl;
        return -1;
    }
    else{
        if(strstr(params[n-1],".log")==nullptr||params[n-1][0]=='.'){
            cerr<<"Erreur : le fichier log doit avoir un nom et .log en extension !"<<raz<<endl;
            return -1;
        }
        //Est-on dans le cas du traitement standard ?
        if(n==2){
            lectureOptions.nomFichierLog=params[n-1];
        }
        else{
            lectureOptions.defaut=false;
            bool doublonOptionTrouve=false;
            for (int i = 1; i < n-1; ++i)
            {
                //Si on a l'option -g, on doit avoir un nom de fichier .dot qui le suit.
                if (strcmp("-g",params[i])==0)
                {
                    if (lectureOptions.genererDot) {
                        cerr << "Erreur : l'option [-g ***.dot] doit être unique !" << raz << endl;
                        return -1;
                    }
                    if (i<n-2)
                    {
                        i++;
                        if(strstr(params[i],".dot")==nullptr||params[i][0]=='.'){
                            cerr<<"Erreur : syntaxe [-g ***.dot] à respecter !"<<raz<<endl;
                            return -1;
                        }
                        lectureOptions.genererDot=true;
                        lectureOptions.nomFichierDot=params[i];
                    }
                    else{
                        cerr<<"Erreur : syntaxe [-g ***.dot] à respecter !"<<raz<<endl;
                        return -1;
                    }
                }
                //Si on a l'option -e
                else if(strcmp("-e",params[i])==0){
                    if (lectureOptions.exclureExtension&&!doublonOptionTrouve){
                        cout<<attention<<"Attention : l'option [-e] doit être unique !"<<raz<<endl;
                        doublonOptionTrouve=true;
                    }
                    lectureOptions.exclureExtension=true;
                }
                //Si on a l'option -g, on regarde si on a une heure h (avec 0<=h<24) qui le suit
                else if(strcmp("-t",params[i])==0){
                    if (lectureOptions.filtrerHeure){
                        cerr<<"Erreur : l'option [-t heure] doit être unique !"<<raz<<endl;
                        return -1;
                    }
                    if (i<n-2)
                    {
                        i++;
                        string heure=params[i];
                        istringstream separateur(heure);
                        char chiffreLu='.';

                        //Entier trop long ?
                        if (heure.length()>2){
                            cerr<<"Erreur : syntaxe [-t heure] à respecter avec une heure "
                                    "comprise entre 0 et 24 !"<<raz<<endl;
                            return -1;
                        }

                        //Chaine impossible a transformer en entier ?
                        for (unsigned int j = 0; j < heure.length(); ++j) {
                            separateur.get(chiffreLu);
                            if (chiffreLu<'0'||chiffreLu>'9')
                            {
                                cerr<<"Erreur : syntaxe [-t heure] à respecter avec une heure "
                                        "comprise entre 0 et 24 !"<<raz<<endl;
                                return -1;
                            }
                        }
                        int valeurHeure=stoi(heure);

                        //L'heure est-elle valide ?
                        if(valeurHeure>23){
                            cerr<<"Erreur : syntaxe [-t heure] à respecter avec une heure "
                                    "comprise entre 0 et 24 !"<<raz<<endl;
                            return -1;
                        }
                        //On modifie la structure pour prendre en compte l'option -t
                        lectureOptions.filtrerHeure=true;
                        lectureOptions.heureDebut=heure;
                        valeurHeure++;
                        lectureOptions.heureFin=to_string(valeurHeure);
                    }
                    else{
                        cerr<<"Erreur : syntaxe [-t heure] à respecter !"<<raz<<endl;
                        return -1;
                    }
                }
                else{
                    cerr<<"Erreur : paramètre inconnu !! Vérifiez le manuel !"<<raz<<endl;
                    return -1;
                }
            }
            lectureOptions.nomFichierLog=params[n-1];
        }
    }


    /**********************
    Infos pour débug
    ***********************/
#ifdef DEBUG
    cout<<debug<<"Debug -- Affichage des options lues"<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout<<params[i]<<endl;
    }
    cout<<"-----    Transformée en   -----"<<endl;
    cout<<"-----la structure suivante-----"<<endl;
    cout<<"defaut "<<lectureOptions.defaut<<endl;
    cout<<"nomFichierLog "<<lectureOptions.nomFichierLog<<endl;
    cout<<"genereDot "<<lectureOptions.genererDot<<endl;
    cout<<"nomFichierDot "<<lectureOptions.nomFichierDot<<endl;
    cout<<"exclure "<<lectureOptions.exclureExtension<<endl;
    cout<<"filtrerHeure "<<lectureOptions.filtrerHeure<<endl;
    cout<<"heureDebut "<<lectureOptions.heureDebut<<raz<<endl;
    cout<<"---------------------------------------------"<<endl;
#endif

    /**********************
    Début code traitement
    ***********************/
    if(lectureOptions.filtrerHeure){
        cout<<attention<<"Attention : seul les cibles "<<lectureOptions.heureDebut<<"h et "
            <<lectureOptions.heureFin<<"h ont été prises en compte !"<<raz<<endl;
    }
    //------------------Début Lecture et stockage
    Lecture* fichierLog=new Lecture(lectureOptions.nomFichierLog);
    //Mise en place de la structure de données
    map<string,int> Noeud;
    map<pair<string,string>,int> Liens;

    string target;
    string referer;
    string hour;

    //Lecture du log et stockage des noeuds et des liens existant entre eux.
    bool exclureRequete;
    while(fichierLog->LecturePossible){
        fichierLog->Charger();
        //On ne prends en compte que les requêtes HTTP réussies (code 200 OK et code 302 FOUND)

        //.line -> ->Decoupeur
        if (fichierLog->Decoupeur->code=="200"||fichierLog->Decoupeur->code=="302"){
            target=fichierLog->Decoupeur->target;
            referer=fichierLog->Decoupeur->referer;
            exclureRequete=false;
            //Formatage de target
            if(target.find('?')!=string::npos){
                target=target.substr(0,target.find('?'));
            }

            //Formatage du referer, on ne prend en compte que les requêtes HTTP
            if (referer.find("http://")==0){
                //Supprime le protocole
                referer=referer.substr(6);
                //Supprime le serveur si target est locale
                if(referer.find(ADRESSE_SERVEUR)==1){
                    referer=referer.substr(ADRESSE_SERVEUR.length()+1);
                }
                //On ne prend pas en compte les données transmisses
                if(referer.find('?')!=string::npos){
                    referer=referer.substr(0,referer.find('?'));
                }
            }
            else{
                exclureRequete=true;
            }

            //On traite en fonction des options saisies
            if(!lectureOptions.defaut){
                //Option -e
                if (lectureOptions.exclureExtension) {
                    for (int i = 0; i < NB_EXTENSION_EXCLUSION&&!exclureRequete; ++i) {
                        if (target.find(EXTENSION_A_EXCLURE[i])!=string::npos
                            ||referer.find(EXTENSION_A_EXCLURE[i])!=string::npos){
                            exclureRequete=true;
                        }
#ifdef DEBUG
                        if(exclureRequete){
                            if (target.find(EXTENSION_A_EXCLURE[i])!=string::npos){
                                cout<<target<<" | cible exclue ! "<<endl;
                            }
                            else
                            {
                                cout<<referer<<" | referer exclut ! "<<endl;
                            }
                        }
#endif
                    }
                }

                //Option -t
                if (lectureOptions.filtrerHeure) {
                    if (fichierLog->Decoupeur->time==""){
                        exclureRequete=true;
                    }else{
                        hour = fichierLog->Decoupeur->time.substr(12, 2);
                        if (lectureOptions.heureDebut != hour) {
                            exclureRequete = true;
                        }
                    }
                }
                //On n'a pas déjà atteind la fin lors de la lecture
                //et on n'exclut pas le résultat de notre requête ?
                if (!exclureRequete&&fichierLog->LecturePossible){

                    if (Noeud.find(target) != Noeud.end()) {
                        Noeud[target]++;
                    }
                    else {
                        Noeud.insert(make_pair(target, 1));
                    }

                    pair<string,string> CleMap =make_pair(referer,target);
                    if (Liens.find(CleMap) != Liens.end()) {
                        Liens[CleMap]++;
                    }
                    else {
                        Liens.insert(make_pair(CleMap,1));
                        //On a une paire avec un referer inconnu ?
                        if (Noeud.find(referer) == Noeud.end()) {
                            Noeud.insert(make_pair(referer, 0));
                        }
                    }
                }
            }//FIN IF(!lectureOptions.defaut)
            else{
                //On a un traitement par défaut
                if (!exclureRequete&&fichierLog->LecturePossible) {
                    if (Noeud.find(target) != Noeud.end()) {
                        Noeud[target]++;
                    } else {
                        Noeud.insert(make_pair(target, 1));
                    }
                }
            }
        }//FIN IF(fichierLog->line.code=="200")
    }//FIN WHILE

    //------------------Vérification de la cohérence avant de continuer
    if (Noeud.empty()){
        cout<<"Aucun résultat obtenu, vérifiez la conformité du fichier log !"<<endl;
        delete fichierLog;
        return 0;
    }
    if (lectureOptions.genererDot&&Liens.empty()){
        cout<<attention<<"Attention : aucun lien n'a pu être trouvé entre les noeuds du graphique !"<<raz<<endl;
    }

    //------------------Début du tri
    //On va charger la multimap de trier nos valeurs en inversant la clé et la valeur
    //de notre map contenant nos noeuds.
    multimap<int,string> triMap;
    map<string, int>::iterator it;
    for (it = Noeud.begin(); it != Noeud.end(); ++it){
        triMap.insert(make_pair(it->second,it->first));
    }
    multimap<int,string>::reverse_iterator ritNoeud;

    //------------------Début de la génération du graphe si nécessaire
    if (lectureOptions.genererDot){
        Generateur* ecrireDot=new Generateur(lectureOptions.nomFichierDot);
        int idNoeud=0;
        map<string,int> idNoeudDot;

        if(!ecrireDot->EcriturePossible){
            cerr<<"Erreur : écriture impossible du fichier "<<lectureOptions.nomFichierDot<<" !"<<raz<<endl;
            return -1;
        }

        //Ecriture des noeuds dans l'ordre décroissant du nombre de hits
        //Et sauvegarde de la correspondance entre le noeud et son id dans le graphe dans une map
        for (ritNoeud = triMap.rbegin(); ritNoeud != triMap.rend(); ++ritNoeud,++idNoeud){
            ecrireDot->EcrireNoeud(idNoeud,ritNoeud->second);
            idNoeudDot.insert(make_pair(ritNoeud->second,idNoeud));
        }

        idNoeud=0;
        multimap<int,string>::reverse_iterator ritLiens;
        //Découverte des liens valides et écriture de ceux-ci pour chaque noeuds
        //On génére l'ensemble des clés <referer,target> possibles
        for (ritNoeud = triMap.rbegin(); ritNoeud != triMap.rend(); ++ritNoeud,++idNoeud){
            for (ritLiens = triMap.rbegin(); ritLiens != triMap.rend(); ++ritLiens){
                pair<string,string> CleLiens=make_pair(ritNoeud->second,ritLiens->second);
#ifdef DEBUG
                cout<<debug<<"Paire lue "<<CleLiens.first<<" | "<<CleLiens.second<<raz<<endl;
#endif
                //On regarde si la paire a une valeur associée
                if (Liens.find(CleLiens)!=Liens.end()){
                    ecrireDot->EcrireLien(idNoeudDot[CleLiens.first],idNoeudDot[CleLiens.second],Liens[CleLiens]);
                }
            }
        }
        if (ecrireDot->EcriturePossible){
            cout<<"Fichier Dot "<<lectureOptions.nomFichierDot<<" généré"<<endl;
        }
        delete ecrireDot;
    }//FIN IF(lectureOptions.genererDot)

    /**********************
    Début code affichage
    ***********************/
    int cptAff=0;
    //On affiche au maximum les dix premiers noeuds dans l'ordre décroissant
    for (ritNoeud = triMap.rbegin(); ritNoeud != triMap.rend() && cptAff<10; ++ritNoeud,++cptAff){
        //Le noeud a t-il déjà été visité ?
        if (ritNoeud->first==0){
            cptAff--;
        }else {
            cout << ritNoeud->second << " (" << ritNoeud->first << " hits)" << endl;
        }
    }

    delete fichierLog;
    return 0;
}

