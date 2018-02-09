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
 * @brief Exécutable :)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  long int start, end; //mesure du temps
  int i, a; //mesure du temps

  t_ptr_noeud dico = initialiser_dictionnaire();
  
  if(argc == 0){
    printf("lzw : les options que vous avez rentré ne fonctionnent pas ! \n");
    printf("Si vous voulez compresser, utilisez 'lzw c fichier_entree fichier_sortie'. \n");
    printf("Si vous voulez décompresser, utiliser 'lzw d fichier_entree fichier_sortie'.\n");
  }

  if((argc == 4) & (strcmp("c",argv[1]) == 0)){
    FILE* fichier_entree = fopen(argv[2],"r");
    FILE* fichier_sortie = fopen(argv[3],"wb");

    //départ du temps
    start = clock();

    printf("Compression\n");
    compression(fichier_entree, fichier_sortie, dico, 0);

    //boucle pour mesurer le temps
    for ( i = 0; i < 10000000; i++) {a++;}

    //fin du temps
    end=clock();

    //affichage du temps
    printf("Temps (ms) : %li\n", end-start);
    printf("Temps d'exécution (en s) : %f \n",(double)(end-start)/(double)CLOCKS_PER_SEC);

    //Taille du fichier entree
    fseek(fichier_entree, 0, SEEK_END);
    printf("Taille du fichier à compresser %s : %li octet(s)\n", argv[2],ftell(fichier_entree));

    //Taille fichier sortie
    fseek(fichier_sortie, 0, SEEK_END);
    printf("Taille du fichier compressé %s : %li octet(s)\n", argv[3], ftell(fichier_sortie));

    //Taux compression
    printf("Taux de compression = %f %%\n",(double)(ftell(fichier_sortie)*100)/(double)ftell(fichier_entree) );

    fclose(fichier_entree);
    fclose(fichier_sortie);
  } else if((argc == 4) & (strcmp("d",argv[1]) == 0)) {
    printf("Décompression\n");
    FILE* fichier_entree = fopen(argv[2],"rb");
    FILE* fichier_sortie = fopen(argv[3],"w+");

    //départ du temps
    start = clock();

    decompression(fichier_entree,fichier_sortie, dico, 0);

    //boucle pour mesurer le temps
    for ( i = 0; i < 10000000; i++) {a++;}

    //fin du temps
    end=clock();

    //affichage du temps
    printf("Temps (ms) : %li\n", end-start);
    printf("Temps d'exécution (en s) : %f\n",(double)(end-start)/(double)CLOCKS_PER_SEC);

    fclose(fichier_entree);
    fclose(fichier_sortie);
  } else if ((argc == 4) & (strcmp("dt",argv[1]) == 0)) {
    printf("Décompression test\n");
    FILE* fichier_entree = fopen(argv[2],"r");
    FILE* fichier_sortie = fopen(argv[3],"w+");

    //départ du temps
    start = clock();

    decompression(fichier_entree,fichier_sortie, dico, 1);

    //boucle pour mesurer le temps
    for ( i = 0; i < 10000000; i++) {a++;}

    //fin du temps
    end=clock();

    //affichage du temps
    printf("Temps (ms) : %li\n", end-start);
    printf("Temps d'exécution (en s) : %f\n",(double)(end-start)/(double)CLOCKS_PER_SEC);

    fclose(fichier_entree);
    fclose(fichier_sortie);
  } else if ((argc == 4) & (strcmp("ct",argv[1]) == 0)){
    FILE* fichier_entree = fopen(argv[2],"r");
    FILE* fichier_sortie = fopen(argv[3],"w");

    //départ du temps
    start = clock();

    printf("Compression\n");
    compression(fichier_entree, fichier_sortie, dico, 1);

    //boucle pour mesurer le temps
    for ( i = 0; i < 10000000; i++) {a++;}

    //fin du temps
    end=clock();

    //affichage du temps
    printf("Temps (ms) : %li\n", end-start);
    printf("Temps d'exécution (en s) : %f \n",(double)(end-start)/(double)CLOCKS_PER_SEC);

    //Taille du fichier entree
    fseek(fichier_entree, 0, SEEK_END);
    printf("Taille du fichier à compresser %s : %li octet(s)\n", argv[2],ftell(fichier_entree));

    //Taille fichier sortie
    fseek(fichier_sortie, 0, SEEK_END);
    printf("Taille du fichier compressé %s : %li octet(s)\n", argv[3], ftell(fichier_sortie));

    //Taux compression
    printf("Taux de compression = %f %%\n",(double)(ftell(fichier_sortie)*100)/(double)ftell(fichier_entree) );

    fclose(fichier_entree);
    fclose(fichier_sortie);
  } else {
    printf("lzw : les options que vous avez rentré ne fonctionnent pas ! \n");
    printf("Si vous voulez compresser, utilisez 'lzw c fichier_entree fichier_sortie'. \n");
    printf("Si vous voulez décompresser, utiliser 'lzw d fichier_entree fichier_sortie'.\n");
  }

}
