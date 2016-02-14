#ifndef CENTRES_FILES_C
#define CENTRES_FILES_C
#include <stdlib.h>
#include "types.h"
#endif

File init_file(){
  File F;
  F.tete = 0;
  F.queue = 0;
  return F;
}

/**
*	\brief	Cette fonction renvoie 1 si la file est vide et 0 sinon
*/
int est_vide(File F){
  if(F.tete == F.queue)
    return 1;
  return 0;
}

/**
*	\brief	Cette fonction renvoie 1 si la file est pleine et 0 sinon
*/

int est_pleine(File F){
  if(F.tete == (F.queue + 1) % 1000)
  	return 1;
  return 0;
}

File enfiler(File F, Arbre A){
  if(est_pleine(F) == 0){

    F.f[F.queue] = A;
    F.queue ++;
    F.queue %= 1000;
  }
  return F;
}

File defiler(File F, Arbre* A){
  if(est_vide(F) == 0){

    *A = F.f[F.tete];
    F.tete ++;
    F.tete %= 1000;
  }
  return F;
}

void empile_feuilles(File* F, Arbre A){
  if (A == NULL)
    return;
  if(A -> fils[0] == NULL)
    *F = enfiler(*F, A);
  else{
    int i;
    while(i < FILS_MAX && A -> fils[i] != NULL){
      empile_feuilles(F, A);
      i++;
    }
  }
}

  //void centre_files(File F, Arbre A)