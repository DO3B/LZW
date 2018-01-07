#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  t_ptr_noeud dico = initialiser_dictionnaire();
  afficher_dictionnaire(dico);

  FILE* fichier_entree = fopen("test","r");
  if(fichier_entree != NULL)
    printf("Travail terminé !\n");
  else
    printf("ça ne marche pas :'(");
  FILE* fichier_sortie = fopen("compresse","w");

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1){
    printf("Compression\n");
    compression(fichier_entree, fichier_sortie, dico);
  }
  else
    printf("Décompression\n");
    /*decompression(fichier_sortie,fichier_entree);*/

  fclose(fichier_entree);
  fclose(fichier_sortie);
  return 0;


}
