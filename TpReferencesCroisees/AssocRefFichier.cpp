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

//------------------------------------------------------ Include personnel
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AssocRefFichier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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
