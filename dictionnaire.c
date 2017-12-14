#include "dictionnaire.h"

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
  return noeud->code = code;
}

void modifier_lettre(t_ptr_noeud noeud, char lettre){
  return noeud->lettre = lettre;
}
t_ptr_arbre initialiser_dictionnaire(){

  return dictionnaire;
}
