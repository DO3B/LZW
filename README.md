# Compression LZW

Développement d'un algorithme de compression et de décompression
**Lempel-Ziv-Welch** dans le cadre d'un Projet d'Algorithmique.

## Pour commencer

Tout d'abord, il faut compiler.

```
make
 ```

Afin de compresser votre fichier, il faut taper la commande suivante :
 ```
 lzw c entrée sortie
 ```

 Afin de décompresser votre fichier, il faut taper la commande suivante :
  ```
  lzw d entrée sortie
  ```
  
 On peut aussi utiliser des fonctions test (lecture et écriture mais pas en binaire) :
 
 Pour compresser :
  ```
 lzw ct entrée sortie
 ```
 
 Pour décompresser :
 ```
 lzw dt entrée sortie
 ```

## À savoir

Il est important d'utiliser des ```unsigned char```à la place des ```char```, car on travaille sur du "extended ASCII".

## Auteurs

* **Léo Jean** -  aka LTPgame
* **Loïc Mayol** - aka DO3B
