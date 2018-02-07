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
#include "lecture_ecriture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int PLEIN;

void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  unsigned char* tampon = NULL;
  unsigned char* res = NULL;
  unsigned char* lettre;

  while((lettre = lire_lettre(entree)) != NULL){
    res = concat(tampon,lettre);

    if(rechercher_caractere(dico,res) != 0){
      tampon = res;
    }else{
      //On ajoute au dico seulement si le dico est pas plein.
      if (PLEIN == 0) {
        dico = ajout_dico(dico,res);
      }

      //fprintf(sortie, "%d ", rechercher_caractere(dico, tampon));
      ecrire_binaire(sortie, rechercher_caractere(dico, tampon), 0);

      tampon = lettre;
    }
  }

  //fprintf(sortie, "%d ", rechercher_caractere(dico, tampon));
  ecrire_binaire(sortie, rechercher_caractere(dico, tampon), 1);
}

void decompression(FILE* entree, FILE* sortie, t_ptr_noeud dico){
  unsigned char * previous = NULL;
  unsigned int code = lire_binaire(entree);
  previous = rechercher_mot(dico,code);
  fprintf (sortie, "%s", previous);

  while ((code = lire_binaire(entree)) != 0){
    unsigned char* mot_lu = NULL;
    unsigned char* res = NULL;
    printf("%d\n", code);

    mot_lu=rechercher_mot(dico,code);

    if(mot_lu == NULL) {
      unsigned char* carac_previous = malloc (sizeof (unsigned char));
      carac_previous[0] = previous[0];
      mot_lu = concat(previous,carac_previous);
    }

    fprintf (sortie, "%s", mot_lu);

    unsigned char* carac_mot_lu = malloc (sizeof (unsigned char));
    carac_mot_lu[0] = mot_lu[0];

    res = concat(previous, carac_mot_lu);

    if (PLEIN == 0) {
      dico = ajout_dico(dico,res);
    }

    previous = mot_lu;
  }

}
