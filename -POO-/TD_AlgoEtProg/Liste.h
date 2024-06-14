#ifndef __LISTE_H__
#define __LISTE_H__

#include <iostream>

using namespace std;

class Maillon
{ 
    friend class Liste;
    
	int info;
	Maillon *suiv;  
	
	public:
	
	Maillon();
	Maillon(int);
	Maillon(int, Maillon *);
	~Maillon();

};



class Liste
{	
		Maillon *tete;

	public :
	
	Liste();
    Liste(int T[], int N);
    Liste(int N, int T[]);
    Maillon * NouveauMaillon(int V, Maillon * M);
    void Afficher();
	~Liste();
    void Afficher_Rec();
    void Afficher_Rec(Maillon * M);
    void Afficher_Inverse();
    void Afficher_Inverse(Maillon * M);
    int Cardinal();
    bool Chercher(int v);
    bool Chercher2(int v);
    int Nb_Occurence(int v);
    void Supprimer(int v);
    void Supprimer_Tout(int v);
    Liste(Liste & L);
};

#endif
