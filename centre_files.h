#ifndef CENTRE_FILES_H
#define CENTRE_FILES_H
#include "types.h"
#endif

File init_file();
int est_vide(File F);
int est_pleine(File F);
File enfiler(File F, Arbre A);
File defiler(File F, Arbre* A);