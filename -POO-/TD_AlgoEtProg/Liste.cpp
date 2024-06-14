#include "Liste.h"

// ======================================
// Question 1 Constructeur Liste vide
Liste::Liste()
{
	tete = NULL;
}

// ======================================
// Question 2 Creation d'un maillon
Maillon::Maillon()
{
	suiv = NULL;
}

Maillon::Maillon(int V)
{
	info = V;
	suiv = NULL;
}

Maillon::Maillon(int V, Maillon * S)
{
  info = V;
  suiv = S;
}

// ======================================
// Question 3 Constructeur Liste a partir d'un tableau

// Version avec insertion en fin
// Il faut traiter le premier maillon à part et donc aussi le cas
// de la liste vide

Liste::Liste(int T[], int N)
{
  int i;
  Maillon * tmp;
  
  if (N == 0)
  {   // Cas particulier tableau vide -> liste vide
    tete = NULL;
    return;
  }
  tete = new Maillon(T[0]);
  tmp = tete;
  for (i = 1;i < N; i++)
  {
    tmp -> suiv = new Maillon(T[i]);
    tmp = tmp -> suiv;
  }
}

// Version avec insertion en tete
// Pas de cas particuliers a traiter

Liste::Liste(int N, int T[])
{
  int i;
  tete = NULL;
  for (i = N - 1;i >= 0; i--)
    tete = new Maillon(T[i], tete);
}

// ======================================
// Question 4 Affichage d'une liste
// On parcourt la liste a partir du debut
// et on affiche l'info de chaque Maillon

void Liste::Afficher()
{
	Maillon * tmp;
	
	tmp = tete;
	
	while (tmp != NULL)
	{
		cout << tmp -> info << " ";
		tmp = tmp -> suiv;
	}
	cout << endl;
}

// ======================================
// Question 5 Destructeur de liste
// On parcourt la liste à partir du debut
// et on delete chaque Maillon sans perdre la
// suite de la liste

// Decommenter et commenter un seul des 2 destructeur de Liste
/*
Liste::~Liste()
{
  Maillon * tmp;
  
  while (tete != NULL)
  {
    tmp = tete;
    tete = tete -> suiv;
    delete tmp;
  }
}
*/

// Version avec un destructeur de Maillon :

// Destructeur de Liste
Liste::~Liste()
{
  if (tete != NULL)
    delete tete;
}

// Destructeur de Maillon

Maillon::~Maillon()
{
  if (suiv != NULL)
    delete suiv;
}

// Avantages : 
//   simplification de l'écriture
// Inconvénients : 
//   il faut "débrancher" un maillon avant de le supprimer sinon on perd
//   toute la suite
//   on sort du modèle où la liste globale est gérée dans la 
//   classe liste


// ======================================
// Question 6 Affichage recursif

// Afficher un Maillon c'est afficher son info puis afficher la suite

void Liste::Afficher_Rec()
{
  Afficher_Rec(tete);
  cout << endl;
}

void Liste::Afficher_Rec(Maillon * M)
{
  if (M == NULL)
    return;
  cout << M -> info << "  ";
  Afficher_Rec(M -> suiv);
}

// ======================================
// Question 7 Affichage inverse

// Afficher un Maillon c'est afficher afficher la suite puis son info

void Liste::Afficher_Inverse()
{
  Afficher_Inverse(tete);
  cout << endl;
}

void Liste::Afficher_Inverse(Maillon * M)
{
  if (M == NULL)
    return;
  Afficher_Inverse(M -> suiv);
  cout << M -> info << "  ";
}

// ======================================
// Question 8 Cardinal

int Liste::Cardinal()
{
  int c = 0;
  Maillon * tmp = tete;
  
  while (tmp != NULL)
  {
    c++;
    tmp = tmp -> suiv;
  }
  return c;
}

// ======================================
// Question 9 Recherche d'une valeur

