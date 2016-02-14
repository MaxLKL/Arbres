#ifndef TYPES_H
#define TYPES_H
#define FILS_MAX 5
#define TAILLE_FEN 500


struct Noeud{
  int niveau;
  int position;
  double angle;		//	la position angulaire du sommet
  int nbEnfants;
  struct Noeud* pere;
  struct Noeud* fils[FILS_MAX];
};
typedef struct Noeud* Arbre;

struct File{
  Arbre f[1000];
  int tete;
  int queue;
};
typedef struct File File;
#endif
