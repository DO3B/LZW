#include "compression.h"
#include "fichier.h"
#include "dictionnaire.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  FILE* entree = fopen("test.txt","r");
  FILE* sortie = fopen("compresse.txt","rw");

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);
  t_ptr_noeud dico =initialiser_dictionnaire();
  if (choix == 1)
    compression(entree,sortie);
  else
    decompression(sortie,entree);

  return 0;


}
