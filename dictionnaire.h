#ifndef __DICTIONNAIRE_H_
#define __DICTIONNAIRE_H_
#define MAX 1024

typedef struct noeud{
  int code;
  char lettre;
  struct noeud* frere;
  struct noeud* fils;
  struct noeud* pere;
} t_noeud, *t_ptr_noeud;

t_ptr_noeud table[MAX];

#endif
