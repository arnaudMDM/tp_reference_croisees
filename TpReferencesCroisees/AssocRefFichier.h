/*************************************************************************
 AssocRefFichier  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par Robin Gicquel et Arnaud Mery de Montigny
 *************************************************************************/

//---------- Interface de la classe <AssocRefFichier> (fichier AssocRefFichier.h) ------
#if ! defined ( ASSOCREFFICHIER_H_ )
#define ASSOCREFFICHIER_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <map>
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AssocRefFichier>
//La classe permet de lier des fichiers à un tableau d'entier
//
//
//------------------------------------------------------------------------ 

class AssocRefFichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void TraiterFichier ( string nomFichier, int numLigne );
	// Mode d'emploi :Lie le nom nomFichier à un tableau d'entier
	//en ajoutant l'entier numLigne à cet objet.
	//
	// Contrat :
	//

	string AfficherFichiers ( );
	// Mode d'emploi : Retourne une chaine de caractère représentant
	//les fichiers avec les numéros de lignes qui leurs sont liés
	//
	// Contrat :
	//

	string AfficherLignes (vector<int> lignes);
	// Mode d'emploi : Retourne une chaine de caractère représentant des
	//numéros de lignes
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	AssocRefFichier ( const AssocRefFichier & unAssocRefFichier );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	AssocRefFichier ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~AssocRefFichier ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	//fichiers possède comme clés des noms de fichiers et pointent vers un
	//un tableau d'entier
	map<string, vector<int> > fichiers;
};

//--------------------------- Autres définitions dépendantes de <AssocRefFichier>

#endif // ASSOCREFFICHIER_H_
