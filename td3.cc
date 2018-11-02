using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>


class Point
{
public:
    double abs;
    double ord;        

public:
    Point()
    {
        abs=ord=0;
    }

    Point(double abs, double ord)
    {
        this->abs=abs;
        this->ord=ord;
    }

    Point(const Point &p) //constructeur de copie
    {
        this->abs=p.abs;
        this->ord=p.ord;
    }

    virtual void afficher()
    {
        cout<<"Point: x = "<<abs<<", y= "<<ord<<"\n";
    }

    void cloner(const Point &p)
    {
        this->abs=p.abs;
        this->ord=p.ord;
    }
    virtual ~Point()
    {
        cout<<"\n";
        cout<<"Destructio du Point : x= "<<abs<<", y= "<<ord<<"\n";
    }
};


enum COLOR{BLANC,BLEU,VIOLET,VERT,ROUGE};
/*
enum définit une enumération. C'est simplement un ensemble d'identificateurs 
que le compilateurs transforme en enier 
*/


class PointColor : public Point
{
private:
    int couleur;
public:
    PointColor(double abs, double ord, int c) : Point(abs, ord)
    {
        couleur=c;
    }
    virtual void afficher()
    {
        Point::afficher(); //utilise la fonction afficher de la classe mère
        cout<<", couleur : "<<coul[couleur]<<"\n";
    }
    ~PointColor()
    {
        cout<<"\n";
        cout<<"Destruction du point colore: x= "<<abs<<", y = "<<ord<<", couleur "<<coul[couleur]<<"\n";
    }
};
