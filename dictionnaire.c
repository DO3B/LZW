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
  modifier_code(nouveau, code);
  modifier_lettre(nouveau, code);
  ajouter_fils(nouveau, fils);
  ajouter_frere(nouveau, frere);
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


t_ptr_noeud initialiser_dictionnaire(){
  int i;
  char lettre;
  t_ptr_noeud dico =NULL;
  for(i=0;i<255;i++){
    dico = cree_noeud(i,lettre,dico,NULL);
  }
  return dico;
}

//tableau qui pointe sur les noeuds du dictionnaire
// n est le nombre d'éléments du dictionnaire

t_ptr_noeud creertab(int n){
  t_ptr_noeud tabnoeud;
  return tabnoeud =(t_ptr_noeud)malloc( n * sizeof(t_noeud));
}
<<<<<<< HEAD
//a
=======

//tableau qui pointe sur les noeuds du dictionnaire
// n est le nombre d'éléments du dictionnaire

t_ptr_noeud creertab(int n){
  return t_ptr_noeud tabnoeud =(t_ptr_noeud)malloc( n * sizeof(t_noeud));
}
>>>>>>> b66a7dc902cbe15660037f3e6be5483f24101637

//penser au free(tabnoeud)
