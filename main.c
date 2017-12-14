#include "compression.h"
#include "fichier.h"

int main(int argc, char const *argv[]) {
  int choix = 0;

  FILE* entree = fopen("test","r");
  FILE* sortie = fopen("compresse","rw");

  printf("(1) pour Compression - (2) pour Décompression : \n");
  scanf("%d", &choix);

  if (choix)
    compression(entree,sortie);
  else
    decompression(sortie,entree);

  return 0;
}
