#include "compression.c"
#include "fichier.c"

int main(int argc, char const *argv[]) {

  ouvrir_fichier("test", "compresse");
  char chaine1[] = "Leole";

  printf("%s",concatene(chaine1,"fragile"));
  return 0;
}
