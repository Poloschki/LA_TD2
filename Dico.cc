#include "Dico.h"

Definition::Definition(char *m, char *def)
{
    clef = CString(m);
    definition = CString(def);
}

CString Definition::GetClef() const
{
    return clef;
}

CString Definition::GetDef() const
{
    return definition;
}

Definition::~Definition()
{
    cout<<"dest "<<clef.GetString()<<"-";
}

// Classe NODE 

Node::Node(Definition *d)
{
    def=d;
    nextNode=NULL;
}

Node::~Node()
{
    cout<<"destNode~";
    //On ne fait rien car la destruction ce fait dans la classe Dico
}

// Classe Dico 

void Dico::Destroy(Node *n)
{
    /*
        si la deuxième liste possède les éléments de la liste principale,
        ici n, on peut alors supprimer 
    */
    if(n)
    {
        if(isOwner && n->def) //si la liste possède les données, il faut les effacer
            delete n->def;
        Destroy(n->nextNode);
        delete n;
    }
}

//ajout d'une définition dans l'ordre lexicographique
void Dico::AddDef(Definition*newDef)
{
    if(!newDef)
        return; // si vide
    
    Node* newNode=new Node(newDef);
    CString entry=newDef->GetClef();
    Node *curNode=head;
    Node * temp;
    while(temp=curNode->nextNode)
    {
        CString curClef=temp->def->GetClef();
        if(curClef>entry)
            break;
        curNode=curNode->nextNode;
    }

    newNode->nextNode=temp;
    curNode->nextNode=newNode;
    lenght++;
}

//Retourne la définition du mot passé en paramètre
CString Dico::GetDef(CString &entry)
{
    Node* curNode=head->nextNode;
    CString def="";
    while(curNode)
    {
        if(!strcmp(entry.GetString(),(curNode->def->GetClef()).GetString()))
        {
            def=curNode->def->GetDef();
            break;
        }
        curNode=curNode->nextNode;
    }
    return def;
}
