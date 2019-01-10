/**
 * @file squelette.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des structures de donnes principales et
 *      des fonctions permettant de les utilises.
 * 
 * @copyright Licence MIT
 * 
 */

#ifndef SQUELETTE
#define SQUELETTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// Definition de constantes pour la construction de "t_mat_str_dyn"
#define DEFAULT_ROWS 1000   // Nombre de lignes par defaut
#define DEFAULT_COLS 100    // Nombre de colonnes par defaut
#define DEFAULT_LEN 50      // Nombre de caractere par case par defaut

/**
 * @brief Structure contenant un tableau d'entiers et sa taille
 * 
 */
typedef struct s_tab_dyn{
  int * tab;
  int dim;
} t_tab_int_dyn;

/**
 * @brief Structure contenant une matrice d'entiers et sa taille
 * 
 */
typedef struct s_mat_dyn{
  int ** tab;
  int nbRows;
  int nbCols;
} t_mat_int_dyn;

/**
 * @brief Structure contenant une matrices de chaines de caracteres et sa taille
 * 
 */
typedef struct s_mat_char_dyn{
  char *** tab;
  int nbRows;
  int nbCols;
  int offset; // donne le nombre de colonnes avant celles des candidats
} t_mat_str_dyn;

/**
 * @brief Cree et renvoie un tableau d'entiers
 * 
 * @param dim   Taille du tableau
 * @return int* Tableau d'entiers
 */
int * creer_tab_int(int dim);

/**
 * @brief Cree et renvoie une matrice d'entiers
 * 
 * @param nbRows  Nb de lignes de la matrice
 * @param nbCols  Nb de colonnes de la matrice
 * @return int**  Matrice d'entiers
 */
int ** creer_mat_int(int nbRows, int nbCols);

/**
 * @brief Initialisation d'un tableau d'entiers
 * 
 * @param tab     Tableau d'entiers
 * @param dim     Taille du tableau
 * @param valeur  Valeur a mettre dans les cases
 */
void init_tab_int(int *tab, int dim, int valeur);

/**
 * @brief Initialisation d'une matrice d'entiers
 * 
 * @param mat     Matrice d'entier
 * @param nbRows  Nb de lignes de la matrice
 * @param nbCols  Nb de colonnes de la matrice
 * @param valeur  Valeur a mettre dans les cases
 */
void init_mat_int(int **mat, int nbRows, int nbCols, int valeur);

/**
 * @brief Affiche le contenue d'un tableau d'entiers
 * 
 * @param tab   Tableau d'entiers
 * @param dim   Taille du tableau
 * @param logfp Sortie de l'affichage
 */
void affiche_tab_int(int *tab, int dim, FILE *logfp);

/**
 * @brief Affiche le contenue d'une matrice d'entiers
 * 
 * @param duels_mat   Matrice d'entiers
 * @param nbRows      Nombre de lignes de la matrice
 * @param nbCols      Nombre de colonne de la matrice
 * @param logfp       Sortie de l'affichage
 */
void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp);

// STRUCT ==================================================

/**
 * @brief Initialisation d'une structure t_mat_int_dyn
 * 
 * @param stTab   Structure a initialiser
 * @param nbRows  Nb de lignes de la matrice d'entiers dans la structure
 * @param nbCols  Nb de colonnes de la matrice d'entiers dans la structure
 */
void creer_t_mat_int_dyn(t_mat_int_dyn *stTab, int nbRows, int nbCols);

/**
 * @brief Initialisation d'une structure t_tab_int_dyn
 * 
 * @param stTab   Structure a initialiser
 * @param dim     Taille du tableau dans la structure
 */
void creer_t_tab_int_dyn(t_tab_int_dyn *stTab, int dim);

/**
 * @brief Initialisation d'une structure t_mat_str_dyn
 * 
 * @param s_tabmots   Structure a initialiser
 */
void creer_t_mat_str_dyn(t_mat_str_dyn * s_tabmots);

/**
 * @brief Affiche le contenue d'un tableau d'entiers
 * 
 * @param t_tab   Structure contenant le tableau d'entiers
 * @param logfp   Sortie de l'affichage
 */
void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp);

/**
 * @brief Affiche le contenue d'une matrice de chaines de caracteres
 * 
 * @param t_tabmots Structure contenant la matrices de chaines de caracteres
 * @param logfp     Sortie de l'affichage
 */
void affiche_t_mat_str_dyn(t_mat_str_dyn t_tabmots, FILE *logfp);

/**
 * @brief Affiche le contenue d'une matrice d'entiers
 * 
 * @param t_tab   Structure contenant la matrice d'entiers
 * @param logfp   Sortie de l'affichage
 */
void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp);

/**
 * @brief Affiche le contenue d'une matrice d'entiers
 * 
 * @param duels_mat   Matrice d'entiers
 * @param nbRows      Nombre de lignes
 * @param nbCols      Nombre de colonnes
 * @param logfp       Sortie de l'affichage
 */
void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp);

// CONVERT =================================================

/**
 * @brief Reduit la taille de la memoire d'une matrice de chaine de caracteres
 * 
 * @param mat   Matrice de chaine de caracteres
 */
void reduire_t_mat_str_dyn(t_mat_str_dyn *mat);

/**
 * @brief Copie une matrice de duels (str) dans une matrice de duels (int)
 * 
 * @param votes   Matrice de duels (str)
 * @param duels   Matrice de duels (int)
 */
void remplir_duels(t_mat_str_dyn * votes, t_mat_int_dyn * duels);

/**
 * @brief Converti un liste (balots) en matrice de duels
 * 
 * @param votes   Liste des votes (balots)
 * @param duels   Matrice de duels
 */
void convertir_en_duels(t_mat_str_dyn * votes, t_mat_int_dyn * duels);

#endif