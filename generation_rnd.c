#ifndef GENERATION_RND_C
#define GENERATION_RND_C
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "fonctions_base.h"
#endif

void genere_alea(Arbre A, int taille){
    if (taille == 1)
      return;
    int i = 0;
    while(i < FILS_MAX && A -> fils[i] != NULL){
      i++;
    }
    if(i == FILS_MAX)
      genere_alea(A -> fils[rand() % i], taille);
    if(i == 0){
      Arbre A2 = creer_arbre();
      A2 -> pere = A;
      A -> fils[0] = A2;
      genere_alea(A, taille - 1);
    }
    else{
      if(rand() % 2)
        genere_alea(A -> fils[rand() % i], taille);
      else{
        Arbre A2 = creer_arbre();
        A2 -> pere = A;
        A -> fils[i] = A2;
        genere_alea(A, taille -1);
      }
    }
  }
