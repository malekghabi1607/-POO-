//Exercice 1:  Écrire le constructeur (avec une capacité par défaut = 100).

#ifndef _COL_POINT_H_
#define _COL_POINT_H_
#include "Point.h"

class col_Points {
    Point *T;
    int nbp;
    int cap;
public:
    col_Points(int cap);
    ~col_Points();
    bool present(Point &P);
    int presentP(Point &P);
    bool ajouter(Point &P);
    bool supprimer(Point &P);
};

#endif
