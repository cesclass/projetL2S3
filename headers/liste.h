/**
 * @file liste.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des fonctions et structures pour l'utilisation d'arcs pondere 
 *      et de listes cirtulaires
 * 
 * @copyright Licence MIT
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

/**
 * @brief Structure d'arc pondere
 * 
 */
typedef struct s_arc_p {
  int orig;
  int dest;
  int poids;
} t_arc_p;

typedef t_arc_p Elementliste;

/**
 * @brief Structure de liste circulaire d'arcs
 * 
 */
struct liste {
    Elementliste Tabliste[DIMMAX];
    int Tete;
    int nbElt;
};

typedef struct liste liste;

/**
 * @brief Permet la saisie d'un Element par l'utilisateur
 * 
 * @param e   Element
 */
void saisie_element(Elementliste *e);

/**
 * @brief Copie un Element
 * 
 * @param cible   Element
 * @param source  Element
 */
void copie_element(Elementliste *cible, Elementliste source);

/**
 * @brief Affiche un Element
 * 
 * @param e   Element
 * @param fp  Sortie de l'affichage
 */
void afficher_element(Elementliste e, FILE *fp);

/**
 * @brief Compare deux Elements
 * 
 * @param e1      Element
 * @param e2      Element
 * @return true   Les deux Elements sont les mêmes
 * @return false  Les deux Elements ne sont pas les mêmes
 */
bool cmp_elements(Elementliste e1, Elementliste e2);

/**
 * @brief Renvoie le nombre d'Elements dans une liste
 * 
 * @param   Liste
 * @return  Nb Element dans la liste
 */
int nbEltList(liste lst);

/**
 * @brief Initialise une liste
 * 
 * @param p   Liste
 */
void createList(liste *p);

/**
 * @brief Ajoute un Element au debut de la liste
 * 
 * @param p   Liste
 * @param e   Element
 */
void addFrontList(liste *p, Elementliste e); // ajoute un élément devant

/**
 * @brief Ajoute un Element a la fin de la liste
 * 
 * @param p   Liste
 * @param e   Element
 */
void addTailList(liste *p, Elementliste e); // ajoute un élément derrière

/**
 * @brief Supprime le dernier Element de la liste
 * 
 * @param p   Liste
 */
void delTailList(liste *p); // supprime l'élément de fin

/**
 * @brief Supprime le premier Element de la liste
 * 
 * @param p   Liste
 */
void delFrontList(liste *p);

/**
 * @brief Recupere le premier Element de la liste
 * 
 * @param p   Liste
 * @param e   Element
 */
void headList(liste p, Elementliste *e);

/**
 * @brief Recupere le dernier Element de la liste
 * 
 * @param p   Liste
 * @param e   Element
 */
void tailList(liste p, Elementliste *e);

/**
 * @brief Determine si la liste est vide
 * 
 * @param p       Liste
 * @return true   La liste est vide
 * @return false  La liste n'est pas vide
 */
bool emptyList(liste p);

/**
 * @brief Determine si la liste est pleine
 * 
 * @param p       Liste
 * @return true   La liste est pleine
 * @return false  La liste n'est pas pleine
 */
bool fullList(liste p);

/**
 * @brief Vide la liste et affiche son contenue
 * 
 * @param p   Liste
 * @param fp  Sortie de l'affichate
 */
void dumpList(liste p, FILE *fp);

/**
 * @brief Echange deux Elements
 * 
 * @param a   Element
 * @param b   Element
 */
void swapEltList(Elementliste *a, Elementliste *b);

/**
 * @brief Trie la liste avec le systeme bubbleSort
 * 
 * @param p   Liste
 */
void bubbleSortList(liste *p);

/**
 * @brief Pioche un Element dans la liste
 * 
 * @param l       Liste
 * @param e       Element pioche
 * @param index   Index de l'Element a piocher
 */
void pickEltList(liste l, Elementliste *e, int index);

/**
 * @brief Cherche la presence d'un Element dans une liste
 * 
 * @param p       Liste a parcourir
 * @param e       Element a chercher
 * @return true   L'element est dans la liste
 * @return false  L'element n'est pas dans la liste
 */
bool belongEltList(liste p, Elementliste e);

#endif
