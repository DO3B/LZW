#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  t_ptr_noeud dico = initialiser_dictionnaire();
  afficher_dictionnaire(dico);
<<<<<<< HEAD

  FILE* fichier_entree = fopen("test","rw");
  FILE* fichier_sortie = fopen("compresse","w");

=======
>>>>>>> adf5d1e75af05d6900f2de2891fab0d7949479c0
  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1){
    printf("Compression\n");
    int lettre = fgetc(fichier_entree);
    printf("%c", lettre);
    compression(fichier_entree, fichier_sortie, dico);
  }
  else
<<<<<<< HEAD
    printf("Décompression\n");
=======
    decompression(sortie,entree);
>>>>>>> adf5d1e75af05d6900f2de2891fab0d7949479c0

  return 0;


}
