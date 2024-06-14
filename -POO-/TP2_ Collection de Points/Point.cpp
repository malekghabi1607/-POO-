//Ajouter à la classe Point une fonction qui dit si deux points sont identiques : deux points sont identiques si la distance les séparant est inférieur à 0,0001.

#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

void Point::afficher() {
    cout << "(" << this->x << "," << (*this).y << ")" << endl;
}

void Point::saisir() {
    cout << "Entrez x:";
    cin >> this->x;
    cout << "Entrez y:";
    cin >> this->y;
}

Point::Point(double a, double b) {
    this->x = a;
    this->y = b;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

double Point::distance(Point &P) {
    double d1 = this->x - P.x;
    double d2 = this->y - P.y;
    return (sqrt(d1 * d1 + d2 * d2));
}


void afficher(Point *T, int N) {
    for(int i = 0; i < N; i++) {
        T[i].afficher();
    }
}

void saisir(Point *T, int N) {
    for(int i = 0; i < N; i++) {
        T[i].saisir();
    }
}

Point* saisir_points(int &n) {
    cout << "Entrez la taille du tableau:";
    cin >> n;
    Point *T = new Point[n];
    saisir(T, n);
    return(T);
}

bool Point::identique(Point &P) {
    return this->distance(P) < 0.0001;
}