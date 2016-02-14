#ifndef MAIN_C
#define MAIN_C
#include <stdlib.h>
#include <time.h>
#include "fonctions_base.h"
#include "generation_rnd.h"
#include "types.h"
#include "affichage.h"
#include "graphics.h"
#include "centre_files.h"
#endif

int main(int argc, char** argv){
  srand(time(NULL));
  while(1){
  Arbre A = genere_alea(A, 10);
  
  init_niveau(A);
  init_angles(A);
  init_graphics(TAILLE_FEN, TAILLE_FEN);
  
  affiche_arbre(A, hauteur(A));
  affiche_segments(A, hauteur(A));
  wait_clic();
}
  return 0;
}
