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
 * @version 1.0.0 / 08-02-2018
 */

/**
 * @file dictionnaire.c
 * @brief Contient tout les fonctions relatives au fonctionnement du
 * dictionnaire
 */


#include "dictionnaire.h"
#include "compression.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int PLEIN = 0;

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

/** @brief Renvoie le père du noeud
* @param noeud -> noeud dont on souhaite connaître le père
* @return Le pointeur vers le père du noeud
*/
t_ptr_noeud pere_noeud(t_ptr_noeud noeud){
  return noeud->pere;
}

/** @brief Modifie le code du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param initialise -> initiliase si à 1
* @return rien
*/
void assigner_code(t_ptr_noeud noeud, int initialise){
  static int code = 255;
  static int code_max = 0;

  if(initialise){
    code = 255;
    code_max = MAX - 1;
    PLEIN = 0;
  }

  noeud->code = code;

  //Le dico a fini d'être initialisé, donc code = 260
  if(code == 1)
    code = 260;
  //On initialise le dico
  else if(code <= 255)
    code--;
  //On ajoute juste un nouveau mot
  else
    code++;

  if(code >= code_max)
    PLEIN = 1;
}

/** @brief Modifie la lettre du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param code -> nouvelle lettre
* @return rien
*/
void modifier_lettre(t_ptr_noeud noeud, unsigned char lettre){
  noeud->lettre = lettre;
}

/** @brief Modifie le fils du noeud ou l'ajoute
* @param pere -> noeud que l'on souhaite modifier
* @param fils -> nouveau fils
* @return rien
*/
void ajouter_fils(t_ptr_noeud pere, t_ptr_noeud fils){
  pere->fils=fils;
}

/** @brief Modifie le frère du noeud ou l'ajoute
* @param pere -> noeud que l'on souhaite modifier
* @param frere -> nouveau frère
* @return rien
*/
void ajouter_frere(t_ptr_noeud pere, t_ptr_noeud frere){
  pere->frere=frere;
}

/** @brief Modifie le père du noeud ou l'ajoute
* @param noeud -> noeud que l'on souhaite modifier
* @param pere -> nouveau père
* @return rien
*/
void ajouter_pere(t_ptr_noeud noeud, t_ptr_noeud pere){
  noeud->pere=pere;
}

/** @brief Créé un noeud
* @param code -> entier contenant le code
* @param lettre -> lettre associée au noeud
* @param frere -> pointeur vers le frère
* @param fils -> pointeur vers le fils
* @param pere -> pointeur vers le père
* @param initialise -> initialise assigner_code si à 1
* @return Un nouveau noeud avec les paramètres ci-dessus
*/
t_ptr_noeud cree_noeud(unsigned char lettre, t_ptr_noeud frere, t_ptr_noeud fils, t_ptr_noeud pere, int initialise){
  t_ptr_noeud nouveau;
  nouveau = (t_ptr_noeud) malloc(sizeof(t_noeud));

  modifier_lettre(nouveau, lettre);
  ajouter_fils(nouveau, fils);
  ajouter_frere(nouveau, frere);
  ajouter_pere(nouveau, pere);
  assigner_code(nouveau, initialise);
  table[code_noeud(nouveau)] = nouveau;

  return nouveau;
}

/** @brief Initialise un dictionnaire
* @return Un arbre contenant les 255 caractères ASCII
*/
t_ptr_noeud initialiser_dictionnaire(){
  t_ptr_noeud dico = NULL;
  unsigned char lettre = 255;

  dico = cree_noeud(lettre, dico, NULL, NULL, 1);
  //Marche en décrémentant mais pas en incrémentant (car assigner_code)
  for(lettre = 254; lettre != 0; lettre--)
    dico = cree_noeud(lettre,dico,NULL,NULL,0);

  return dico;
}

