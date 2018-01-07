#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  t_ptr_noeud dico = initialiser_dictionnaire();
  afficher_dictionnaire(dico);

  FILE* fichier_entree = fopen("test","rw");
  FILE* fichier_sortie = fopen("compresse","w");

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1){
    printf("Compression\n");
    int lettre = fgetc(fichier_entree);
    printf("%c", lettre);
    compression(fichier_entree, fichier_sortie, dico);
  }
  else
    printf("Décompression\n");

  return 0;


}
