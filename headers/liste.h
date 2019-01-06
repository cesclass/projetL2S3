/**
 * @file liste.h
 * @author Vincent Dugat and Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#ifndef listeSTAT
#define listeSTAT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIMMAX 100  // taille maximale de la liste statique
#define VIDE -1     // constante  pour indiquer que la liste est vide (par convention)

/*----------------------------------
        Déclaration des types
  ----------------------------------*/

typedef struct s_arc_p { /// arc pondéré
  int orig;
  int dest;
  int poids;
} t_arc_p;

typedef t_arc_p Elementliste;

struct liste {
    Elementliste Tabliste[DIMMAX];
    int Tete;
    int nbElt;
};

typedef struct liste liste;

void saisie_element(Elementliste *e);
void copie_element(Elementliste *cible, Elementliste source);
void afficher_element(Elementliste e, FILE *fp);
bool cmp_elements(Elementliste e1, Elementliste e2);

int nbEltList(liste lst); // nombre d'éléments
void createList(liste *p); // renvoie une liste statique
void addFrontList(liste *p, Elementliste e); // ajoute un élément devant
void addTailList(liste *p, Elementliste e); // ajoute un élément derrière
void delTailList(liste *p); // supprime l'élément de fin
void delFrontList(liste *p); // supprime l'élément de tête
void headList(liste p, Elementliste *e); // renvoie l'élément de tête
void tailList(liste p, Elementliste *e); // renvoie l'élément de fin
bool emptyList(liste p); // renvoie true si la pile est vide, false sinon
bool fullList(liste p); // renvoie true si la pile est pleine, false sinon
void dumpList(liste p, FILE *fp); // affiche le contenu de la liste
void swapEltList(Elementliste *a, Elementliste *b); // échange deux éléments de la liste
void bubbleSortList(liste *p); // trie la liste
void pickEltList(liste l, Elementliste *e, int index); // renvoie l'élément n° index
bool belongEltList(liste p, Elementliste e); // true si l'élément est dans la liste

#endif
