#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "types.h"
#define TAILLE_FENETRE 400
#endif

void init_niveau(Arbre A);
void init_angles(Arbre A);
void affiche_commande(Arbre A);
int hauteur(Arbre A);
void affiche_arbre(Arbre A, int hauteur);
void affiche_segments(Arbre A, int hauteur);
void init_freres(Arbre A);