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

//------------------------------------------------------ Include personnel
#include "References.h"
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes
const int TAILLE_MAX_MOT = 50;
const char DELIM[] = {
        ' ', '\t', '\n', ';', ':', ',', '.', '<', '>', '=', '{', '}', '(', ')',
        '!', '-', '+', '/', '*', '&', '|', '%', '$', '#' };
const char TAILLE_DELIM = 24;
const string MOTS_CLES_C[] = {
        "asm", "auto", "bool", "break", "case", "catch", "char", "class",
        "const", "const_char", "continue", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false",
        "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "operator", "private", "protected",
        "public", "register", "reinterpret_cast", "return", "short", "signed",
        "sizeof", "static", "static_cast", "struct", "switch", "template",
        "this", "throw", "true", "try", "typedef", "typeid", "typename",
        "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t",
        "while" };
const int TAILLE_MOTS_CLES_C = 63;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void References::TraiterFichiers ( char * nomFichierMotsCles,
        vector<char *> &nomsFichiers )
// Algorithme :
//
{
	if ( nomFichierMotsCles != NULL )
	{
		lireFichierMotsCles ( nomFichierMotsCles );
	}
	else
	{
		motsCles = new vector<string> ( MOTS_CLES_C,
		        MOTS_CLES_C + TAILLE_MOTS_CLES_C );
	}

	for ( vector<char *>::iterator it = nomsFichiers.begin ( );
	        it < nomsFichiers.end ( ); it++ )
	        {
		lireFichier ( *it );
	}
} //----- Fin de TraiterFichiers

string References::AfficherResultat ( )
// Algorithme :
//
{
	string str = "";
	for (map<string, AssocRefFichier>::iterator it = references.begin(); it != references.end(); it++) {
		str += it->first + " : " + it->second.AfficherLignes() + '\n';
	}

	return str;
}

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
	char str[TAILLE_MAX_MOT + 1];vector<string> * motsCles = new vector<string>;
	ifstream lecture;

	lecture.open ( nomFichier );

	if (lecture.fail())
	{
		Erreur e = ERREUR_LECTURE;
		delete motsCles;
		throw e;
	}

	while (!lecture.eof ( ))
	{
		lecture.getline ( str, TAILLE_MAX_MOT );

		if ( strchr ( str, ' ' ) != NULL || strchr ( str, ',' ) != NULL
				|| strchr ( str, ';' ) != NULL )
		{
			Erreur e = ERREUR_LECTURE;
			delete motsCles;
			throw e;
		}

		motsCles->push_back ( str );
	}

	lecture.close();

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
					lecture.get ( );
				}
				else if ( c2 == '*' )
				{
					carAttendu1 = '*';
					carAttendu2 = '/';
					lecture.get ( );
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
			else if ( find ( DELIM, DELIM + TAILLE_DELIM, c )
			        == DELIM + TAILLE_DELIM )
			{
				mot.push_back ( c );
			}
			else
			{
				traiterMot ( mot, numLigne );
				mot = "";
			}
		}
		else
		{
			if ( c == carAttendu1 )
			{
				if ( carAttendu2 == -1 )
				{
					carAttendu1 = -1;
				}
				else
				{
					if ( lecture.peek ( ) == carAttendu2 )
					{
						carAttendu1 = -1;
						carAttendu2 = -1;
						if ( lecture.get ( ) == '\n' )
						{
							numLigne++;
						}
					}
				}
			}
		}

		if ( c == '\n' )
		{
			numLigne++;
		}
	}
} //----- Fin de lireFichier

void References::traiterMot ( string &mot, int numLigne )
{
	if ( find ( motsCles->begin ( ), motsCles->end ( ), mot )
	        != motsCles->end ( ) )
	{
		if ( !exclureMotsCles )
		{
			ajouterReference ( mot, numLigne );
		}
	}
	else if ( exclureMotsCles )
	{
		ajouterReference ( mot, numLigne );
	}
}

void References::ajouterReference ( string &mot, int numLigne )
{
	AssocRefFichier * assoc = new AssocRefFichier ( );
	pair<map<string, AssocRefFichier>::iterator, bool> paire;
	paire = references.insert (
	        pair<string, AssocRefFichier> ( mot, *(assoc) ) );
	map<string, AssocRefFichier>::iterator it = paire.first;

	it->second.AjouterLigne ( numLigne );
}
