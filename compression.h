#ifndef __COMPRESSION_H_
#define __COMPRESSION_H_

#include <stdio.h>
#include "dictionnaire.h"

unsigned char* lire_lettre(FILE* entree);
unsigned char * concat (unsigned char * ch1, unsigned char * ch2);
void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico);
void decompression(FILE* sortie, FILE* entree);

#endif
