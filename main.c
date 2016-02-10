#ifndef MAIN_C
#define MAIN_C
#include <stdlib.h>
#include <time.h>
#include "fonctions_base.h"
#include "generation_rnd.h"
#include "types.h"
#include "affichage.h"
#endif

int main(int argc, char** argv){
  srand(time(NULL));
  Arbre A = creer_arbre();
  genere_alea(A, 10);
  init_niveau(A);
  init_angles(A);
  /*char nom[] = "test.dot";
  creer_dot(nom);
  remplir_dot(nom, A);
  fin_dot(nom);
  creer_jpg(nom);*/
  affiche_commande(A);
  
  return 0;
}
