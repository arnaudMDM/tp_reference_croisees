/*************************************************************************
                           AssocFichierLigne  -  description
                             -------------------
    début                : 10 nov. 2011
    copyright            : (C) 2011 par rgicquel
*************************************************************************/

//---------- Réalisation de la classe <AssocFichierLigne> (fichier AssocFichierLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AssocFichierLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AssocFichierLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*
AssocFichierLigne & AssocFichierLigne::operator = ( const AssocFichierLigne & unAssocFichierLigne )
// Algorithme :
//
{

} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
AssocFichierLigne::AssocFichierLigne ( const AssocFichierLigne & unAssocFichierLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AssocFichierLigne>" << endl;
#endif
} //----- Fin de AssocFichierLigne (constructeur de copie)


AssocFichierLigne::AssocFichierLigne ( ) :
		numLigne ( 0 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AssocFichierLigne>" << endl;
#endif
} //----- Fin de AssocFichierLigne


AssocFichierLigne::~AssocFichierLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AssocFichierLigne>" << endl;
#endif
} //----- Fin de ~AssocFichierLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
