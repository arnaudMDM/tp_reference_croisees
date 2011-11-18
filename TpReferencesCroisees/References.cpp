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
#include <string>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "References.h"
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes
const int TAILLE_MAX_MOT = 50;
const char DELIM[] = {
        ' ', '\t', '\r', '\n', ';', ':', ',', '.', '<', '>', '=', '{', '}',
        '(', ')', '!', '-', '+', '/', '*', '&', '|', '%', '$', '#','[', ']' };
const char TAILLE_DELIM = 27;
const string MOTS_CLES_C[] = {
        "asm", "auto", "bool", "break", "case", "catch", "char", "class",
        "const", "const_char", "continue", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int",
        "long", "mutable", "namespace", "new", "operator", "private",
        "protected", "public", "register", "reinterpret_cast", "return",
        "short", "signed", "sizeof", "static", "static_cast", "struct",
        "switch", "template", "this", "throw", "true", "try", "typedef",
        "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
        "volatile", "wchar_t", "while" };
const int TAILLE_MOTS_CLES_C = 63;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void References::TraiterFichiers ( bool optExclureMotsCle,
        char * nomFichierMotsCles, set<string> &nomsFichiers )
// Algorithme :
//
{
	exclureMotsCles = optExclureMotsCle;

	if ( nomFichierMotsCles != NULL )
	{
		lireFichierMotsCles ( nomFichierMotsCles );
	}
	else
	{
		motsCles = new vector<string> ( MOTS_CLES_C, MOTS_CLES_C
		        + TAILLE_MOTS_CLES_C );
	}

	for ( set<string>::iterator it = nomsFichiers.begin ( ); it
	        != nomsFichiers.end ( ); it++ )
	{
		const char * truc = it->c_str();
		lireFichier ( truc );
	}
} //----- Fin de TraiterFichiers

string References::AfficherResultat ( )
// Algorithme :
//
{
	string str = "";
	for ( map<string, AssocRefFichier>::iterator it = references.begin ( ); it
	        != references.end ( ); it++ )
	{
		str += it->first + it->second.AfficherFichiers ( ) + '\n';
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
	string str;
	char c;
	motsCles = new vector<string> ;
	ifstream lecture;

	lecture.open ( nomFichier );

	if ( lecture.fail ( ) )
	{
		Erreur e = ERREUR_LECTURE;
		throw e;
	}

	while (!lecture.eof ( ))
	{
		str = "";

		// ajoute les caractères en provenance du flux jusqu'à trouver une fin de ligne
		while ((c = lecture.get ( )) != '\n' && c != '\r' && c != -1)
		{
			str.push_back ( c );
		}

		// vide le "buffer" des éventuels '\n' et '\r' restants
		while ((c = lecture.peek ( )) == '\n' || c == '\r')
		{
			lecture.get();
		}

		if ( str.find ( ' ' ) == 0 || str.find ( ',' ) == 0 || str.find ( ';' )
		        == 0 )
		{
			Erreur e = ERREUR_LECTURE;
			throw e;
		}

		motsCles->push_back ( str );
	}

	lecture.close ( );

	return motsCles;
} //----- Fin de lireFichierMotsCles

void References::lireFichier ( const char * nomFichier )
// Algorithme :
//
{
	ifstream lecture;
	string mot = "";
	int numLigne = 1;

	int c;
	int c2;
	char carAttendu1 = -1;
	char carAttendu2 = -1;

	lecture.open ( nomFichier );

	if ( lecture.fail ( ) )
	{
		Erreur e = ERREUR_LECTURE;
		throw e;
	}

	while (!lecture.eof ( ))
	{
		c = lecture.get ( );

		if ( carAttendu1 == -1 )
		{
			if ( c == '/' )
			{
				c2 = lecture.peek ( );
				if ( c2 == '/' )
				{
					carAttendu1 = '\n';
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
			else if ( find ( DELIM, DELIM + TAILLE_DELIM, c ) == DELIM
			        + TAILLE_DELIM )
			{
				mot.push_back ( c );
			}
			else
			{
				if ( mot != "" )
				{
					traiterMot ( mot, nomFichier, numLigne );
					mot.clear ( );
				}
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

		if ( lecture.peek ( ) == '\n' )
		{
			numLigne++;
		}
	}
} //----- Fin de lireFichier

void References::traiterMot ( string &mot, const char * nomFichier, int numLigne )
{
	const char * motC = mot.c_str ( );
	char ** retourStrtod = (char**) malloc ( sizeof(char*) );

	if ( strtod ( motC, retourStrtod ) == 0.0 && *retourStrtod == motC )
	{
		if ( find ( motsCles->begin ( ), motsCles->end ( ), mot )
		        != motsCles->end ( ) )
		{
			if ( !exclureMotsCles )
			{
				ajouterReference ( mot, nomFichier, numLigne );
			}
		}
		else if ( exclureMotsCles )
		{
			ajouterReference ( mot, nomFichier, numLigne );
		}
	}

	delete retourStrtod;
}

void References::ajouterReference ( string &mot, const char * nomFichier,
        int numLigne )
//
{
	AssocRefFichier * assoc = new AssocRefFichier ( );
	pair<map<string, AssocRefFichier>::iterator, bool> paire;
	paire
	        = references.insert (
	                pair<string, AssocRefFichier> ( mot, *(assoc) ) );
	map<string, AssocRefFichier>::iterator it = paire.first;

	it->second.TraiterFichier ( nomFichier, numLigne );

	delete assoc;

}
