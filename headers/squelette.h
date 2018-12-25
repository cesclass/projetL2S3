
#include <stdio.h>
#include <stdlib.h>

// mettre des choses avant
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//  struct pour encapsuler des tableaux dynamiques d'entiers avec la dimension.
typedef struct s_tab_dyn{
  int * tab;
  int dim;
} t_tab_int_dyn;

typedef struct s_mat_dyn{
  int ** tab;
  int nbRows;
  int nbCol;
} t_mat_int_dyn;

//  struct idem avec des chaînes de cractères
typedef struct s_mat_char_dyn{
  char *** tab;
  int nbRows;
  int nbCol;
  int offset; // donne le nombre de colonnes avant celles des candidats
} t_mat_char_star_dyn;

//  struct arc pour les graphes
typedef struct s_arc_p{ //  arc pondéré
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
void creer_t_mat_char_dyn(t_mat_char_star_dyn * s_tabmots);
void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp);
void affiche_t_mat_char_star_dyn(t_mat_char_star_dyn t_tabmots, FILE *logfp);
void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp);
void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp);

// mettre des choses après
