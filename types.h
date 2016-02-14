#ifndef TYPES_H
#define TYPES_H
#define FILS_MAX 5
#define TAILLE_FEN 500
#include "graphics.h"


struct Noeud{
  int niveau;
  POINT coord;
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
