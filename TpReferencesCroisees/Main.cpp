/*************************************************************************
 Main  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par rgicquel
 *************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "References.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
const int ERREUR_ARGS = 1;
const int ERREUR_FICHIER_MOTS_CLES = 2;

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char ** argv )
// Algorithme :
//
{
	if ( argc < 2 )
	{
		cout << "Nombres d'arguments insuffisant" << endl;
		return ERREUR_ARGS;
	}

	bool exclureMotsCles = false;
	bool fichierMotsClesAttendu = false;
	bool optionsTerminees = false;
	int positionAttendue;

	char * nomFichierMotsCles = NULL;
	vector<char *> nomsFichiers;

	// Traitement des arguments fournis
	for (int i = 1; i < argc; i++) {

		if (!optionsTerminees && argv[i][0] == '-') {
			if (argv[i][1] == 'e') {
				if (i == 1) {
					if (argc < 3) {
						cout << "Aucun nom de fichier fourni" << endl;
						return ERREUR_ARGS;
					}
					exclureMotsCles = true;
				}
				else {
					cerr << "Position de l'argument -e invalide" << endl;
					return ERREUR_ARGS;
				}
			}
			else if (argv[i][1] == 'k') {
				if (exclureMotsCles) {
					positionAttendue = 2;
				}
				else {
					positionAttendue = 3;
				}

				if (i == positionAttendue) {
					fichierMotsClesAttendu = true;
				}
				else {
					cerr << "Position de l'argument -k invalide" << endl;
					return ERREUR_ARGS;
				}

				if (argc < positionAttendue+2) {
					cout << "Nombres d'arguments insuffisant" << endl;
					return ERREUR_ARGS;
				}
			}
		}
		else {
			optionsTerminees = true;

			if (fichierMotsClesAttendu) {
				nomFichierMotsCles = argv[i];
				fichierMotsClesAttendu = false;
			}
			else {
				nomsFichiers.push_back(argv[i]);
			}
		}
	}

	References ref;
	try {
		ref.TraiterFichiers(nomFichierMotsCles, nomsFichiers);
	}
	catch (Erreur &e) {
		cerr << "Erreur" << endl;
	}

	cout << ref.AfficherResultat() << endl;

	return 0;
} //----- fin de main
