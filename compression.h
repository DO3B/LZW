#ifndef __COMPRESSION_H_
#define __COMPRESSION_H_

#include <stdio.h>
#include "dictionnaire.h"

void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico);
void decompression(FILE* sortie, FILE* entree);

#endif
