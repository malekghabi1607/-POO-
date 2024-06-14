
#include "col_Points.h"




//Exercice 1:  Écrire le constructeur (avec une capacité par défaut = 100).

col_Points::col_Points(int cap = 100) {
    this->T = new Point[cap];
    this->nbp = 0;
    this->cap = cap;
}


//Exercice 2:   Écrire le constructeur qui initialise la collection en utilisant un tableau de Point.

col_Points::col_Points(Point *T, int nbp, int cap) {
    this->nbp = nbp;
    this->cap = cap;
    this->T = new Point[cap];
    for (int i = 0; i < nbp; i++) {
        this->T[i] = T[i];
    }
}


//Exercice 3:  Écrire le destructeur.

col_Points::~col_Points() {
    delete[] this->T;
}



//Exercice 4:  Écrire la fonction present() qui renvoie vrai si l’élément donné en argument est présent dans la collection.
bool col_Points::present(Point &P) {
    for (int i = 0; i < this->nbp; i++) {
        if (P.identique(this->T[i])) {
            return true;
        }
    }
    return false;
}



//Exercice 5: Écrire la fonction ajouter qui ajoute un Point s’il n’est pas déjà dans la collection. Si l’ajout ne se fait pas la fonction renvoie false.


bool col_Points::ajouter(Point &P) {
    if (present(P) or this->nbp >= this->cap) {
        return false;
    } 
    this->T[this->nbp] = P;
    this->nbp++;
    return true;
}


//Exercice 6:  Écrire la fonction supprimer() qui supprime de la collection un Point donné en argument. Si le Point en question n’existe pas, alors la fonction doit renvoyer false.

int col_Points::presentP(Point &P) {
    for(int i = 0 ; i < this->nbp ; i++) {
        if (this->T[i].identique(P) == true) {
            return i;
        }
    }
    return -1;
}

bool col_Points::supprimer(Point &P) {

    int pos = presentP(P);

    if (pos >= 0) {
        for(int i = pos; i < this->nbp - 1; i++) {
            this->T[i] = this->T[i + 1];
        }
        this->nbp--;
        return true;
    } 

    return false;
}



//Exercice 7: Écrire la fonction ajouter_bis(Point &P) qui lorsque la collection est pleine, alloue un espace 2 fois plus grand, y mettre le contenu actuel de la collection et ajoute le Point P. N’oubliez pas de libérer l’espace inutile désormais.
bool col_Points::ajouter_bis(Point &P) {
    // * P ne sera pas ajouté si il existe déjà dans la collection
    if (this->present(P)) {
        return false;
    }

    // * P ne peut pas être ajouté sans augmenter la taille de T
    bool plein = this->nbp == this->cap;
    if (plein) {
        Point *T2 = new Point[this->cap * 2];
        // copie des données de this->T dans T2
        for (int i = 0; i < this->nbp; i++) {
            T2[i] = this->T[i];
        }
        // suppression de T
        delete[] this->T;
        // on utilise désormais T2
        this->T = T2;
        // la capacité a été multipliée par 2
        this->cap = cap * 2;
    }

    // * ajout de P
    this->T[this->nbp] = P;
    this->nbp++;

    return true;
}



//Exercice 8:  Écrire une fonction membre qui ajoute (utiliser la fonction ajouter_bis) les éléments d'un tableau de Point à une collection de Point.

void col_Points::ajouter_tableau(Point *T, int N) {
    for (int i = 0; i < N; i++) {
        this->ajouter_bis(T[i]);
    }
}



//Exercice 9:    Écrire le constructeur par copie.

col_Points::col_Points(const col_Points &cp) {
    this->nbp = cp.nbp;
    this->cap = cp.cap;
    this->T = new Point[this->cap];
    for (int i = 0; i < cp.nbp; i++) {
        this->T[i] = cp.T[i];
    }
}




//Exercice 10:  Écrire la fonction qui met l’intersection de (*this) et de A dans B.

void col_Points::intersection(const col_Points &A, col_Points &B) {
    for (int i = 0; i < this->nbp; i++) {
        if (A.present(this->T[i])) {
            B.ajouter_bis(this->T[i]);
        }
    }
}


//Exercice 11:  Écrire un constructeur qui prend 2 collections de points en argument et qui crée la collection union des 2 autres.
col_Points * col_Points::union(const col_Points &other) {
    col_Points *out = new col_Points(this->nbp + other.nbp);

    for (int i = 0; i < this->nbp; i++) {
        out->ajouter(this->T[i]);
    }
    for (int i = 0; i < other.nbp; i++) {
        out->ajouter(other.T[i]);
    }

    return out;
}



//Exercice 12:  Écrire une fonction qui renvoie 5 résultats : le point ayant la plus petite abscisse, le point ayant la plus grande abscisse, le point ayant la plus petite ordonnée, le point ayant la plus grande ordonnée et le centre de tous les points de la collection.


Point col_Points::calculer_metriques(Point &petiteAbs, Point &petiteOrd, Point &grandAbs, Point &grandOrd) {

    petiteAbs = this->T[0];
    petiteOrd = this->T[0];
    grandAbs = this->T[0];
    grandOrd = this->T[0];

    double x = this->T[0].x;
    double y = this->T[0].y;

    for (int i = 1; i < this->nbp; i++) {
        if (this->T[i].x < petiteAbs.x) petiteAbs = this->T[i];
        if (this->T[i].y < petiteOrd.y) petiteOrd = this->T[i];
        if (this->T[i].x > grandAbs.x) grandAbs = this->T[i];
        if (this->T[i].y > grandOrd.y) grandOrd = this->T[i];
        x += this->T[i].x;
        y += this->T[i].y;
    }

    return Point(x / this->nbp, y / this->nbp);
}








