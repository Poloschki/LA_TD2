#ifndef _exo2_H
#define _exo2_H

#include <iostream>
using namespace std;
/*
  fichier .h équivalent en C on met juste les déclarations des méthodes
  dans les arguments des méthodes il suffit de mettre le type de retour
  On est pas obligé de mettre le nom car car le fichier .cc tout sera
  redéfinie (?)
*/


/*
Constantes macro qui permet de choisir l'implémentatoin à compiler
Si cette def est faite, c'est l'implémentation par tableau
dynamique qui est réalisée.
Pour l'implémentation par liste chaînée, il suffit de mettre en commentaire
la def de TAB_DYNAMIQUE

*/
#define TAB_DYNAMIQUE
#ifdef TAB_DYNAMIQUE //mot spécial pour les fichiers .h On ne peut pas mettre ifndef
  //ifndef sert uniquement pour le nom du fichier

//implémentation du vecteur
class Vector {
  private:
    int *vect;
    int dim; //taille du vecteur = nb de composantes (ou entiers)


  public:
    Vector (int d);
    Vector(const Vector &v); //de copie

  ~Vector ();

  Vector &operateur=(const Vector &); //surcharge de l'opérateur =
  int & operateur [](int i); //retourne le ième élement
  Vector &operateur+=(const int); //ajoute un entier au vecteur

//la fonction ostream va récupérer élemnt du vecteur, sauf que les attributs sont privé
//donc on crée un lien d'amitié pour permetre à ostream d'accéder au constructeurs privé
    friend ostream &operateur <<(ostream &o, Vector &v);//surcharge de l'opérateur d'affichage
    friend iostream &operateur >>(iostream &is, Vector &v);//opérateur de saisie
};
/*
  Si on ne veut pas utiliser le tableau dynamique on va aller dans le else
*/
#else

class Node {
  friend class Vector; //le vecteur sera une classe amie de Node
  // pour accéder facilement aux attributs
  /*
    les fils de Node ne peuvent pas accéder aux élément de Vector
  */

private:
  int integer;
  Node *nextNode;

public:
  Node (int);
  int GetInt(){return integer;} //on peut dans le fichier .h définir les fonctions
  Node * GetNextNode(){return nextNode;}
  //Nous voyont que nous pouvons définir une partie des méthodes
  //dans la classe elle-même et laisser les autres pour l'implémentation
  ~Node ();
};

class Vector {

  public:
    Node *head;
    int lenght; //dimension du vecteur

    Vector (int);
    Vector(const Vector &v); //de copie
    ~Vector ();

    //fonction de gestion de la liste chaînée
    Vector &operateur+=(const int);//Ajoute un entier à la fin de la liste
    Vector &operateur=(const Vector &); //Affectation
    int & operateur [](const int);
    friend ostream &operateur <<(ostream &o, Vector &v);
    friend istream &operateur >>(istream &is, Vector &v);
};

#endif
#endif
