#ifndef FONCTIONS_BASE_C
#define FONCTIONS_BASE_C
#include <stdlib.h>
#include "types.h"
#endif

Arbre creer_arbre(){
  Arbre A = malloc(sizeof(struct Noeud));
  A -> pere = NULL;
  // gcc refuse A -> fils = {NULL};
  int i;
  for(i = 0; i < FILS_MAX; i++){
    A -> fils[i] = NULL;
  }
  return A;
}

Arbre ajoute_fils(Arbre A){
  if(A == NULL){
    return creer_arbre();
  }

  int i = 0;
  while((A -> fils[i] != NULL) && (i < FILS_MAX)){
    i++;
  }
  if(i == FILS_MAX)
    return NULL;
  else{
    A -> fils[i] = creer_arbre();
    A -> fils[i] -> pere = A;
    return A;
  }
}
