/**
 * @file squelette.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// Definition de constantes pour la construction de "t_mat_str_dyn"
#define DEFAULT_ROWS 1000   // Nombre de lignes par defaut
#define DEFAULT_COLS 100    // Nombre de colonnes par defaut
#define DEFAULT_LEN 50      // Nombre de caractere par case par defaut

// Tableau d'entiers
typedef struct s_tab_dyn{
  int * tab;
  int dim;
} t_tab_int_dyn;

// Matrice d'entiers
typedef struct s_mat_dyn{
  int ** tab;
  int nbRows;
  int nbCols;
} t_mat_int_dyn;

// Matrices de chaines de caracteres
typedef struct s_mat_char_dyn{
  char *** tab;
  int nbRows;
  int nbCols;
  int offset; // donne le nombre de colonnes avant celles des candidats
} t_mat_str_dyn;

// struct arc pour les graphes
typedef struct s_arc_p{ // arc pondéré
  int orig;
  int dest;
  int poids;
} t_arc_p;

/**
 * @brief Cree un tableau d'entiers de taille "dim".
 * 
 * @param dim 
 * @return int* 
 */
int * creer_tab_int(int dim);

/**
 * @brief Cree une matrice de "nbRows" lignes et "nbCols" Colonnes.
 * 
 * @param nbRows 
 * @param nbCols 
 * @return int** 
 */
int ** creer_mat_int(int nbRows, int nbCols);

/**
 * @brief Initialise le tableau "tab" de taille "dim" avec la valeur "valeur".
 * 
 * @param tab 
 * @param dim 
 * @param valeur 
 */
void init_tab_int(int *tab, int dim, int valeur);

/**
 * @brief Initialise la matrice "mat" de "nbRows" lignes et "nbCols" Colonnes avec
 *        la valeur "valeur".
 * 
 * @param mat 
 * @param nbRows 
 * @param nbCols 
 * @param valeur 
 */
void init_mat_int(int **mat, int nbRows, int nbCols, int valeur);

/**
 * @brief Affiche le contenu du tableau "tab" de taille "dim" sur la sortie "logfp".
 * 
 * @param tab 
 * @param dim 
 * @param logfp 
 */
void affiche_tab_int(int *tab, int dim, FILE *logfp);

/**
 * @brief Affiche le contenu de la matrice "duels_mat" de "nbRows" lignes et
 *        "nbCols" colonnes sur la sortie "logfp".
 * 
 * @param tab 
 * @param dim 
 * @param logfp 
 */
void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp);

void creer_t_mat_int_dyn(t_mat_int_dyn *stTab, int nbRows, int nbCols);
void creer_t_tab_int_dyn(t_tab_int_dyn *stTab, int dim);
void creer_t_mat_str_dyn(t_mat_str_dyn * s_tabmots);
void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp);
void affiche_t_mat_str_dyn(t_mat_str_dyn t_tabmots, FILE *logfp);
void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp);
void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp);
