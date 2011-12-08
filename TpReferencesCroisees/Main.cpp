/*************************************************************************
 Main  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par Robin Gicquel et Arnaud Mery de Montigny
 *************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) -----
/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <set>
#include <vector>
#include <string>

//------------------------------------------------------ Include personnel
#include "References.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
const int RET_ERR_ARGS = 1;
const int RET_ERR_FICHIER_MOTS_CLES = 2;
const int RET_ERR_LECTURE = 3;

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char ** argv )
// Algorithme : Lecture des paramètres fournis à l'exécution, vérification de
// leur validité puis lancement des opérations de traitement de fichiers avec
// les options adéquates
{
	if ( argc < 2 )
	{
		cout << "Nombres d'arguments insuffisant" << endl;
		return RET_ERR_ARGS;
	}

	bool exclureMotsCles = false;
	bool fichierMotsClesAttendu = false;
	int positionAttendue;

	char * nomFichierMotsCles = NULL;
	set<string> nomsFichiers;

	// Traitement des arguments fournis
	for ( int i = 1; i < argc; i++ )
	{

		if ( argv[i][0] == '-' )
		{
			if ( argv[i][1] == 'e' && argv[i][2] == 0 )
			{
				if ( i == 1 )
				{
					if ( argc < 3 )
					{
						cerr << "Aucun nom de fichier fourni" << endl;
						return RET_ERR_ARGS;
					}
					exclureMotsCles = true;
				}
				else
				{
					cerr << "Position de l'argument -e invalide" << endl;
					return RET_ERR_ARGS;
				}
			}
			else if ( argv[i][1] == 'k' && argv[i][2] == 0 )
			{
				if ( exclureMotsCles )
				{
					positionAttendue = 2;
				}
				else
				{
					positionAttendue = 1;
				}

				if ( i == positionAttendue && argv[i + 1][0] != '-' )
				{
					fichierMotsClesAttendu = true;
				}
				else if ( argv[i + 1][0] == '-' )
				{
					cerr << "FichierMotCles attendu apres l'option -k" << endl;
					return RET_ERR_ARGS;
				}
				else
				{
					cerr << "Position de l'argument -k invalide" << endl;
					return RET_ERR_ARGS;
				}

				if ( argc < positionAttendue + 3 )
				{
					cerr << "Nombres d'arguments insuffisant" << endl;
					return RET_ERR_ARGS;
				}
			}
			else
			{
				cerr << "Option inconnue" << endl;
				return RET_ERR_ARGS;
			}
		}
		else
		{

			if ( fichierMotsClesAttendu )
			{
				nomFichierMotsCles = argv[i];
				fichierMotsClesAttendu = false;
			}
			else
			{
				nomsFichiers.insert ( argv[i] );
			}
		}
	}

	References ref(exclureMotsCles);
	try
	{
		ref.TraiterFichiers ( nomFichierMotsCles,
		        nomsFichiers );
	}
	catch (Erreur &e)
	{
		cerr << "Erreur" << endl;
		return RET_ERR_LECTURE;
	}

	cout << ref.AfficherResultat ( ) << endl;

	return 0;
} //----- fin de main
