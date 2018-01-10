#ifndef __COMPRESSION_H_
#define __COMPRESSION_H_

#include <stdio.h>
#include "dictionnaire.h"

unsigned char* lire_lettre(FILE* entree);
void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico);
void decompression(FILE* sortie, FILE* entree);
unsigned char * concatener_chaines (unsigned char * ch1, unsigned char * ch2);

#endif
