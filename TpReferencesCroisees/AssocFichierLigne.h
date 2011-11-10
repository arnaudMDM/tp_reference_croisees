/*************************************************************************
                           AssocFichierLigne  -  description
                             -------------------
    début                : 10 nov. 2011
    copyright            : (C) 2011 par rgicquel
*************************************************************************/

//---------- Interface de la classe <AssocFichierLigne> (fichier AssocFichierLigne.h) ------
#if ! defined ( ASSOCFICHIERLIGNE_H_ )
#define ASSOCFICHIERLIGNE_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AssocFichierLigne>
//
//
//------------------------------------------------------------------------ 

class AssocFichierLigne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    AssocFichierLigne & operator = ( const AssocFichierLigne & unAssocFichierLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AssocFichierLigne ( const AssocFichierLigne & unAssocFichierLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AssocFichierLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AssocFichierLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int numLigne;
};

//--------------------------- Autres définitions dépendantes de <AssocFichierLigne>

#endif // ASSOCFICHIERLIGNE_H_
