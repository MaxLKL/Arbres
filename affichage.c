#ifndef AFFICHAGE_C
#define AFFICHAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graphics.h"
#include <math.h>
#endif

/**
* \brief  Cette fonction initialise les angles d'un arbre
* \details On initialise l'angle de la racine à 2 pi puis on divise récursivement les secteurs angulaires des enfants.
* \param A l'arbre à initialiser 
*/
/*
void init_angles(Arbre A){
  if(A == NULL)
    return;

  if(A -> pere == NULL)
    A -> angle = 2 * M_PI;

  int i, j;
  if(A -> fils[0] != NULL){

    for(i = 0; i < A -> fils[0] -> freres; i++){
      j = i - (A -> fils[0] -> freres / 2.0);
      
      A -> fils[i] -> angle = (A -> angle) + (A -> angle / A -> fils[i] -> freres) * j;

      if(i == 0)                                    //ces deux tests evitent les recouvrements entre voisins.
        A -> fils[i] -> angle += 0.25;
      if(i == A -> fils[0] -> freres - 1)
        A -> fils[i] -> angle -= 0.25;
    }

    for(i = 0; i < A -> fils[0] -> freres; i++){
      init_angles(A -> fils[i]);
    }
  }
}*/

void init_angles(Arbre A){
  if(A == NULL)
    return;
  if(A -> pere == NULL)
    A -> angle = 2 * M_PI;
  // A partir d'ici A -> angle a nécessairement été initialisé
  
  double deb = A -> angle - A -> angle/2;   //  deb contient le debut de l'intervalle où on a le droit de mettre des enfants
  int nbEnf = 0;
  while(nbEnf < FILS_MAX && A -> fils[nbEnf] != NULL)
    nbEnf ++;

  double pas = A -> angle/nbEnf;            //  pas correspond à la distance entre chaque enfant
  int i;
  for(i = 0; i < nbEnf; i++){
    A -> fils[i] -> angle = deb + i*pas;
    
    if(i == 0 && A -> pere != NULL)
      A -> fils[i] -> angle += pas / 2;        //  on veut eviter de recouvrir le cousin en derniere position du précédent intervalle
  }
  for(i = 0; i < nbEnf; i++)
    init_angles(A -> fils[i]);
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

POINT coord_sommet(Arbre A, int h){
  POINT P;
  if(A -> pere == NULL){
    P.x = TAILLE_FEN / 2;
    P.y = TAILLE_FEN / 2;
    return P;
  }
  P.x = TAILLE_FEN / 2 + cos(A -> angle) * TAILLE_FEN / 2 * (double)A -> niveau / (double)h;
  P.y = TAILLE_FEN / 2 + sin(A -> angle) * TAILLE_FEN / 2 * (double)A -> niveau / (double)h;
  return P;
}

void affiche_arbre(Arbre A, int hauteur){
  if(A == NULL)
    return;
  draw_fill_circle(coord_sommet(A, hauteur), 5, rouge);
  int i;
  for(i = 0; i < FILS_MAX; i++){
    affiche_arbre(A -> fils[i], hauteur);
  }
}

void affiche_segments(Arbre A, int hauteur){
  if(A == NULL)
    return;
  int i = 0;
  while(A -> fils[i] != NULL && i < FILS_MAX){
    draw_line(coord_sommet(A, hauteur), coord_sommet(A -> fils[i], hauteur), blanc);
    i++;
  }
  i = 0;
  while(A -> fils[i] != NULL && i < FILS_MAX){
    affiche_segments(A -> fils[i], hauteur);
    i++;
  }
}

void affiche_commande(Arbre A){
  if(A==NULL)
    return;
  //printf("A:%p, lvl:%d, angle:%f, freres: %d \n", A, A -> niveau, A -> angle, A -> freres);
  int i;
  for(i = 0; i < FILS_MAX; i++){
    affiche_commande(A -> fils[i]);
  }
}