/*************************************************************************
 AssocRefFichier  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par rgicquel
 *************************************************************************/

//---------- Réalisation de la classe <AssocRefFichier> (fichier AssocRefFichier.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void AssocRefFichier::TraiterFichier ( string nomFichier, int numLigne )
// Algorithme : trivial
{
	vector<int> * vec = new vector<int>;
	pair<map<string, vector<int> >::iterator, bool> paire;
	paire = fichiers.insert (
	        pair<string, vector<int> > ( nomFichier, *(vec) ) );
	map<string, vector<int> >::iterator it = paire.first;
	it->second.push_back(numLigne);

	delete vec;
} //----- Fin de ajouterLigne

string AssocRefFichier::AfficherFichiers ( )
// Algorithme : parcourt du vector
{
	string str = "";
	for ( map<string, vector<int> >::iterator it = fichiers.begin ( );
	        it != fichiers.end ( ); it++ )
	{
		str += '\t' + it->first + AfficherLignes (it->second);
	}


	return str;
}

string AssocRefFichier::AfficherLignes (vector<int> lignes)
// Algorithme :
//
{
	string str = "";
	ostringstream oss;
	for ( vector<int>::iterator it = lignes.begin ( ); it != lignes.end ( );
	        it++ )
	{
		oss << *(it);
		str += ' ' + oss.str ( );
		oss.str ( "" );
	}

	return str;
} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur
AssocRefFichier::AssocRefFichier ( const AssocRefFichier & unAssocRefFichier )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <AssocRefFichier>" << endl;
#endif
} //----- Fin de AssocRefFichier (constructeur de copie)

AssocRefFichier::AssocRefFichier ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <AssocRefFichier>" << endl;
#endif
} //----- Fin de AssocRefFichier

AssocRefFichier::~AssocRefFichier ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <AssocRefFichier>" << endl;
#endif
} //----- Fin de ~AssocRefFichier

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
