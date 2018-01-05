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

void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  char * tampon = NULL,
       * lettre = NULL,
       * res;
  int code;

  do {
    code = fgetc(entree);
    printf("%d", code);
    res = concatene(res, lettre);

    printf("%s\n", res);

    if(rechercher_dictionnaire(dico,res))
      tampon=res;
    else{
      ajout_dico(dico,res);
      tampon=lettre;
    }
  } while(code != EOF);
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
