#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

// Exo1
void Point::afficher()
{
	cout<<"("<<(*this).x<<","<<(*this).y<<")"<<endl;

}

// Exo2
void Point::saisir()
{
	cout<<"Entrez x:";
	cin>>(*this).x;
	cout<<"Entrez y:";
	cin>>(*this).y;
}

// Exo3 a
Point::Point(double a, double b)
{
	(*this).x=a;
	(*this).y=b;
}

// Exo3 b
Point::Point()
{
	(*this).x=0;
	(*this).y=0;
}

// Exo4
double Point::distance(Point & P)
{
	double d1=(*this).x-P.x;
	double d2=(*this).y-P.y;
	return (sqrt(d1*d1+d2*d2));
}


// Exo5
void afficher(Point *T, int N)
{
	for(int i=0;i<N;i++) T[i].afficher();
}

// Exo7
void saisir(Point *T, int N)
{
	for(int i=0;i<N;i++) T[i].saisir();
}

// Exo8
Point* saisir_points(int &n)
{
	cout <<"Entrez la taille du tableau:";
	cin >> n;
	Point *T=new Point[n];
	saisir(T,n);
	return(T);
}




