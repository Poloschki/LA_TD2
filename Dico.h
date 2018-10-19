#ifndef DICO_H
#define DICO_H

#include <CString.h>
#include <iostream>
using namespace std;


class Definition
{
    //attributs
    private:
        CString clef;
        CString definition;


    public:
        Definition(char *, char *);
        CString GetClef() const;
        CString GetDef() const;
        ~Definition();
};


class Node
{
    friend class Dico;
    //variable membre
private:
    Definition *def; 
    /*
        Pointeur vers la définition. Ceci permet la séparation entre la structure
        de chaîne et les données manipulées. Cela permettra ce qu'on appelle le 
        "stockage externe" voir l'explication au début de la classe Dico ci dessous
    */
public:
    Node(Definition *); 
    ~Node();
    Definition *GetDef(){return def;};
    Node * GetNextNode(){return nextNode;};
};

/*
Dico implémente une liste chaînée de définition
ELle contient un champ spécial : IsOwner
Por comprendre ce champ, expliquons d'abord les deux notions suivantes: 
Stockage interne et stockage externe.

En effet, les données d'une liste chaînée sont comminément stocjées dans les noeuds
de la lsite, comme c'était le cas avec la classe Vector de l'exo2 du TD2.
C'est le cas d'un stockage interne.
Cependant, en stockage externe, le noeud contien uniquement un pointeur vers les données
Cela facilitera la construction de plusieurs listes utilisant les mêmes données.
En plus, cela permttra une implémentation générique de la minipulation d'une liste
independemment de la nature des données utilisées 

Dans la liste Dico, on utilise bien le stockage externe puisque la classe Node
contient un pointeur vers la définition. La variable booléenne isOwner précise
si le dictionnaire contrôle (possède) les définitions. Si c'est le cas,
tout effacement de noeud devra en même temps effacer la définition pointée.
Dans le cas contraire, les données seront toujours intactes indépendamment 
des noeuds de la liste
*/


class Dico
{
private:
    Node *head;
    int lenght;
    bool isOwner;

    void Destroy(Node *); // méthode récursive privée qui sera appelée par le destructeur
public:
    Dico(bool=true); //paramètre optionnel lors de l'appel, par défaut true 
    ~Dico();
    void AddDef(Definition*); //ajout d'une définition
    int GetLenght(){return lenght;};

    CString GetDef(CString &);//Recherche une définition
    Definition* GetRandDef();//Retourne une définition aléatoire
    void Display();
    friend ostream & operator<<(ostream &, Dico &); //doit être un friend sinon le compilateur ne fait pas la différence
};

#endif