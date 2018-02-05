#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  t_ptr_noeud dico = initialiser_dictionnaire();

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1){
    FILE* fichier_entree = fopen("test","r");
    FILE* fichier_sortie = fopen("compresse","w");
    printf("Compression\n");
    compression(fichier_entree, fichier_sortie, dico);
    fclose(fichier_entree);
    fclose(fichier_sortie);
  }
  else {
    printf("Décompression\n");
    FILE* fichier_entree = fopen("compresse","r");
    FILE* fichier_sortie = fopen("decompresse","w");
    decompression(fichier_entree,fichier_sortie, dico);
    fclose(fichier_entree);
    fclose(fichier_sortie);
  }

  return 0;


}
