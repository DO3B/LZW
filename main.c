#include "compression.h"
#include "fichier.h"

int main(int argc, char const *argv[]) {

  char* test = concatene('./',argv[0]);
  char* test1 = concatene('./',argv[1]);
  FILE* entree = fopen(test,"rw");
  FILE* sortie = fopen(test1,"rw");
  compression(entree,sortie);
  //decompression(sortie,entree);
  return 0;
}
