#include <iostream>
#include "Liste.h"

using namespace std;

int main()
{
  cout << "C'est parti !" << endl << endl;

  Liste l;

  cout << "------------" << endl;
  l.Afficher();
  cout << "------------" << endl;
  
  int T1[10] = {1, 3, 9, 5, 7, 6, 2, 10, 4, 8};
  Liste l1(T1, 10);

  cout << "------------" << endl;
  l1.Afficher();
  cout << "------------" << endl;

  Liste l11(10, T1);

  cout << "------------" << endl;
  l11.Afficher();
  cout << "------------" << endl;

  cout << "------------" << endl;
  l1.Afficher_Rec();
  cout << "------------" << endl;

  cout << "------------" << endl;
  l1.Afficher_Inverse();
  cout << "------------" << endl;

  cout << "------------" << endl;
  cout << "Nombre d'element : " << l.Cardinal() << endl;
  cout << "Nombre d'element : " << l1.Cardinal() << endl;
  cout << "------------" << endl;

  cout << "------------" << endl;
  l.Afficher();
  cout << "------------" << endl;
  cout << 1;
  if (l.Chercher(1))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << "------------" << endl;
  l1.Afficher();
  cout << "------------" << endl;
  cout << 12;
  if (l1.Chercher(12))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << "------------" << endl;
  cout << 6;
  if (l1.Chercher(6))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << endl;

  int T4[10] = {1, 3, 5, 7, 9, 12, 20, 34, 48, 55};
  Liste l4(T4, 10);

  cout << "------------" << endl;
  l4.Afficher();
  cout << "------------" << endl;
  cout << "------------" << endl;
  cout << 1;
  if (l4.Chercher2(1))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << "------------" << endl;
  cout << 13;
  if (l4.Chercher2(13))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << "------------" << endl;
  cout << 12;
if (l4.Chercher2(12))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << "------------" << endl;
  cout << 60;
if (l4.Chercher2(60))
    cout << " Present" << endl;
  else
    cout << " Absent" << endl;
  cout << "------------" << endl;
  cout << endl;


  int T2[10] = {1, 3, 3, 5, 7, 3, 2, 3, 4, 1};
  Liste l2(T2, 10);

  cout << "------------" << endl;
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << "------------" << endl;
  cout << l2.Nb_Occurence(1) << " occurences de " << 1 << endl;
  cout << "------------" << endl;
  cout << l2.Nb_Occurence(3) << " occurences de " << 3 << endl;
  cout << "------------" << endl;
  cout << l2.Nb_Occurence(5) << " occurences de " << 5 << endl;
  cout << "------------" << endl;
  cout << l2.Nb_Occurence(8) << " occurences de " << 8 << endl;
  cout << "------------" << endl;
  cout << endl;
  
  cout << "------------" << endl;
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << "------------" << endl;
  cout << "l2.Supprimer(5)" << endl;;
  l2.Supprimer(5);
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << endl;

  cout << "------------" << endl;
  cout << "l2.Supprimer_Tout(12)" << endl;
  l2.Supprimer_Tout(12);
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << endl;

  cout << "------------" << endl;
  cout << "l2.Supprimer_Tout(7)" << endl;
  l2.Supprimer_Tout(7);
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << endl;

  cout << "------------" << endl;
  cout << "l2.Supprimer_Tout(1)" << endl;
  l2.Supprimer_Tout(1);
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << endl;

  cout << "------------" << endl;
  cout << "l2.Supprimer_Tout(3)" << endl;
  l2.Supprimer_Tout(3);
  l2.Afficher();
  cout << "------------" << endl;
  
  cout << endl;

  cout << "------------" << endl;
  cout << "Liste p(l1)" << endl;
  Liste p(l1);

  l1.Afficher();
  cout << endl;
  p.Afficher();
  cout << endl;
  cout << "------------" << endl;


  cout << "C'est fini !" << endl;
}
