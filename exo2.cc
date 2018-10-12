using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "exo2.h"

#ifdef TAB_DYNAMIQUE

/*
  Partie 1. implémentation par tableau dynamique

  initialise un vecteur à d entiers tous nuls
*/


//nomDeLaClasse::NomDeLaMethode il faut lui préciser ou se trouve la méthode
Vector::Vector(int d)
{
  if (d<=1) //juste le cas où d = 1 ou d=0
  {
    cout << "dimension <= 1. Un seul entier (0) sera alloué" << '\n';
    vect = new int [1];
    vect[0]=0;
    dim=1;
    return;
  }
  vect = new int[d];
  dim=d;
  for(int i=0; i<dim;i++)
  {
    vect[i]=0;

  }
}

Vector::Vector(const Vector &v)
{
  dim=v.dim; //on reprend la dimension de v
  vect = new int[dim]; // création d'un tableau pour vect
  for(int i=0; i<dim; i++)
  {
    vect[i]=v.vect[i];
  }
}

Vector::~Vector()
{
  delete []vect;
  vect=NULL;
}

Vector & Vector::operator=(const Vector &v) // Affectation
{
  //si param de droite et de gauche sont les mêmes
  if (this ==&v) //comme c'est des pointeurs on vérifie si il pointe sur le même objet
    return *this;

    // sinon libère l'objet appelant et le construit comme
    //etant une copie de v

    dim=v.dim;
    if(vect)
      delete []vect; //supression du vecteur de this
    vect = new int[dim];
    for (int i=0; i<dim; i++)
      this->vect[i] = v.vect[i]; //copie de v dans le vecteur de this
    return *this;
}

//retourne une référence vers l'ième entier du vecteur
//le retour de référence rend possible la modification des élements du vecteur.
int & Vector::operator [](int i)
{
  if (i<dim  && i>= 0) //vérification si i est dans la limite
    return vect[i];

  cout<<"indice hors limites. Dernières composantes retournée \n";
  return vect[dim-1];
}

//ajoute un entier au vector
Vector &Vector::operator+=(const int i)
{
  int *newVect=new int [dim];
  for(int k=0; k<dim; k++)// copie des composantes du vecteur dans un autre tableau
    newVect[k] = vect[k];
  newVect[dim++]=i; //ajout du nouvel entier à la fin du nouveau tableau
  if(vect)
    delete[] vect;
  vect = newVect;
  return *this;
  /*
    on copie dans un nouveau tableau de 1 plus grand tout les élément du tableau
    existant
    On ajoute l'élément à la fin du tableau
    On supprime le 1er tableau et on retourne le nouveau
  */
}

//opérateur d'affichage
ostream &operator<< (ostream &o, Vector &v)
{
  for (int i=0;i<v.dim;i++)
  {
    o<<v[i]<<" "; // fonctionne car on a surcharger [] sinon v.vect[i]
  }
  cout<<endl;
  return o;
}

//l'opérateur de saisie
//Cet opérateur suppose la connaissance de la taille du vecteur
//l'utilisateur pourra alors entre dim entiers séprés par des espaces ou par des entrées
istream &operator>>(istream &is, Vector &v)
{
  int k=0;
  cout<<"entrer "<< v.getDim() <<" entiers ";
  for (k=0; k<v.getDim(); k++)
  {
    is>>v[k];
  }
  return is;
}

#else

Node::Node(int i)
{
  integer=i;
  nextNode=NULL,
}

Node::~Node()
{
  //fonctionne de manière récursive
  //la destruction d'un noeud entraîne la destruction du noeud suivant
  if(nextNode) delete nextNode;
}

Vector::Vector(int nElm)
{
  head=NULL;
  length=0;
  if(nELm <=0)
  {
    cout<<"Dimension <=0. Vecteurs vide\n";
    return
  }

  for(int i=0; i<nELm;i++)
    (*this)+=0;
  //Ajout des nElm entiers en utilisant l'opérateur += défini ci dessous
  // += redéfini pour des objets donc on utilise pointeur sur this pour avoir l'objet

  //pour un élement alors qu'il fallait pour n element mis en paramètre mettre à 0
  // this->lenght = 1;
  // this->head->integer = d;
  // this->head->nextNode = NULL;
}

Vector::Vector(const Vector &v)
{
  if(!v.head) //cas où v est une liste vide
  {
    head=NULL;
    lenght=0;
    return;
  }
  head=new Node(v.head->integer);//constructeur du premier noeud

  Node*thisCurNode=head; //Curseur pour le vecteur this
  Node*vCurNode=v.head->nextNode; //curseur pour v

  while(vCurNode)
  {
    thisCurNode->nextNode=new Node(vCurNode->integer);
    vCurNode=vCurNode->nextNode;
    thisCurNode=thisCurNode->nextNode;
    /*
      On a le vecteur V est un deuxième vecteur de copie
      On cree deux pointeurs l'un qui va pointer sur les objets de V
      et l'autre sur les objets de la copie
      la boucle fait que les deux poiteurs se déplace dans les vecteurs
      et on affecte l'integer de v au vecteur de copie
    */
  }
}

Vector::~Vector()
{
  delete head; //effacement recursif
  head=NULL;
  lenght=0;

}

//ajout à la fin de la chaîne
Vector &Vector::operator+=(const int i)
{
  Node *newNode=new Node(i);
  if (!head)
    head=newNode;
  else
  {
    Node *n=head;
    //parcourir la liste pour arriver au dernier élément
    while (n->newNode)
      n=n->nextNode;
    //inserer le nouveau noeud
    n->nextNode=newNode;
  }

  lenght++;
  return *this; //retourner le poiteur

  // this->lenght = this->lenght+1;
  // this->head->integer = i;
  // this->head->nextNode = NULL;

  // return this;
}

Vector &Vector::operator=(const Vector &v)
{
  if ((this)==&v) return *this;

  if(head) delete head;

  head=NULL;
  lenght=0;
  Node*n=v.head;
  for(int i=0;i<v.lenght;i++)
  {
    (*this)+=n->integer;
    n=n->newNode;
  }
  return *this;
}

//affichage du ième élément
Vector::int &operetor[](const int index)
{
  Node*n=head;
  for(int i =0;i<index;i++)
    n=n->nextNode;
  return n->integer;

// a tester car peut ne pas fonctionner
  // for(int j =0; j < i;j++)
  // {
  //   this = this->head->nextNode;
  // }
  // return this->head->integer;
}

ostream &operator<<(ostream &o, Vector &v)
{
  Node *curNode=v.head;
  for(int i=0; i< v.lenght; i++)
  {
    o<<curNode->GetInt()<<" ";
    curNode=curNode->getNextNode();
  }
  return o;
}

istream &operator>>(istream &is, Vector &v)
{
  int entry=-1;
  cout<<"entrer "<<v.lenght<<" entiers : ";
  for (int i=0;i<v.lenght;i++)
    is>>v[i];
  return is;
}

#endif

main(int argc, char const *argv[])
{
  Vector v1= Vector(2);
  Vector v2= Vector(4);

  //test différent opérateurs
  cout<<"v1=: "<<v1<<endl;
  cout<<"v2=: "<<v2<<endl;
  v1[0]=56;
  v1[1]=24;
  v1+=3;
  v1[0]=56;
  cout<<"v1=:"<<v1<<endl;
  cout<<"v2=:"<<v2<<endl;

  cin>>v1;

  cout<<"v1=:"<<v1<<endl;

  v2+=67;
  cout<<"v2=:"<<v2<<endl;

  return 0;
}
