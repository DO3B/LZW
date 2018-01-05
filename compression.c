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

char* lire_lettre(FILE* entree){
  char* lettre = NULL;
  int code;

  code = fgetc(entree);

  if(code != EOF){
    lettre = malloc(sizeof(char)*2);
    sprintf(lettre, "%c", code);
  }

  return lettre;
}


void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  char * tampon = NULL,
       * lettre = NULL,
       * res;
  do {
    lettre = lire_lettre(entree);
    res = strcat(res, lettre);
    printf("%s\n", res);

    if(rechercher_dictionnaire(dico,res)){
      free(tampon);
      free(lettre);

      tampon = res;

    }else{
      ajout_dico(dico,res);
      fprintf(sortie, "%c", rechercher_dictionnaire(dico, tampon));

      free(tampon);
      free(lettre);

      tampon = lettre;
    }
    
    fprintf(sortie, "%c", rechercher_dictionnaire(dico, tampon));
    free(tampon);
  } while((lettre = lire_lettre(entree)) != NULL);
}

int lire_code (FILE* fichier) {
    int code;
    fscanf (fichier, "%d", &code);
    return code;
}

void decompression(FILE* sortie, FILE* entree){
  unsigned char * previous = NULL;
  int code = lire_code(sortie);
  while (code != EOF){
    printf("essai");
    fputc(code, entree);
    code = lire_code(sortie);
  }
}
