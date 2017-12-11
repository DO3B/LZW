#include "compression.h"
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void compression(FILE* entree, FILE* sortie){
  unsigned char * tampon = NULL;
  int c;

  do {
    c = fgetc(entree);
    printf("%d ", c);
    fprintf(sortie, "%d ", c);
  } while(c != EOF);
}

int lire_code (FILE* arg) {
    int code = 0;
    assert (arg != NULL);

    fscanf (arg, "%d", &code);
    return code;
}

void decompression(FILE* sortie, FILE* entree){
  unsigned char * tampon = NULL;
  int code;
  while ((code = lire_code(sortie)) != 0){
    printf("%d",code);
  }
}
