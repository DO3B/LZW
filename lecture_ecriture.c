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

unsigned int puissance(char bit){
  int i, res=1;
  for (i=0; i< bit; i++) res*=2;
  return res;
}

void mise_a_un(unsigned char *tampon, unsigned int i){
  unsigned int deux_puissances[32];
  int j;

  for(j = 0; j < 32; j++)
    deux_puissances[j] = puissance(j);

  *tampon = *tampon | deux_puissances[i];
}

void ecrire_binaire(FILE* fichier_sortie, unsigned int code, int vider_tampon) {
    static unsigned char tampon = 0;
    static int indice = 7; //7 car 1 octets (0 à 7)
    int i;

    for (i = NB_BITS - 1; i >= 0; i--) {
        int bit = ((code >> i) & 1);

        if(bit){
          mise_a_un(&tampon, indice);
        }

        if (indice == 0) {
            fwrite (&tampon, sizeof (unsigned char), 1, fichier_sortie);
            tampon = 0;
            indice = 7;
        }
        else
            indice--;
    }

    if (vider_tampon) {
        fwrite (&tampon, sizeof (unsigned char), 1, fichier_sortie);
        tampon = 0;
        indice = 7;
    }
}

int lire_binaire(FILE* entree) {
    unsigned char tampon = 0; /* Debut d'ecriture dans le tampon à droite */
    unsigned int indice = 0;
    unsigned int code;
    int i, nb_bits, tmp = 0;

    /* Recuperation des bits restants du tampon */
    nb_bits = NB_BITS - indice;
    code = ((int)tampon) << nb_bits;

    for (i = 1; i <= (nb_bits / 8); i++) {
        fread (&tampon, sizeof (unsigned char), 1, entree);

        tmp = ((int)tampon) << (nb_bits - 8*i);
        code = code | tmp;
    }

    /* Lecture du dernier paquet de 8 bits dont les non utilisés iront dans le tampon */
    if (nb_bits % 8 != 0) {
        fread (&tampon, sizeof (unsigned char), 1, entree);

        tmp = ((int)tampon) >> (8 - nb_bits % 8);
        code = code | tmp;

        /* Stockage dans le tampon des bits restants */
        indice = 8 - nb_bits % 8;
        tampon = tampon << (8 - indice);
        tampon = tampon >> (8 - indice);
    }
    else {
        tampon = 0;
        indice = 0;
    }

    return code;
}
