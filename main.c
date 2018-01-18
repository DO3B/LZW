#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  t_ptr_noeud dico = initialiser_dictionnaire();
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
  else {
    printf("Décompression\n");
    unsigned char* essai = "ebc";
    unsigned char* essai2 = "etc";
    dico = ajout_dico(dico, essai);
    printf("%d\n", code_noeud(pere_noeud(table[260])));
    /*decompression(fichier_sortie,fichier_entree, dico);*/
  }

  fclose(fichier_entree);
  fclose(fichier_sortie);
  return 0;


}