bool Liste::Chercher(int v)
{
  Maillon * tmp = tete;
  
  while (tmp != NULL && tmp -> info != v)
    tmp = tmp -> suiv;
  if (tmp == NULL)
    return false;
  return true;
}

// ======================================
// Question 10 Recherche d'une valeur dans une liste ordonnée
// On peut profiter du fait que la liste est ordionnee pour arreter 
// la recherche quand la valeur recherchee est depassee

bool Liste::Chercher2(int v)
{
  Maillon * tmp = tete;
  
  while (tmp != NULL && tmp -> info < v)
    tmp = tmp -> suiv;
  if (tmp == NULL)
    return false;
  if (tmp -> info != v)
    return false;
  return true;
}

// ======================================
// Question 11 Nombre d'occurence d'une valeur

int Liste::Nb_Occurence(int v)
{
  Maillon * tmp = tete;
  int c = 0;
  
  while (tmp != NULL)
  {
    if (tmp -> info == v)
      c++;
    tmp = tmp -> suiv;
  }
  return c;
}

// ======================================
// Question 12 Suppression de la premiere occurence d'une valeur
// Technique à 2 pointeurs :
// On parcourt la liste avec 2 pointeurs un qui pointe sur le 
// Maillon courant et un qui pointe sur le Maillon precedent
// quand on a trouve on utilise le pointeur precedent pour faire 
// la suppression

void Liste::Supprimer(int v)
{ 
  Maillon * pc = tete;  // pointeur courant
  Maillon * pr = NULL;  // pointeur precedent (en retard)
  
  while (pc != NULL && pc -> info != v)
  {
    pr = pc;
    pc = pc -> suiv;
  }
  if (pc == NULL) // valeur non trouvee
    return;
  if (pr == NULL) // valeur trouvee en tete 
    tete = tete -> suiv;
  else  		  // valeur trouve ailleurs dans la liste
    pr -> suiv = pc -> suiv;
  pc -> suiv = NULL;
  delete pc;
}


// ======================================
// Question 13 Suppression de toutes les occurences d'une valeur

void Liste::Supprimer_Tout(int v)
{ // Technique à 2 pointeurs
  Maillon * pc = tete;  // pointeur courant
  Maillon * pr = NULL;  // pointeur en retard
  
  while (pc != NULL)
  {
    if (pc -> info == v)
    {
      if (pr == NULL)
      {
        tete = tete -> suiv;
        pc -> suiv = NULL;
        delete pc;
        pc = tete;
      }
      else
      {
        pr -> suiv = pc -> suiv;
        pc -> suiv = NULL;
        delete pc;
        pc = pr -> suiv;
      }
    }
    else
    {
      pr = pc;
      pc = pc -> suiv;
    }
  }
}

// ======================================
// Question 14 Constructeur de recopie
// Le constructeur de recopie est le constructeur qui permet de
// construire une liste a parir d'une autre liste donnee en 
// argument.
// Il construit donc une copie de la liste argument.
// Il est utilisé explicitement lorsqu'on declare une liste ainsi :
// Liste L2(L1);
// avec L1 qui est une Liste
// Il est utilise automatiquement :
// - lors d'un passage d'argument par valeur (un argument par 
// valeur est une variable locale initialisee par la valeur fournie)
// - lors du retour par valeur d'une fonction (pour la meme raison)

Liste::Liste(Liste & L)
{
  // Si la liste L a recopier est vide on cree une liste vide
  if (L.tete == NULL)
  {
    tete = NULL;
    return;
  }
  //  Le 1er Maillon doit etre traite d'abord
  tete = new Maillon(L.tete -> info, NULL);

  // m2 parcourt la liste a recopier
  // m1 avance et cree la copie
  // m1 doit etre positionnee sur le dernier Maillon 
  // pour garantir le chainage  
  Maillon * m1 = tete, * m2 = L.tete -> suiv;
  
  while (m2 != NULL)
  {
    m1 -> suiv = new Maillon(m2 -> info, NULL);
    m1 = m1 -> suiv;
    m2 = m2 -> suiv;
  }
}