/** @brief Supprime un dictionnaire
* @param dico -> dictionnaire que l'on souhaite supprimer
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
* @param dico -> dictionnaire que l'on souhaite parcourir
* @param chaine -> chaîne de caractères dont l'on cherche le code
* @return Le code de la chaîne
*/
int rechercher_caractere(t_ptr_noeud dico, unsigned char* chaine){
  t_ptr_noeud noeud = dico;

  if(dico == NULL){
    return 0;
  }

  if(lettre_noeud(noeud) == chaine[0]){
  //si chaine a une seule lettre, retourne le code
    if(strlen((char*)chaine) == 1)
      return code_noeud(noeud);
    else
      return rechercher_caractere(fils_noeud(noeud), &chaine[1]);
  } else {
    if(lettre_noeud(noeud) > chaine[0])
      return 0;
    else
      return rechercher_caractere(frere_noeud(noeud), chaine);
  }
}

/** @brief Recherche un mot dans le dictionnaire
* @param dico -> dictionnaire que l'on souhaite parcourir
* @param code -> code dont l'on cherche la chaîne de caractères associée
* @return Le code de la chaîne
*/
unsigned char* rechercher_mot(t_ptr_noeud dico, int code){
  t_ptr_noeud noeud = table[code];

  unsigned char* mot = malloc(MAX * sizeof(unsigned char));
  int i = 1;
  if(noeud == NULL){
    return mot = NULL;
  }

  mot[0]=lettre_noeud(noeud);

  while(pere_noeud(noeud) != NULL){
    noeud = pere_noeud(noeud);
    mot[i] = lettre_noeud(noeud);
    i++;
  }

  unsigned char* motf = malloc(i*sizeof(unsigned char));
  int j = 0;

  for(i = i - 1 ; i >= 0; i--){
    motf[j] = mot[i];
    j++;
  }
  motf = concat(motf,"\0");
  return motf;
}

/** @brief Affiche le dictionnaire
* @param dico -> dictionnaire que l'on souhaite afficher
* @return Rien
*/
void afficher_dictionnaire(t_ptr_noeud dico){
  printf("%d %c\n", code_noeud(dico), lettre_noeud(dico));

  if(fils_noeud(dico) != NULL)
    afficher_dictionnaire(fils_noeud(dico));

  if(frere_noeud(dico) != NULL)
    afficher_dictionnaire(frere_noeud(dico));

//  if(pere_noeud(dico) != NULL)
//    afficher_dictionnaire(pere_noeud(dico));
}

/** @brief Ajoute plusieurs à la fils à la suite du noeud
* @param pere -> père des fils que l'on souhaite ajouter
* @param chaine -> chaîne de caractères que l'on souhaite ajouter dans l'arbre
* @return Rien
*/
t_ptr_noeud ajout_plusieurs_fils(t_ptr_noeud pere, unsigned char* chaine){
  t_ptr_noeud noeud = cree_noeud(chaine[0],NULL,NULL,pere,0);
  t_ptr_noeud tmp = NULL;
  int i;

  ajouter_fils(pere,noeud);
  for (i = 1; i<strlen((char*)chaine);i++){
    tmp=noeud;
    noeud= cree_noeud(chaine[i],NULL,NULL,tmp,0);
    ajouter_fils(tmp,noeud);
  }
  return pere;
}

/** @brief Ajoute un mot au dictionnaire
* @param dico -> dictionnaire
* @param chaine -> chaîne de caractères que l'on souhaite ajouter dans l'arbre
* @return Le dictionnaire mis à jour.
*/
t_ptr_noeud ajout_dico(t_ptr_noeud dico, unsigned char* chaine){
  //Fin de caractère, on retourne le dictionnaire
  if(chaine[0] == '\0')
    return dico;

  t_ptr_noeud noeud = dico;

  if(lettre_noeud(noeud) == chaine[0]){
    if(fils_noeud(noeud) == NULL)
      return ajout_plusieurs_fils(noeud,&chaine[1]);
    ajouter_fils(noeud, ajout_dico(fils_noeud(noeud), &chaine[1]));
  }else if(lettre_noeud(noeud) > chaine[0]){
    noeud = cree_noeud(chaine[0], noeud, NULL,pere_noeud(noeud),0);
    noeud = ajout_plusieurs_fils(noeud,&chaine[1]);
  }else{
    if(frere_noeud(noeud) == NULL){
      noeud = cree_noeud(chaine[0], noeud, NULL, pere_noeud(noeud),0);
      return ajout_plusieurs_fils(noeud, &chaine[1]);
    }
    ajouter_frere(noeud, ajout_dico(frere_noeud(noeud), chaine));
  }

  return noeud;
}
