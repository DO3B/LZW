#include "compression.h"
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void compression(FILE* entree, FILE* sortie){
  unsigned char * tampon = NULL;
  int code;
  unsigned char * res;

  do {
    code = fgetc(entree);
    res=concatene(tampon,lettre);
    if(existedico(res)) tampon=res;
    else{
      ajout_dico(res);
      tampon=lettre;
    }
  } while(code != EOF);
}

int lire_code (FILE* fichier) {
    int code;
    fscanf (fichier, "%d", &code);
    return code;
}

void decompression(FILE* sortie, FILE* entree){
  unsigned char * previous = NULL;
  int code = lire_code(sortie);
  while (code != EOF){
    printf("essai");
    fputc(code, entree);
    code = lire_code(sortie);
  }
}
