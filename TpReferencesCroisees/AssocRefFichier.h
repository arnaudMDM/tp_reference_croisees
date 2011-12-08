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
//	La classe permet de lier des fichiers à un tableau d'entier
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
	//	Aucun
	//

	string AfficherFichiers ( );
	// Mode d'emploi :
	//	Retourne une chaine de caractère représentant
	//	les fichiers avec les numéros de lignes qui leurs sont liés
	//
	// Contrat :
	//	Aucun

//-------------------------------------------- Constructeurs - destructeur
	AssocRefFichier ( const AssocRefFichier & unAssocRefFichier );
	// Mode d'emploi (constructeur de copie) :
	//	Constructeur par copie de la classe.
	//
	// Contrat :
	//	Aucun

	AssocRefFichier ( );
	// Mode d'emploi :
	//	Constrcuteur par défaut de la classe
	//
	// Contrat :
	//	Aucun

	virtual ~AssocRefFichier ( );
	// Mode d'emploi : Destrcteur de la classe
	//
	// Contrat : Aucun

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	string AfficherLignes (vector<int> lignes);
	// Mode d'emploi : Retourne une chaine de caractère représentant des
	//numéros de lignes
	//
	// Contrat :
	//	Aucun

//----------------------------------------------------- Attributs protégés

	//fichiers possède comme clés des noms de fichiers et pointent vers un
	//un tableau d'entier
	map<string, vector<int> > fichiers;
};

//--------------------------- Autres définitions dépendantes de <AssocRefFichier>

#endif // ASSOCREFFICHIER_H_
