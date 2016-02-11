#ifndef GENERATION_RND_C
#define GENERATION_RND_C
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "fonctions_base.h"
#endif

/**
* \brief Cette fonction ajoute une feuille à un arbre de manière aléatoire
* \param A l'arbre à traiter
* \return s'il y a eu un ajout, 0 sinon
*/

int ajoute_feuille_rnd(Arbre A){
  int i = 0;
  if(A == NULL)
    return 0;

  while(i < FILS_MAX && A -> fils[i] != NULL){    // on cherche le nombre de fils de A
    i++;
  }
  int test = rand() % (i + 1);
  
  if (i == 0 || (i != FILS_MAX && test == i)){   // si le sommet n'a pas de fils on est obligé d'en rajouter un. S'il est saturé on ne peut pas en ajouter.
    ajoute_fils(A);
    return 1;
  }
  else if(test != i)                             // sans cette condition on a parfois une segfault car A -> fils[i] est interdit
    return ajoute_feuille_rnd(A -> fils[test]);
  else
    return 0;
}

/**
* \brief  Cette fonction génère un arbre aléatoire
* \param  A, taille L'arbre à traiter et sa taille
*/
void genere_alea(Arbre A, int taille){
  while(taille > 0){
    if (ajoute_feuille_rnd(A))
      taille --;
  }
}

