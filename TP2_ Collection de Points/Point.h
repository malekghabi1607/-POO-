#ifndef _POINT_H_
#define _POINT_H_


//Ajouter à la classe Point une fonction qui dit si deux points sont identiques : deux points sont identiques si la distance les séparant est inférieur à 0,0001.


class Point {
public:
    double x;
    double y;
public:
    Point();
    Point(double a, double b);
    void afficher();
    void saisir();
    double distance(Point &P);
    bool identique(Point &P);
};

void afficher(Point *T, int N);

void  saisir(Point *T, int N);

Point *saisir_points(int &n);

#endif
