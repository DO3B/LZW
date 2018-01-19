#include <stdio.h>
#include <stdlib.h>

/* attention, ici utilisation de unsigned int (4 octets) */


unsigned int deux_puissance[32];
/* pour stocker les puissances de 2
   et ne pas avoir a les recalculer a chaque fois */


unsigned int puissance(char bit)
{int i, res=1;
 for (i=0; i< bit; i++) res*=2;
 return res;
 }


char valeur_bit(unsigned int x, char i) /* donne la valeur du ieme bit */
{return ((x & deux_puissance[i]) == 0) ? 0 : 1; }


void visualiser(unsigned int x)
{int i;
 printf("nombre = %d\n",x);
 for (i=31; i>=0; i--) printf("%d",valeur_bit(x,i));
 printf("\n");
}


void mise_a_un(unsigned int *x, char i) /* mise a 1 du ieme bit */
{ *x=*x | deux_puissance[i]; }


void mise_a_zero(unsigned int *x, char bit) /* mise a 0 du ieme bit */
{ unsigned int y=0;
  y--; /* pour avoir des 1 partout */
  y = y ^ (deux_puissance[bit]);
  /* ou exclusif pour faire apparaitre un 0 sur bit */
  *x=*x & y;
}



int main()/* petit programme principal pour tester */
{
  int i;
  char bit;
  unsigned x = 0;

  for (i=0;i<32;i++) deux_puissance[i]=puissance(i);

  visualiser(x);

  mise_a_un(&x,0); /* mise a 1 du bit d'indice 0 de x */
  visualiser(x);

  mise_a_un(&x,1);
  visualiser(x);

  mise_a_un(&x,2);
  visualiser(x);

  mise_a_zero(&x,1);
  visualiser(x);
}


/*****************************************************************************

nombre = 0
00000000000000000000000000000000
nombre = 1
00000000000000000000000000000001
nombre = 3
00000000000000000000000000000011
nombre = 7
00000000000000000000000000000111
nombre = 5
00000000000000000000000000000101

******************************************************************************/
