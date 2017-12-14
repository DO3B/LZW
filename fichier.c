#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static FILE * entree = NULL;
static FILE * sortie = NULL;

/*void ouvrir_fichier(char* nom_entree, char* nom_sortie){
  entree = fopen(nom_entree, "r");
  sortie = fopen(nom_sortie, "rw");
}*/

void fermer_fichier(){
  fclose(entree);
  fclose(sortie);
}

char* concatene(char *s1, char *s2){
  int i,j;

  i = 0; //va contenir la taille de s1
  while (s1[i] != '\0') i++;

  j = 0;
  do {
    s1[i++] = s2[j];
  } while(s2[j++] != '\0');

  return s1;
}
