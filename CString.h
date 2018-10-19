/*=============================================================
 *               Classes CString et Definition                *
 *             (exo 6, 7 du TD1 et exo 1 du TD2)              *
 *            -----------------------------------    		  *
 *													          *
 * Fichier ent�te .					                          *
 *															  *
 * Le code est parsem� de commentaires qui serviront �        *    
 * expliquer le code, � clarifier certaines notions de C++ ou *
 * � proposer d'autres alternatives possibles de solution.    *
 *												Walid Ben     *
 *============================================================*/

//Pour eviter des declarations multiples ou recursives
#ifndef _TD2_H
#define _TD2_H

using namespace std;
#include <iostream>
//#include <stdlib.h>
//#include <math.h>

//===============
//Classe CString 
//===============
class CString
{
//Attributs
private:
	char * string; //pointeur vers la cha�ne qui sera dans la m�moire dynamique.
	unsigned short length; //taille de la cha�ne.
public:
	static unsigned long nChaines; //nombre de cha�nes cr��es

//M�thodes
public:
	// constructeurs
	CString();	//Initialise une chaine vide.
	CString(const char *const);//Constructeur a partir d'une chaine
	CString(const CString &);//Constructeur de copie
	CString(char );	//Constructeur a partir d'un char

	//destructeur
	~CString();	

	const char *GetString() const;
	static unsigned long nbrChaines();
	CString plus(const CString &s);//La concatenation ne change pas l'objet appelant
	CString plus(char );//Concatene le caractere a la fin de la chaine
	//Surcharge de l'op�rateur + qui fait le m�me travail que la fonction plus.
	CString operator +(CString &);	
	CString& operator=(const CString & );//Operateur d'affectation
	bool PlusGrandQue(const CString & );
	bool operator > (CString &);
	bool InfOuEgal(const CString & );
	bool operator <= (CString &);
	CString PlusGrand(const CString &);
	friend ostream & operator <<(ostream &, CString &);
};
//==========================================================================

#endif
