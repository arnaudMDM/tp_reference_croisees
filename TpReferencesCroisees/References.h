/*************************************************************************
 References  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par rgicquel
 *************************************************************************/

//---------- Interface de la classe <References> (fichier References.h) ------
#if ! defined ( REFERENCES_H_ )
#define REFERENCES_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <vector>
#include <string>
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
enum Erreur {ERREUR_LECTURE};

//------------------------------------------------------------------------ 
// Rôle de la classe <References>
//
//
//------------------------------------------------------------------------ 

class References
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void TraiterFichiers(char * nomFichierMotsCles, vector<char *> nomFichiers);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'opérateurs
	References & operator = ( const References & unReferences );
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	References ( const References & unReferences );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	References ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~References ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées
	vector<string> * lireFichierMotsCles ( char * nomFichier );
	void lireFichier ( char * nomFichier );
	void traiterMot ( string &mot, int numLigne );
	void ajouterReference ( string &mot, int numLigne );

	//----------------------------------------------------- Attributs protégés
	map<string, AssocRefFichier> references;
	vector<string> * motsCles;
	bool exclureMotsCles;
};

//--------------------------- Autres définitions dépendantes de <References>

#endif // REFERENCES_H_
