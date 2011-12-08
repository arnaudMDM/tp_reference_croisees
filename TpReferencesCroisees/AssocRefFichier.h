/*************************************************************************
 AssocRefFichier  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par Robin Gicquel et Arnaud Mery de Montigny
 *************************************************************************/

//--- Interface de la classe <AssocRefFichier> (fichier AssocRefFichier.h) ---
#if ! defined ( ASSOCREFFICHIER_H_ )
#define ASSOCREFFICHIER_H_


//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <map>
#include <string>


//------------------------------------------------------------- Constantes


//------------------------------------------------------------------ Types


//------------------------------------------------------------------------ 
// Rôle de la classe AssocRefFichier :
//	La classe permet de représenter une association entre un nom de fichier et
//	une liste de numéro de lignes (aussi appelés références).
//------------------------------------------------------------------------ 

class AssocRefFichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void AjouterReference ( string nomFichier, int numLigne );
	// Mode d'emploi :
	//	Ajoute un numéro de ligne pour un fichier. Si le fichier n'est pas
	//	encore référencé, il est ajouté en tant que clé à la map.
	//
	// Contrat :
	//	Aucun
	//

	string AfficherFichiers ( );
	// Mode d'emploi :
	//	Retourne une chaine de caractère représentant les fichiers avec
	//	les numéros de lignes qui leurs sont liés.
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
	// Mode d'emploi : Destructeur de la classe
	//
	// Contrat :
	//	Aucun


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	string afficherLignes ( vector<int> & lignes );
	// Mode d'emploi :
	//	Retourne une chaine de caractère représentant les numéros de lignes
	//	contenus dans le vector passé en paramètre.
	//
	// Contrat :
	//	Aucun


//----------------------------------------------------- Attributs protégés

	map<string, vector<int> > fichiers;
	// fichiers possède comme clés des noms de fichiers et comme valeur un
	// tableau dynamique d'entiers représentant des numéros de ligne
};


//------------------------ Autres définitions dépendantes de <AssocRefFichier>

#endif // ASSOCREFFICHIER_H_
