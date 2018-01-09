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
#include <string.h>

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

unsigned char * concatener_chaines (unsigned char * ch1, unsigned char * ch2) {
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

void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  unsigned char* tampon = NULL;
  unsigned char* res = NULL;
  unsigned char* lettre;

  while((lettre = lire_lettre(entree)) != NULL){
    res = concatener_chaines(tampon,lettre);

    if(rechercher_caractere(dico,res) != 0){
      free(tampon);
      free(lettre);

      tampon = res;
    }else{
      ajout_dico(dico,res);
      fprintf(sortie, "%d", rechercher_caractere(dico, tampon));
      free(tampon);
      free(res);

      tampon = lettre;
    }
  }
  fprintf(sortie, "%d", rechercher_caractere(dico, tampon));
  free(tampon);
}

int lire_code (FILE* fichier) {
    int code;
    fscanf (fichier, "%d", &code);
    return code;
}

void decompression(FILE* sortie, FILE* entree, t_ptr_noeud dico){
  unsigned char * previous = NULL;
  int code = lire_code(sortie);
  previous=rechercher_mot(dico,code);

  fprintf (sortie, "%s", previous);

  while (code != EOF){
    mot_lu=rechercher_mot(dico,code);
    fprintf (sortie, "%s", mot_lu);
    if(mot_lu==0){

    }

    res=concatener_chaines(previous, mot_lu);
  }
  previous=mot_decode;
}
