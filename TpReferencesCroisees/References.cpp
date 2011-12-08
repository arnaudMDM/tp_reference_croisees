/*************************************************************************
 References  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par Robin Gicquel et Arnaud Mery de Montigny
 *************************************************************************/

//------- Réalisation de la classe <References> (fichier References.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
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
static const char DELIM[] = {
        ' ', '\t', '\r', '\n', ';', ':', ',', '.', '<', '>', '=', '{', '}',
        '(', ')', '!', '-', '+', '/', '*', '&', '|', '%', '$', '#', '[', ']' };
static const char TAILLE_DELIM = 27;
static const string MOTS_CLES_C[] = {
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
static const int TAILLE_MOTS_CLES_C = 63;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void References::TraiterFichiers ( char * nomFichierMotsCles,
        set<string> &nomsFichiers )
// Algorithme : Trivial
{
	if ( nomFichierMotsCles != NULL )
	{
		lireFichierMotsCles ( nomFichierMotsCles );
	}
	else
	{
		// remplissage du vector à partir du tableau constant de mots-clés
		motsCles = new vector<string> ( MOTS_CLES_C, MOTS_CLES_C
		        + TAILLE_MOTS_CLES_C );
	}

	for ( set<string>::iterator it = nomsFichiers.begin ( ); it
	        != nomsFichiers.end ( ); it++ )
	{
		const char * truc = it->c_str ( );
		lireFichier ( truc );
	}
} //----- Fin de TraiterFichiers

string References::AfficherResultat ( )
// Algorithme : Trivial
{
	string str = "";
	for ( map<string, AssocRefFichier>::iterator it = references.begin ( ); it
	        != references.end ( ); it++ )
	{
		str += it->first + it->second.AfficherFichiers ( ) + '\n';
	}

	return str;
} //----- Fin de AfficherResultat


//-------------------------------------------- Constructeurs - destructeur
References::References ( const References & unReferences )
// Algorithme : Trivial
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <References>" << endl;
#endif
} //----- Fin de References (constructeur de copie)

References::References ( )
// Algorithme : Trivial
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <References>" << endl;
#endif
} //----- Fin de References (contructeur par défaut)

References::References ( bool optExclureMotsCles ) :
	exclureMotsCles ( optExclureMotsCles )
// Algorithme : Trivial
{
#ifdef MAP
	cout << "Appel au constructeur de <References>" << endl;
#endif
} //----- Fin de References

References::~References ( )
// Algorithme : Trivial
{
#ifdef MAP
	cout << "Appel au destructeur de <References>" << endl;
#endif
	delete motsCles;
} //----- Fin de ~References

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
vector<string> * References::lireFichierMotsCles ( char * nomFichier )
// Algorithme : Lecture ligne par ligne d'un fichier
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

		// Ajoute les caractères en provenance du flux jusqu'à trouver une
		// fin de ligne
		while ((c = lecture.get ( )) != '\n' && c != '\r' && c != -1)
		{
			str.push_back ( c );
		}

		// Vide le "buffer" des éventuels '\n' et '\r' restants
		while ((c = lecture.peek ( )) == '\n' || c == '\r')
		{
			lecture.get ( );
		}

		if ( str.find ( ' ' ) == 0 || str.find ( ',' ) == 0 || str.find ( ';' )
		        == 0 || str.find ( '\t' ) == 0 )
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
// Algorithme : Lecture caractère par caratère d'un fichier avec détection des
// commentaires. Dès qu'un mot est isolé, il est recherché dans la liste des
// mots clés et ajouté aux références en fonction des options fournies
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
			        + TAILLE_DELIM ) // Recherche du mot lu dans les mots-clés
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

void References::traiterMot ( string &mot, const char * nomFichier,
        int numLigne )
// Algorithme : Trivial, point délicat détaillé dans le corps
{
	const char * motC = mot.c_str ( );
	char ** retourStrtod = new char*;

	// Pour vérifier si motC n'est pas un nombre, on teste s'il s'agit d'un
	// réel. Pour cela, on utilise la fonction C strtod qui renvoie 0.0 si la
	// chaîne passée en paramètre ne correspond pas à un nombre réel. Pour
	// différencier la lecture de la chaîne "0" et celle d'une chaîne quelconque
	// ne correspondant pas à un nombre réel, la fonction affecte l'adresse du
	// premier paramètre passé à la valeur du second paramètre passé. Ainsi, en
	// vérifiant que *retourStrtod est égal à motC, on est assuré que le mot est
	// ou n'est un nombre.
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
} //----- Fin de traiterMot

void References::ajouterReference ( string &mot, const char * nomFichier,
        int numLigne )
// Algorithme : Trivial
{
	AssocRefFichier * assoc = new AssocRefFichier ( );

	pair<map<string, AssocRefFichier>::iterator, bool> paire;

	paire
	        = references.insert (
	                pair<string, AssocRefFichier> ( mot, *(assoc) ) );

	map<string, AssocRefFichier>::iterator it = paire.first;

	it->second.AjouterReference ( nomFichier, numLigne );

	delete assoc;

} //----- Fin de ajouterReference
