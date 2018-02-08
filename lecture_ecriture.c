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
 * @file lecture_ecriture.c
 * @brief Contient tout les fonctions relatives à la lecture et l'écriute mais aussi
 * concat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"

/** @brief Va lire la lettre du fichier en argument
* @param entree -> fichier que l'on souhaite lire
* @return lettre lue
*/
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

/** @brief Concatène les deux chaînes de caractères en argument.
* @param ch1 -> première chaîne
* @param ch2 -> deuxième chaîne
* @return une chaîne
*/
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

/** @brief Va lire le code du fichier en argument
* @param entree -> fichier que l'on souhaite lire
* @return code lu
*/
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

/** @brief Met à un le bit i du tampon
* @param tampon -> tampon que l'on souhaite modifier
* @param i -> le bit que l'on veut mettre à un
*/
void mise_a_un(unsigned char *tampon, unsigned int i){
  unsigned int deux_puissances[32];
  int j;

  for(j = 0; j < 32; j++)
    deux_puissances[j] = puissance(j);

  *tampon = *tampon | deux_puissances[i];
}

/** @brief Ecrit en binaire le code sur un nombre NB_BITS de bits
* @param sortie -> fichier dans lequel on va écrire
* @param code -> code à écrire
* @param vider_tampon -> quand 1 écrit le buffer restant
*/
void ecrire_binaire (FILE* fichier_sortie, unsigned int code, int vider_tampon) {
    static unsigned char tampon = 0;
    static int indice = 7; //7 car 1 octets
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

/** @brief Traduit en int un binaire
* @param entree -> fichier que l'on souhaite lire
* @return code lu en int
*/
int lire_binaire (FILE* entree) {
    static unsigned char tampon = 0;
    static unsigned int indice = 0;
    unsigned int code;
    int i, nb_bits, tmp = 0;

    nb_bits = NB_BITS - indice;
    code = ((int)tampon) << nb_bits;

    for (i = 1; i <= (nb_bits / 8); i++) {
        fread (&tampon, sizeof (unsigned char), 1, entree);

        tmp = ((int)tampon) << (nb_bits - 8*i);
        code = code | tmp;
    }

    if (nb_bits % 8 != 0) {
        fread (&tampon, sizeof (unsigned char), 1, entree);

        tmp = ((int)tampon) >> (8 - nb_bits % 8);
        code = code | tmp;

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
