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
#include <vector>
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "AssocRefFichier.h"
#include "AssocFichLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void AssocRefFichier::TraiterFichier ( string nomFichier, int numLigne )
// Algorithme : trivial
{
	AssocFichLigne * assoc = new AssocFichLigne;
	pair<map<string, AssocFichLigne>::iterator, bool> paire;
	paire = fichiers.insert (
	        pair<string, AssocFichLigne> ( nomFichier, *(assoc) ) );
	map<string, AssocFichLigne>::iterator it = paire.first;
	it->second.AjouterLigne ( numLigne );
} //----- Fin de ajouterLigne

string AssocRefFichier::AfficherFichiers ( )
// Algorithme : parcourt du vector
{
	string str = "";
	for ( map<string, AssocFichLigne>::iterator it = fichiers.begin ( );
	        it != fichiers.end ( ); it++ )
	{
		str += '\t' + it->first + it->second.AfficherLignes ( );
	}

	return str;
}

//------------------------------------------------- Surcharge d'opérateurs
/*
 AssocRefFichier & AssocRefFichier::operator = ( const AssocRefFichier & unAssocRefFichier )
 // Algorithme :
 //
 {
 } //----- Fin de operator =*/

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
