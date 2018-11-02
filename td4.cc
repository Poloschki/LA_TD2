#include <stdlib.h>
#include <math.h>
#include "../td2/CString.h"
#include <vector>

template <class T>
T GetMax(T x, T y)
{
    return x>y ? x : y;
}

template <class T>
class pair;

/*
    les fonctions template amies d'une classe,
    doivent être déclareées avant la classe
*/

template <class T>
ostream &operator<<(ostream&, Pair<T> &);

template <class T>
class Pair
{
private:
    T x1;
    T x2;
public: 
    Pair(T x_1, T x_2) {x1 = x_1; x2=x_2 ;}

    T GetMax(); // on peut la définir à l'intérieur ou à l'extérieur

    friend void Dispx1(Pair<CString>); // fonction friend spécialisée
    friend ostream & operator<< <>(ostream&, Pair<T> &); // fonction friend template
    friend ostream & operator<< (ostream&, Pair<CString>&); //fonction friend spécialisée
};
// définition d'une fonction membre template
template <class T>
T Pair<T>::GetMax()
{
    return x1 > x2 ? x1 : x2;

}

//version spécialisée
//c'est cette version qui sera appelée pour les Pair<int>
int Pair<int>::GetMax()
{
    cout<<"max int";
    return x1 > x2 ? x1 : x2;
}

//autre version spécialisée
float Pair<float>::GetMax()
{
    cout<<"max float";
    return x1 > x2 ? x1 : x2;
}

template <class T>
void DispMax(Pair<T> &p)
{
    cout<<p.GetMax();
}

//version spécialisée pour afficher les CString qui ne définissent pas l'opérateur <<
void DispMax(Pair <CString> &p)
{
    cout<<p.GetMax().GetString();
}

//fonction amie spécialisée pour les CString
void Dispx1(Pair<CString>p)
{
    cout<<p.x1.GetString();
}

template <class T>
ostream & operator<<(ostream& out, Pair<T> &p)
{
    out<<p.x1<<", "<<p.x2;
    return out;
}

//version spécilisée pour les CString 
ostream & operator <<(ostream & out, Pair<CString> &p)
{
    cout<<"spec : ";
    out<<p.x1.GetString()<<", "<<p.x2.GetString();
    return out;
}

// /*
//  * conclusion : quelle qeu soit la nature des fonctions template
//  * elle peuvent être spécialisée pour faire des traitement sépciaxu 
//  * pour certaines classes
//  * Pou rces classes, ce sont les versions spécialisée qui seront appelées,sinon
//  * les versions template. 
//  * 
//  */

// //////////////////////////////////////
// Exercice3  
// /////////////////////////////////////






 
 int main(int argc, char const *argv[])
 {
     Pair<int> myInts(i,j);
     Pair<float> myFloats(l,m);
     Pair<CString> myString(s1,s2);

     cout<<myInts.GetMax()<<endl;
     cout<<myFloats.GetMax()<<endl;

     s3=myString.GetMax();
     cout<<s3<<endl;

     DispMax(myInts);
     cout<<endl;
     DispMax(myString);
     cout<<endl;
     Dispx1(myString);
     cout<<endl;

     cout<<myFloats;
     cout<<endl;
     cout<<myString;
     cout<<endl;

     return 0;
 }
 