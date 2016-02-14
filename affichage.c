#ifndef AFFICHAGE_C
#define AFFICHAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graphics.h"
#include <math.h>
#endif

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
* \brief Cette fonction convertit des coordonnées angulaires en coordonnées cartésiennes.
* \return Le point où placer le sommet
*/

POINT conversion(POINT origine, int rayon, double angle){
  POINT P;
  P.x = origine.x + cos(angle) * rayon;     // origine = angle dans le nouveau repere
  P.y = origine.y + sin(angle) * rayon;
  return P;
}

int rayon(Arbre A){
  return TAILLE_FEN / (hauteur(A)*2);
}

void init_coord(Arbre A, double total, int rayon){
  if(A == NULL)
    return;

  if(A -> pere == NULL){
    A -> coord.x = TAILLE_FEN / 2;
    A -> coord.y = TAILLE_FEN / 2;
    total = 2 * M_PI;
  }

  POINT nv_origine;
  double phi;

  for(i = 0; i < nbEnf ; i++){
    phi = i * total / A -> nbEnfants;
    // changement de repère
    nv_origine.x = cos(phi) * x - sin(phi) * y;
    nv_origine.y = sin(phi) * x + cos(phi) * y;
    
    A -> fils[i] -> coord = conversion(nv_origine, rayon, -(total/nbEnfants)/2);
    init_coord(A -> fils[i], phi, rayon);
  }
}

void dessine_arbre(Arbre A){
  if(A == NULL)
    return;

  draw_fill_circle(A -> coord, 5, rouge);

  int i;
  for(i = 0; i < nbEnfants; i++)
    dessine_arbre(A -> fils[i]);
}