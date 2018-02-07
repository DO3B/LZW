#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;
  long int start, end; //mesure du temps
  int i, a; //mesure du temps

  t_ptr_noeud dico = initialiser_dictionnaire();

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1){
  FILE* fichier_entree = fopen("test","r");
  FILE* fichier_sortie = fopen("compresse","wb");

  //départ du temps
  start = clock();

  printf("Compression\n");
  compression(fichier_entree, fichier_sortie, dico);

  //boucle pour mesurer le temps
  for ( i = 0; i < 10000000; i++) {a++;}

  //fin du temps
  end=clock();

  //affichage du temps
  printf("temps micro sec=%d\n", end-start);
  printf("Temps consomme (s) : %f \n",(double)(end-start)/(double)CLOCKS_PER_SEC);

  //Taille du fichier entree
  fseek(fichier_entree, 0, SEEK_END);
  printf("taille fichier_entree: %li octet(s)\n", ftell(fichier_entree));

  //Taille fichier sortie
  fseek(fichier_sortie, 0, SEEK_END);
  printf("taille fichier_sortie: %li octet(s)\n", ftell(fichier_sortie));

  //Taux compression
  printf("Taux de compression =%f\n",(double)ftell(fichier_sortie)/(double)ftell(fichier_entree) );

  fclose(fichier_entree);
  fclose(fichier_sortie);
  }
  else {
    printf("Décompression\n");
    FILE* fichier_entree = fopen("compresse","rb");
    FILE* fichier_sortie = fopen("decompresse","w+");

    //départ du temps
    start = clock();

    decompression(fichier_entree,fichier_sortie, dico);

    //boucle pour mesurer le temps
    for ( i = 0; i < 10000000; i++) {a++;}

    //fin du temps
    end=clock();

    //affichage du temps
    printf("temps micro sec=%d\n", end-start);
    printf("Temps consomme (s) : %f \n",(double)(end-start)/(double)CLOCKS_PER_SEC);

    fclose(fichier_entree);
    fclose(fichier_sortie);
  }

  return 0;


}
