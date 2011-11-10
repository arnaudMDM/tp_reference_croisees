/*************************************************************************
 AssocRefFichier  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par rgicquel
 *************************************************************************/

//---------- Interface de la classe <AssocRefFichier> (fichier AssocRefFichier.h) ------
#if ! defined ( ASSOCREFFICHIER_H_ )
#define ASSOCREFFICHIER_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AssocRefFichier>
//
//
//------------------------------------------------------------------------ 

class AssocRefFichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void AjouterLigne ( int numLigne );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string AfficherLignes ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	AssocRefFichier & operator = ( const AssocRefFichier & unAssocRefFichier );
	// Mode d'emploi :
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
	vector<int> lignes;
};

//--------------------------- Autres définitions dépendantes de <AssocRefFichier>

#endif // ASSOCREFFICHIER_H_
