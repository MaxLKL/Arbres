#ifndef AFFICHAGE_C
#define AFFICHAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graphics.h"
#include <math.h>
#endif

void init_angles(Arbre A){
  if(A == NULL)
    return;
  if(A -> pere == NULL){
    A -> angle = 2 * M_PI;
    A -> pos_angle = 0;
  }
  int j = 0;
  while(A -> fils[j] != NULL){
    j++;
    printf("%d \n", j);
  }
  int i;
  for(i = 0; i < j; i++){
      if(A -> fils[i] > 0x1000){
        A -> fils[i] -> angle = A -> angle/j;
        A -> fils[i] -> pos_angle = i;
        init_angles(A -> fils[i]);
      }
  }
}

void init_niveau(Arbre A){
  if (A == NULL)
    return;
  if (A -> pere == NULL)
    A -> niveau = 0;
  else
    A -> niveau = A -> pere -> niveau + 1;
  int i;
  for(i = 0; i < FILS_MAX; i++){
    init_niveau(A -> fils[i]);
  }
}

void affiche_commande(Arbre A){
  if(A==NULL)
    return;
  printf("A:%p ; lvl:%d ; pere:%p ; Angle:%f ; Pos :%d\n", A, A -> niveau, A -> pere, A -> angle, A -> pos_angle);
  int i;
  for(i = 0; i < FILS_MAX; i++){
    affiche_commande(A -> fils[i]);
  }
}