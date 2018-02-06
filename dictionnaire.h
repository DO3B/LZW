#ifndef __DICTIONNAIRE_H_
#define __DICTIONNAIRE_H_
#define NB_BITS 9
#define MAX 1024

typedef struct noeud{
  int code;
  unsigned char lettre;
  struct noeud* frere;
  struct noeud* fils;
  struct noeud* pere;
} t_noeud, *t_ptr_noeud;

t_ptr_noeud table[MAX];

int code_noeud(t_ptr_noeud noeud);
unsigned char lettre_noeud(t_ptr_noeud noeud);
t_ptr_noeud frere_noeud(t_ptr_noeud noeud);
t_ptr_noeud fils_noeud(t_ptr_noeud noeud);
t_ptr_noeud pere_noeud(t_ptr_noeud noeud);
void assigner_code(t_ptr_noeud noeud, int initialise);
void modifier_lettre(t_ptr_noeud noeud,unsigned char lettre);
t_ptr_noeud cree_noeud(unsigned char lettre, t_ptr_noeud frere, t_ptr_noeud fils, t_ptr_noeud pere, int initialise);
void ajouter_fils(t_ptr_noeud pere, t_ptr_noeud fils);
void ajouter_frere(t_ptr_noeud pere, t_ptr_noeud frere);
t_ptr_noeud initialiser_dictionnaire();
int rechercher_caractere(t_ptr_noeud dico,unsigned char* chaine);
unsigned char* rechercher_mot(t_ptr_noeud dico, int code);
void afficher_dictionnaire(t_ptr_noeud dico);
t_ptr_noeud ajout_plusieurs_fils(t_ptr_noeud pere,unsigned char* chaine);
t_ptr_noeud ajout_dico(t_ptr_noeud dico,unsigned char* chaine);
#endif
