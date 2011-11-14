/*************************************************************************
                           AssocFichLigne  -  description
                             -------------------
    début                : 14 nov. 2011
    copyright            : (C) 2011 par arnaud
*************************************************************************/

//---------- Réalisation de la classe <AssocFichLigne> (fichier AssocFichLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "AssocFichLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AssocFichLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string AssocFichLigne::AfficherLignes ( )
// Algorithme :
//
{
	string str = "";
	ostringstream oss;
			for ( vector<int>::iterator it = lignes.begin ( );
			        it != lignes.end ( ); it++ )
			{
				oss << *(it);
				str += ' ' + oss.str();
				oss.str("");
			}

		return str;
} //----- Fin de Méthode

void AssocFichLigne::AjouterLigne ( int numLigne )
// Algorithme :
//
{
	lignes.push_back(numLigne);
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
AssocFichLigne::AssocFichLigne ( const AssocFichLigne & unAssocFichLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AssocFichLigne>" << endl;
#endif
} //----- Fin de AssocFichLigne (constructeur de copie)


AssocFichLigne::AssocFichLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AssocFichLigne>" << endl;
#endif
} //----- Fin de AssocFichLigne


AssocFichLigne::~AssocFichLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AssocFichLigne>" << endl;
#endif
} //----- Fin de ~AssocFichLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
