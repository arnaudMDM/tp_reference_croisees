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

//------------------------------------------------------ Include personnel
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void AssocRefFichier::AjouterLigne ( int numLigne )
// Algorithme : trivial
{
	lignes.push_back(numLigne);
} //----- Fin de ajouterLigne

string AssocRefFichier::AfficherLignes()
// Algorithme : parcourt du vector
{
	string str = "";
	for (vector<int>::iterator it = lignes.begin(); it < lignes.end(); it++) {
		str += *it + '\t';
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
