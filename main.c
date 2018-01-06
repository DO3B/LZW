#include "compression.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  FILE* entree = fopen("test.txt","r");
  FILE* sortie = fopen("compresse.txt","rw");

  t_ptr_noeud dico =initialiser_dictionnaire();
  afficher_dictionnaire(dico);
  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  if (choix == 1)
    compression(entree,sortie,dico);
  else
    decompression(sortie,entree);

  return 0;


}
