/**
 *
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author JEAN Léo <leo.jean@etu.univ-amu.fr>
 * @author MAYOL Loïc <loic.mayol@etu.univ-amu.fr>
 *
 * @version 0.0.1 / 17-12-2017
 */

/**
 * @file compression.c
 * @brief Contient tout les fonctions relatives à la compression
 */
#include "compression.h"
#include "dictionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned char* lire_lettre(FILE* entree){
  if(entree == NULL){
    printf("Pas de fichier en entrée");
    return NULL;
  }

  unsigned char* lettre = NULL;
  int code;

  code = fgetc(entree);


  if(code != EOF){
    lettre = malloc(sizeof(unsigned char)*2);
    sprintf((char*)lettre, "%c", (unsigned char)code);
  }

  return lettre;
}

unsigned char * concatener_chaines (unsigned char * chaine1, unsigned char * chaine2) {
    unsigned char * chaine12;
    int i, n1 = 0, n2 = 0;

    if (chaine1 != NULL)
        n1 = strlen ((char *)chaine1);
    if (chaine2 != NULL)
        n2 = strlen ((char *)chaine2);

    chaine12 = malloc (sizeof (unsigned char) * (n1 + n2 + 1));
    assert (chaine12 != NULL);
    for (i = 0; i < n1; i++)
        chaine12[i] = chaine1[i];
    for (i = n1; i <= n1+n2; i++)
        chaine12[i] = chaine2[i-n1];

    return chaine12;
}

void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  unsigned char * tampon = NULL;
  unsigned char* res = NULL;
  int lettre;

  printf("Ok");
  do {
    lettre = fgetc(entree);
    printf("%c", lettre);
    res = concatener_chaines(res,(unsigned char*)lettre);

    if(rechercher_dictionnaire(dico,res)){
      free(tampon);

      tampon = res;

    }else{
      ajout_dico(dico,res);
      fprintf(sortie, "%c", rechercher_dictionnaire(dico, tampon));

      free(tampon);

      tampon = (unsigned char*)lettre;
    }

    fprintf(sortie, "%c", rechercher_dictionnaire(dico, tampon));
    free(tampon);

  } while(lettre != EOF);

}

int lire_code (FILE* fichier) {
    int code;
    fscanf (fichier, "%d", &code);
    return code;
}

/*void decompression(FILE* sortie, FILE* entree){
  unsigned char * previous = NULL;
  int code = lire_code(sortie);
  while (code != EOF){
    printf("essai");
    fputc(code, entree);
    code = lire_code(sortie);
  }
}*/
