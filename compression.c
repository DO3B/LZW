#include "compression.h"
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void compression(FILE* entree, FILE* sortie){
  unsigned char * tampon = NULL;
  int code;

  do {
    code = fgetc(entree);
    fprintf(sortie, "%d ", code);
  } while(code != EOF);
  fermer_fichier();
}

int lire_code (FILE* arg) {
    int code = 0;
    assert (arg != NULL);

    fscanf (arg, "%d", &code);
    return code;
}

void decompression(FILE* sortie, FILE* entree){
  unsigned char * tampon = NULL;
  FILE* sortie2 = fopen("sortie2","rw+");
  int code;
  while ((code = lire_code(sortie)) != 0){
    fputc(code, sortie2);
  }
  fermer_fichier();
  fclose(sortie2);
}
