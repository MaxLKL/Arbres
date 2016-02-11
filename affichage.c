#ifndef AFFICHAGE_C
#define AFFICHAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graphics.h"
#include <math.h>
#define TAILLE_FEN 500
#endif

/**
* \brief  Cette fonction initialise les angles d'un arbre
* \details On initialise l'angle de la racine à 2 pi puis on divise récursivement les secteurs angulaires des enfants.
* \param A l'arbre à initialiser 
*/

void init_angles(Arbre A){
  if(A == NULL)
    return;
  if(A -> pere == NULL){
    A -> angle = 2 * M_PI;
    A -> pos_angle = 0;
  }
  int j = 0;
  while(A -> fils[j] != NULL && j < FILS_MAX){
    j++;
  }
  int i;
  for(i = 0; i < j; i++){
        A -> fils[i] -> angle = A -> angle/j;
        if(A -> fils[i] -> angle >= M_PI)     // si on a un angle > pi on aura des croisements 
          A -> fils[i] -> angle = M_PI;
        
        A -> fils[i] -> pos_angle = i;
        init_angles(A -> fils[i]);
  }
}

/**
* \brief Cette fonction initialise les niveaux de l'arbre récursivement.
* \details  Les niveaux sont les distances à la racine. On s'en sert pour calculer le cercle sur lequel placer le sommet
* \param  A L'arbre à initialiser
*/

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


/**
* \brief Cette fonction calcule récursivement la hauteur d'un arbre.
* \param A L'arbre à traiter
*/
int hauteur(Arbre A){
  if(A == NULL)
    return -1;
  else{
    int i;
    int tmp;
    int max = -1;
    for(i = 0; i < FILS_MAX; i++){
      tmp = hauteur(A -> fils[i]);
      if(tmp > max)
        max = tmp;
    }
    return max + 1;
  }
}

/**
* \brief Cette fonction calcule les coordonnées cartésiennes d'un sommet
* \param A le sommet initialisé à traiter
* \return Le point où placer le sommet
*/

POINT coord_sommet(Arbre A){
  POINT P;
  int h = hauteur(A);
  P.x = cos(A -> angle * A -> pos_angle) * A -> niveau * TAILLE_FEN / h;
  P.x = sin(A -> angle * A -> pos_angle) * A -> niveau * TAILLE_FEN / h;
  return P;
}

void affiche_commande(Arbre A){
  if(A==NULL)
    return;
  printf("A:%p ; lvl:%d ; pere:%p ; Angle:%f ; Pos :%d, h:%d \n", A, A -> niveau, A -> pere, A -> angle, A -> pos_angle, hauteur(A));
  int i;
  for(i = 0; i < FILS_MAX; i++){
    affiche_commande(A -> fils[i]);
  }
}