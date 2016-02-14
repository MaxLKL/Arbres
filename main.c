#ifndef MAIN_C
#define MAIN_C
#include <stdlib.h>
#include <time.h>
#include "fonctions_base.h"
#include "generation_rnd.h"
#include "types.h"
#include "affichage.h"
#include "graphics.h"
#endif

int main(int argc, char** argv){
  srand(time(NULL));
  Arbre A = genere_alea(A, 10);
  init_niveau(A);
  init_angles(A);
  //affiche_commande(A);
  init_graphics(TAILLE_FEN, TAILLE_FEN);
  affiche_arbre(A, hauteur(A));
  affiche_segments(A, hauteur(A));
  wait_escape();
  return 0;
}
