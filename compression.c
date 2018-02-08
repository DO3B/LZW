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
 * @version 1.0.0 / 08-02-2018
 */

/**
 * @file compression.c
 * @brief Contient tout les fonctions relatives à la compression et la décompression
 */

#include "compression.h"
#include "dictionnaire.h"
#include "lecture_ecriture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int PLEIN;

/** @brief Compression en utilisant LZW
* @param entree -> fichier à compresser
* @param sortie -> fichier compressé
* @param dico -> dictionnaire que l'on va remplir
* @param test -> binaire si 0, normal si 1
*/
void compression(FILE* entree, FILE* sortie, t_ptr_noeud dico, int test){
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

      if(test)
        fprintf(sortie, "%d ", rechercher_caractere(dico, tampon));
      else
        ecrire_binaire(sortie, rechercher_caractere(dico, tampon), 0);

      tampon = lettre;
    }
  }

  if(test)
    fprintf(sortie, "%d ", rechercher_caractere(dico, tampon));
  else
    ecrire_binaire(sortie, rechercher_caractere(dico, tampon), 1);
}

/** @brief Décompression en utilisant LZW
* @param entree -> fichier compressé
* @param sortie -> fichier décompressé
* @param dico -> dictionnaire que l'on va remplir
* @param test -> binaire si 0, normal si 1
*/
void decompression(FILE* entree, FILE* sortie, t_ptr_noeud dico, int test){
  unsigned char * previous = NULL;
  unsigned int code;
  if(!test)
    code = lire_binaire(entree);
  else
    code = lire_code(entree);
  previous = rechercher_mot(dico,code);
  fprintf (sortie, "%s", previous);

  if(!test){
    while ((code = lire_binaire(entree)) != 0){
      unsigned char* mot_lu = NULL;
      unsigned char* res = NULL;

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

      if (PLEIN == 0)
        dico = ajout_dico(dico,res);

      previous = mot_lu;
      }

    } else {
      while ((code = lire_code(entree)) != 0){
        unsigned char* mot_lu = NULL;
        unsigned char* res = NULL;

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

        if (PLEIN == 0)
          dico = ajout_dico(dico,res);

        previous = mot_lu;
    }
  }

}
