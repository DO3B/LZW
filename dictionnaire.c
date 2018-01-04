/**
 *
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author JEAN Léo <leo.jean@etu.univ-amu.fr>
 * @author MAYOL Loïc <loic.mayol@etu.univ-amu.fr>
 *
 * @version 0.0.1 / 20-09-2012
 */

/**
 * @file dictionnaire.c
 * @brief Contient tout les fonctions relatives au fonctionnement du
 * dictionnaire
 */


#include "dictionnaire.h"
#include <stdlib.h>

/** @brief Renvoie le code du noeud
* @param noeud -> noeud dont on souhaite connaître le code
* @return Le code du noeud en paramètre
*/
int code_noeud(t_ptr_noeud noeud){
  return noeud->code;
}

/** @brief Renvoie la lettre correspondant au noeud
* @param noeud -> noeud dont on souhaite connaître la lettre
* @return La lettre du noeud en paramètre
*/
char lettre_noeud(t_ptr_noeud noeud){
  return noeud->lettre;
}

/** @brief Renvoie la frère du noeud
* @param noeud -> noeud dont on souhaite connaître le frère
* @return Le pointeur vers le frère du noeud
*/
t_ptr_noeud frere_noeud(t_ptr_noeud noeud){
  return noeud->frere;
}

/** @brief Renvoie la fils du noeud
* @param noeud -> noeud dont on souhaite connaître le fils
* @return Le pointeur vers le fils du noeud
*/
t_ptr_noeud fils_noeud(t_ptr_noeud noeud){
  return noeud->fils;
}

/** @brief Renvoie la père du noeud
* @param noeud -> noeud dont on souhaite connaître le père
* @return Le pointeur vers le père du noeud
*/
t_ptr_noeud pere_noeud(t_ptr_noeud noeud){
  return noeud->pere;
}

/** @brief Modifie le code du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouveau code
* @return rien
*/
void modifier_code(t_ptr_noeud noeud, int code){
  noeud->code = code;
}

/** @brief Modifie la lettre du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouvelle lettre
* @return rien
*/
void modifier_lettre(t_ptr_noeud noeud, char lettre){
  noeud->lettre = lettre;

/** @brief Modifie la lettre du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouvelle lettre
* @return rien
*/
void ajouter_fils(t_ptr_noeud pere, t_ptr_noeud fils){
  pere->fils=fils;
}

/** @brief Modifie la lettre du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouvelle lettre
* @return rien
*/
void ajouter_frere(t_ptr_noeud pere, t_ptr_noeud frere){
  pere->frere=frere;
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

//penser au free(tabnoeud)
=======
/** @brief Créer un noeud
* @param code -> entier contenant le code
* @param lettre -> lettre associée au noeud
* @param frere -> pointeur vers le frère
* @param fils -> pointeur vers le fils
* @return Un nouveau noeud avec les paramètres ci-dessus
*/
t_ptr_noeud cree_noeud(int code,char lettre, t_ptr_noeud frere, t_ptr_noeud fils){
  t_ptr_noeud nouveau;
  nouveau = (t_ptr_noeud) malloc(sizeof(t_noeud));

  modifier_code(nouveau, code);
  modifier_lettre(nouveau, code);
  ajouter_fils(nouveau, fils);
  ajouter_frere(nouveau, frere);

  return nouveau;
}

t_ptr_noeud initialiser_dictionnaire(){
  int i;
  for(i=0;i<255;i++){

  }
  return dictionnaire;
}
