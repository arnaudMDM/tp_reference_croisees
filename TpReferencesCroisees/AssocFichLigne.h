/*************************************************************************
 AssocFichLigne  -  description
 -------------------
 début                : 14 nov. 2011
 copyright            : (C) 2011 par arnaud
 *************************************************************************/

//---------- Interface de la classe <AssocFichLigne> (fichier AssocFichLigne.h) ------
#if ! defined ( ASSOCFICHLIGNE_H_ )
#define ASSOCFICHLIGNE_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AssocFichLigne>
//
//
//------------------------------------------------------------------------ 

class AssocFichLigne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string AfficherLignes ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AjouterLigne ( int );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	AssocFichLigne ( const AssocFichLigne & unAssocFichLigne );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	AssocFichLigne ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~AssocFichLigne ( );
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

//--------------------------- Autres définitions dépendantes de <AssocFichLigne>

#endif // ASSOCFICHLIGNE_H_
