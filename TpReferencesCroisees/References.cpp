/*************************************************************************
 References  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par rgicquel
 *************************************************************************/

//---------- Réalisation de la classe <References> (fichier References.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include "AssocRefFichier.h"

//------------------------------------------------------ Include personnel
#include "References.h"

//------------------------------------------------------------- Constantes
const int TAILLE_MAX_MOT = 50;
const char DELIM[] = {
        ' ', '\t', '\n', ';', ':', ',', '.', '<', '>', '=', '{', '}', '(', ')',
        '!', '-', '+', '/', '*', '&', '|', '%', '$', '#' };
const char TAILLE_DELIM = 24;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type References::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*
 References & References::operator = ( const References & unReferences )
 // Algorithme :
 //
 {
 } //----- Fin de operator =
 */

//-------------------------------------------- Constructeurs - destructeur
References::References ( const References & unReferences )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <References>" << endl;
#endif
} //----- Fin de References (constructeur de copie)


References::References ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <References>" << endl;
#endif
} //----- Fin de References


References::~References ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <References>" << endl;
#endif
	delete motsCles;
} //----- Fin de ~References


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
vector<string> * References::lireFichierMotsCles ( char * nomFichier )
// Algorithme :
//
{
	char * str = new char[TAILLE_MAX_MOT + 1];
	vector<string> * motsCles = new vector<string> ;
	ifstream lecture;

	lecture.open ( nomFichier );

	while (!lecture.eof ( ))
	{
		lecture.getline ( str, TAILLE_MAX_MOT );

		if ( strchr ( str, ' ' ) != NULL || strchr ( str, ',' ) != NULL
		        || strchr ( str, ';' ) != NULL )
		{
			throw 15;
		}

		motsCles->push_back ( str );
	}

	return motsCles;
} //----- Fin de lireFichierMotsCles

void References::lireFichier ( char * nomFichier )
// Algorithme :
//
{
	ifstream lecture;
	string mot = "";
	int numLigne = 1;

	int c;
	char carAttendu1 = -1;
	char carAttendu2 = -1;

	lecture.open ( nomFichier );

	while (!lecture.eof ( ))
	{
		c = lecture.get ( );

		if ( carAttendu1 == -1 )
		{
			if ( c == '/' )
			{
				char c2 = lecture.peek ( );
				if ( c2 == '/' )
				{
					carAttendu1 = '\n';
					numLigne++;
					lecture.get();
				}
				else if ( c2 == '*' )
				{
					carAttendu1 = '*';
					carAttendu2 = '/';
					lecture.get();
				}
			}
			else if ( c == '"' )
			{
				carAttendu1 = '"';
			}
			else if ( c == '\'' )
			{
				carAttendu1 = '\'';
			}
			else if ( find ( DELIM, DELIM + TAILLE_DELIM, c ) == DELIM
			        + TAILLE_DELIM )
			{
				mot << c;
			}
			else
			{
				traiterMot ( mot );
				mot = "";
			}
		}
		else
		{
			if (c == carAttendu1) {
				if (carAttendu2 == -1) {
					carAttendu1 = -1;
				}
				else {
					if (lecture.peek() == carAttendu2) {
						carAttendu1 = -1;
						carAttendu2 = -1;
						if (lecture.get() == '\n') {
							numLigne++;
						}
					}
				}
			}
		}

		if (c == '\n') {
			numLigne++;
		}
	}
} //----- Fin de lireFichier

void References::traiterMot ( string &mot )
{
	if ( find ( motsCles->begin ( ), motsCles->end ( ), mot )
	        != motsCles->end ( ) )
	{
		if ( !exclureMotsCles )
		{
			//ajouter aux references
		}
	}
	else if ( exclureMotsCles )
	{
		//ajouter aux references
	}
}

void References::ajouterReference ( string &mot )
{
	AssocRefFichier * assoc = new AssocRefFichier ();
	pair<map<string, AssocRefFichier>::iterator, bool> paire;
	paire = references.insert ( pair<string, AssocRefFichier>(mot, *(assoc)));
	map<string, AssocRefFichier>::iterator it = paire.first;

	it->second->ajouterLigne(numLigne);
}
