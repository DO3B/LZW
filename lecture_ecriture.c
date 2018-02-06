#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"

unsigned char* lire_lettre(FILE* entree){
  unsigned char* lettre = NULL;
  int code;

  code = fgetc(entree);

  if(code != EOF){
    lettre = malloc(sizeof(unsigned char)*2);
    sprintf((char*) lettre, "%c", (unsigned char) code);
  }
  return lettre;
}

unsigned char * concat (unsigned char * ch1, unsigned char * ch2) {
    unsigned char * resultat;
    int i;
    int longueur_ch1 = 0, longueur_ch2 = 0;

    if (ch1 != NULL)
        longueur_ch1 = strlen ((char *)ch1);
    if (ch2 != NULL)
        longueur_ch2 = strlen ((char *)ch2);

    resultat = malloc (sizeof (unsigned char) * (longueur_ch1 + longueur_ch2 + 1));

    for (i = 0; i < longueur_ch1; i++)
        resultat[i] = ch1[i];
    for (i = longueur_ch1; i <= longueur_ch1 + longueur_ch2; i++)
        resultat[i] = ch2[i-longueur_ch1];

    return resultat;
}

unsigned int lire_code (FILE* fichier) {
    unsigned int code = 0;

    fscanf (fichier, "%d", &code);
    return code;
}
