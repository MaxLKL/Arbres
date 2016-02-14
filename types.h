#ifndef TYPES_H
#define TYPES_H
#define FILS_MAX 5
#define TAILLE_FEN 500


struct Noeud{
  int niveau;
  double angle;		//	la position angulaire du sommet
  struct Noeud* pere;
  struct Noeud* fils[FILS_MAX];
};
typedef struct Noeud* Arbre;

struct Element{
  Arbre val;
  struct Element* suiv;
};
typedef struct Element* Liste;
#endif
