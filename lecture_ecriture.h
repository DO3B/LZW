#ifndef __LECTURE_ECRITURE_H_
#define __LECTURE_ECRITURE_H_

unsigned char* lire_lettre(FILE* entree);
unsigned char * concat (unsigned char * ch1, unsigned char * ch2);
unsigned int lire_code (FILE* fichier);
void ecrire_binaire_code (FILE* sortie, unsigned int code, int vider_tampon);
int lire_binaire_code (FILE* entree);

#endif
