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

int code_noeud(t_ptr_noeud noeud);
char lettre_noeud(t_ptr_noeud noeud);
t_ptr_noeud frere_noeud(t_ptr_noeud noeud);
t_ptr_noeud fils_noeud(t_ptr_noeud noeud);
t_ptr_noeud pere_noeud(t_ptr_noeud noeud);
void modifier_code(t_ptr_noeud noeud, int code);
void modifier_lettre(t_ptr_noeud noeud, char lettre);
t_ptr_noeud cree_noeud(int code,char lettre, t_ptr_noeud frere, t_ptr_noeud fils);
void ajouter_fils(t_ptr_noeud pere, t_ptr_noeud fils);
void ajouter_frere(t_ptr_noeud pere, t_ptr_noeud frere);
t_ptr_noeud initialiser_dictionnaire();
t_ptr_noeud table[MAX];
t_ptr_noeud creertab(int n);
#endif
