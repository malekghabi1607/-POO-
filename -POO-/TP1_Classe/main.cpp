#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
	// création d'un Point
	Point P; // appel du constructeur sans argument
	Point Q(2.5,9.1); // appel du constructeur avec 2 argument
	Q.afficher();
	cout<<P.distance(Q)<<endl;

	Point T[3]; //création d'un tableau statique de points
	saisir(T,3);
	afficher(T,3);

	int taille;
	Point *t=saisir_points(taille);
	afficher(t,taille);
}

