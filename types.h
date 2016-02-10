#ifndef TYPES_H
#define TYPES_H
#define FILS_MAX 5

struct Noeud{
  int niveau;
  double angle;
  int pos_angle;
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
