#Définition des variables
OPTIONS=
# Pour l'utiliser, écrire $ make OPTIONS="..." dans un shell
# -DMAP pour afficher les traces
# -DDEBUG pour passer en mode debug

#Définition des fichiers sources
sources=$(wildcard Maladif/Ecriture/*.cpp Maladif/Lecture/*.cpp Maladif/ObjetsMetiers/*.cpp Maladif/Services/*.cpp Maladif/Vue/*.cpp)
#Définition des options de compilation
CLEAN=raz
CXXFLAGS= -g -ansi -pedantic -Wall -std=c++11
LDFLAGS= -g -ansi -pedantic -Wall -std=c++11
COMPILATEUR=g++
REP_TEST = Tests/
EXEC_TEST = ./mktest.sh
#Définition du nom de l'éxécutable à créer
EXEC=MaladIF
#Définition des fichiers à compiler en .o
objets = $(sources:.cpp=.o)

#Création de l'éxécutable avec l'édition des liens
all: $(EXEC)

MaladIF: $(objets)
	@echo "-----Edition des liens-----"
	@($(COMPILATEUR) $(LDFLAGS) -o $@ $^)
	@echo "-----Application générée-----"

#Création des classes compilées en .o
%.o: %.cpp
	@echo "-----Compilation de "$@"-----"
	@($(COMPILATEUR) $(CXXFLAGS) $(OPTIONS) -o $@ -c $<)

#La fonction raz n'est pas associé aux fichiers
.PHONY: $(CLEAN)

#Fonction pour re/construire les dépendances au sein du makefile
#NE FONCTIONNE PAS SUR LES POSTES DES SALLES DE TD
#depend:
#	makedepend $(sources)
	
#Fonction de suppression de l'ensemble des fichiers crées par le makefile
$(CLEAN):
	@echo "-----Suppression des fichiers antérieurs-----"
	@(rm -f $@ $(objets) $(EXEC) core)

test:	
	$(MAKE)
	@echo "Lancement du script de test : \n"
	@(cd $(REP_TEST) && bash $(EXEC_TEST) )

# DO NOT DELETE

Maladif/Ecriture/Generateur.o: Maladif/Ecriture/Generateur.h
Maladif/Ecriture/Generateur.o: Maladif/ObjetsMetiers/Maladie.h
Maladif/Ecriture/Generateur.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Ecriture/Generateur.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Ecriture/Generateur.o: Maladif/Vue/Console.h
Maladif/Lecture/Formateur.o: Maladif/Lecture/Formateur.h
Maladif/Lecture/Formateur.o: Maladif/Vue/Console.h
Maladif/Lecture/Lecture.o: Maladif/Lecture/Lecture.h
Maladif/Lecture/Lecture.o: Maladif/Lecture/Formateur.h Maladif/Vue/Console.h
Maladif/ObjetsMetiers/Maladie.o: Maladif/ObjetsMetiers/Maladie.h
Maladif/ObjetsMetiers/Maladie.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/ObjetsMetiers/Maladie.o: Maladif/Vue/Console.h
Maladif/ObjetsMetiers/Empreinte.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/ObjetsMetiers/Empreinte.o: Maladif/Vue/Console.h
Maladif/Services/Gestion.o: Maladif/Services/Gestion.h
Maladif/Services/Gestion.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Services/Gestion.o: Maladif/ObjetsMetiers/Maladie.h
Maladif/Services/Gestion.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Services/Gestion.o: Maladif/Lecture/Lecture.h
Maladif/Services/Gestion.o: Maladif/Lecture/Formateur.h Maladif/Vue/Console.h
Maladif/Vue/Affichage.o: Maladif/Vue/Affichage.h Maladif/Vue/Console.h
Maladif/Vue/Affichage.o: Maladif/ObjetsMetiers/Maladie.h
Maladif/Vue/Affichage.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Vue/Affichage.o: Maladif/Services/Gestion.h
Maladif/Vue/Affichage.o: Maladif/ObjetsMetiers/Empreinte.h
Maladif/Vue/Console.o: Maladif/Vue/Console.h
