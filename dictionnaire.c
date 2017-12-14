#include "dictionnaire.h"
#include <stdlib.h>

int code_noeud(t_ptr_noeud noeud){
  return noeud->code;
}

char lettre_noeud(t_ptr_noeud noeud){
  return noeud->lettre;
}

t_ptr_noeud frere_noeud(t_ptr_noeud noeud){
  return noeud->frere;
}

t_ptr_noeud fils_noeud(t_ptr_noeud noeud){
  return noeud->fils;
}

t_ptr_noeud pere_noeud(t_ptr_noeud noeud){
  return noeud->pere;
}

void modifier_code(t_ptr_noeud noeud, int code){
  noeud->code = code;
  return;
}

void modifier_lettre(t_ptr_noeud noeud, char lettre){
  noeud->lettre = lettre;
  return;
}

t_ptr_noeud cree_noeud(int code,char lettre, t_ptr_noeud frere, t_ptr_noeud fils){
  t_ptr_noeud nouveau;
  nouveau=(t_ptr_noeud)malloc(sizeof(t_noeud));
  nouveau->code=code;
  nouveau->lettre=lettre;
  nouveau->frere=frere;
  nouveau->fils=fils;
  return nouveau;
}

void ajouter_fils(t_ptr_noeud pere, t_ptr_noeud fils){
  pere->fils=fils;
  return;
}

void ajouter_frere(t_ptr_noeud pere, t_ptr_noeud frere){
  pere->frere=frere;
  return;
}

/*t_ptr_noeud initialiser_dictionnaire(){

  return dictionnaire;
}*/
