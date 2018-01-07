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
#include <stdio.h>
#include <string.h>

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
unsigned char lettre_noeud(t_ptr_noeud noeud){
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
* @return rien
*/
void assigner_code(t_ptr_noeud noeud){
  static int code = 255;
  noeud->code = code;

  //Le dico a fini d'être initialisé, donc code = 260
  if(code == 1)
    code = 260;
  //On initiliase le dico
  else if(code <= 255)
    code--;
  //On ajoute juste un nouveau mot
  else
    code++;
}

/** @brief Modifie la lettre du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouvelle lettre
* @return rien
*/
void modifier_lettre(t_ptr_noeud noeud, unsigned char lettre){
  noeud->lettre = lettre;
}

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

/** @brief Créé un noeud
* @param code -> entier contenant le code
* @param lettre -> lettre associée au noeud
* @param frere -> pointeur vers le frère
* @param fils -> pointeur vers le fils
* @return Un nouveau noeud avec les paramètres ci-dessus
*/
t_ptr_noeud cree_noeud(unsigned char lettre, t_ptr_noeud frere, t_ptr_noeud fils){
  t_ptr_noeud nouveau;
  nouveau = (t_ptr_noeud) malloc(sizeof(t_noeud));

  modifier_lettre(nouveau, lettre);
  ajouter_fils(nouveau, fils);
  ajouter_frere(nouveau, frere);
  assigner_code(nouveau);
  table[code_noeud(nouveau)] = nouveau;

  return nouveau;
}

/** @brief Initialise un dictionnaire
* @return Un arbre contenant les 255 caractères ASCII
*/
t_ptr_noeud initialiser_dictionnaire(){
  t_ptr_noeud dico = NULL;
  unsigned char lettre;

  //Marche en décrémentant mais pas en incrémentant pour des raisons que j'ignore
  for(lettre = 255; lettre != 0; lettre--)
    dico = cree_noeud(lettre,dico,NULL);

  return dico;
}

/** @brief Supprime un dictionnaire
* @param Dictionnaire que l'on souhaite supprimer
* @return Rien
*/
void supprimer_dictionnaire(t_ptr_noeud dico){
  t_ptr_noeud noeud = dico;

  if(fils_noeud(noeud) != NULL)
    supprimer_dictionnaire(fils_noeud(noeud));

  if(frere_noeud(noeud) != NULL)
    supprimer_dictionnaire(frere_noeud(noeud));

  if(pere_noeud(noeud) != NULL)
    supprimer_dictionnaire(pere_noeud(noeud));

  free(noeud);
}

/** @brief Recherche un caractère dans le dictionnaire
* @param Dictionnaire que l'on souhaite parcourir
* @param Chaîne de caractère
* @return Le code de la chaîne
*/
int rechercher_dictionnaire(t_ptr_noeud dico, unsigned char* chaine){
  t_ptr_noeud noeud = dico;

  if(dico == NULL){
    return 0;
  }

  if(lettre_noeud(noeud) == chaine[0]){
  //si chaine a une seule lettre, retourne le code
    if(strlen((char*)chaine) == 1)
      return code_noeud(noeud);
    else
      return rechercher_dictionnaire(fils_noeud(noeud), &chaine[1]);
  } else {
    if(lettre_noeud(noeud) > chaine[0])
      return 0;
    else
      return rechercher_dictionnaire(frere_noeud(noeud), chaine);
  }
}

/** @brief Affiche le dictionnaire
* @param Dictionnaire que l'on souhaite afficher
* @return Rien
*/
void afficher_dictionnaire(t_ptr_noeud dico){
  printf("%d %c\n", code_noeud(dico), lettre_noeud(dico));

  if(fils_noeud(dico) != NULL)
    afficher_dictionnaire(fils_noeud(dico));

  if(frere_noeud(dico) != NULL)
    afficher_dictionnaire(frere_noeud(dico));
}

t_ptr_noeud ajout_plusieurs_fils(unsigned char* chaine){
  int i;
  t_ptr_noeud noeud;

  for(i=0; i != strlen((char*)chaine); i++)
    noeud = cree_noeud(chaine[i], NULL, noeud);

  return noeud;
}

t_ptr_noeud ajout_dico(t_ptr_noeud dico, unsigned char* chaine){
  //Fin de caractère, on retourne le dictionnaire
  if(chaine[0] == '\0')
    return dico;

  if(dico == NULL)
    return ajout_plusieurs_fils(chaine);

  t_ptr_noeud noeud = dico;

  if(lettre_noeud(noeud) > chaine[0])
    noeud = cree_noeud(chaine[0], noeud, ajout_plusieurs_fils(&chaine[1]));
  if(lettre_noeud(noeud) < chaine[0])
    ajouter_frere(noeud, ajout_dico(frere_noeud(noeud), chaine));
  else
    ajouter_fils(noeud, ajout_dico(fils_noeud(noeud), &chaine[1]));
  /*if(rechercher_dictionnaire(noeud, &chaine[0])){
    int code = rechercher_dictionnaire(noeud, &chaine[0]);
    noeud = table[code];
    if(fils_noeud(noeud) != NULL){
      while (frere_noeud(fils_noeud(noeud)) != NULL) {
        noeud = frere_noeud(noeud);
      }
      if(strlen(chaine) == 2)
        ajouter_frere(noeud, cree_noeud(chaine[1],noeud,NULL));
      else
        ajouter_frere(noeud,cree_noeud(chaine[1],noeud,ajout_plusieurs_fils(&chaine[2])));
    }else
      ajouter_fils(noeud, cree_noeud(chaine[1], NULL, ajout_plusieurs_fils(&chaine[2])));
  } else
    noeud = cree_noeud(chaine[0], noeud, ajout_plusieurs_fils(&chaine[1]));*/

  return noeud;
}
