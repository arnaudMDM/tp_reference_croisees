/*************************************************************************
 References  -  description
 -------------------
 début                : 10 nov. 2011
 copyright            : (C) 2011 par Robin Gicquel et Arnaud Mery de Montigny
 *************************************************************************/

//---------- Interface de la classe <References> (fichier References.h) ------
#if ! defined ( REFERENCES_H_ )
#define REFERENCES_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <set>
#include <vector>
#include <string>
#include "AssocRefFichier.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
enum Erreur
{
	ERREUR_LECTURE
};

//------------------------------------------------------------------------ 
// Rôle de la classe <References>
//References est une classe générale qui permet de connaitre les identificateurs
//d'un ou plusieurs fichiers. Cela est fonction des mots-clés demandés par
//un client ou par défaut, et fonction de l'utilisateur à vouloir connaitre
//les identificateurs présents dans les mots-clés ou qui ne le sont pas.
//
//------------------------------------------------------------------------ 

class References
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void
	        TraiterFichiers ( char * nomFichierMotsCles,
	                set<string> &nomsFichiers );
	// Mode d'emploi :
	//	Calcule les identificateurs souhaités. Le calcul dépend du paramètre
	//  exclureMotsCles qui précise si on veut connaitre
	//	les idenctificateurs présents dans les mots-clés ou les autres.
	//	nomFichierMotsCles est l'adresse du nom de fichier où sont présnts les
	//	mots clés. En l'absence de ce paramètre, le programme prend une liste de
	//	mots clés par défaut. nomsFichiers est un objet de type Set qui comporte
	//	les noms de fichiers à analyser.
	//
	// Contrat :
	//	Aucun

	string AfficherResultat ( );
	// Mode d'emploi :
	//	Affiche Les identificateurs avec les fichiers et les numéros de lignes
	//	qui leurs sont liés.
	//
	// Contrat :
	//	Aucun


	//-------------------------------------------- Constructeurs - destructeur
	References ( const References & unReferences );
	// Mode d'emploi (constructeur de copie) :
	//	Constructeur par copie de la classe.
	//
	// Contrat :
	//	Aucun

	References ( );
	// Mode d'emploi :
	//	Constructeur par défaut de la classe. Affecte la valeur false à
	//	l'attribut exclureMotsCles.
	//
	// Contrat :
	//	Aucun

	References ( bool optExclureMotsCles );
	// Mode d'emploi :
	//	Contructeur de la classe permettant de spécifier la valeur de
	//	exlureMotsCles.
	//
	// Contrat :
	//	Aucun
	//

	virtual ~References ( );
	// Mode d'emploi :
	//	Destructeur de la classe.
	//
	// Contrat :
	//	Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	vector<string> * lireFichierMotsCles ( char * nomFichier );
	// Mode d'emploi :
	//	Lit le fichier nomFichier et retourne les mots-clés présents dans le
	//	fichier.
	//
	// Contrat :
	//	Aucun

	void lireFichier ( const char * nomFichier );
	// Mode d'emploi :
	//	Lit un fichier quelconque et en discerne les identificateurs pour
	//	pouvoir les traiter
	//
	// Contrat :
	//	Aucun

	void traiterMot ( string &mot, const char * nomFichier, int numLigne );
	// Mode d'emploi :
	//	Ajoute le mot ou non en fonction de la valeur de
	//	exclureMotsCles.
	//
	// Contrat :
	//	Aucun

	void ajouterReference ( string &mot, const char * nomFichier, int numLigne );
	// Mode d'emploi :
	//	Ajoute le mot comme identificateur si il n'a pas déjà
	//	été ajouté et le nom de fichier et le numéro de ligne.
	//
	// Contrat :
	//	Aucun


	//----------------------------------------------------- Attributs protégés

	map<string, AssocRefFichier> references;
	// references possède comme clés les identificateurs retenus et pointent vers
	// une instance de la classe AssocRefFichier

	vector<string> * motsCles;
	// Tableau dynamique de mots-clés


	bool exclureMotsCles;
	// Précise si on veut retenir uniquemehnt les mots-clés ou tous les
	// identificateurs sauf les mots-clés.
};

//--------------------------- Autres définitions dépendantes de <References>

#endif // REFERENCES_H_
