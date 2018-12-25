/**
 * @file squelette.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Definitino des fonctions de squelette.h
 * 
 * @licence MIT
 * 
 */

#include "../headers/squelette.h"

// INT =====================================================

int * creer_tab_int(int dim) {
    int * i;
    i = malloc(dim*sizeof(int));
    return i;
}

int ** creer_mat_int(int nbRows, int nbCols) {
    int ** i;
    i = malloc(nbRows*sizeof(int *));
    for(int c = 0; c < nbRows; c++) {
        i[c] = creer_tab_int(nbCols);
    }
    return i;
}

void init_tab_int(int *tab, int dim, int valeur) {
    for(int c = 0; c < dim; c++) {
        tab[c] = valeur;
    }
}

void init_mat_int(int **mat, int nbRows, int nbCols, int valeur) {
    for(int i = 0; i < nbRows; i++) {
        for(int j = 0; j < nbCols; j++) {
            mat[i][j] = valeur;
        }
    }
}

void affiche_tab_int(int *tab, int dim, FILE *logfp) {
    for(int c = 0; c < dim; c++) {
        fprintf(logfp, "%d\t", tab[c]);
    }
    fprintf(logfp, "\n");
}

void affiche_mat_int(int **duels_mat, int nbRows, int nbCols, FILE *logfp) {
    for(int c = 0; c < nbRows; c++) {
        affiche_tab_int(duels_mat[c], nbCols, logfp);
    }
}

// STRUCT ==================================================

void creer_t_tab_int_dyn(t_tab_int_dyn *stTab, int dim);
void creer_t_mat_int_dyn(t_mat_int_dyn *stTab, int nbRows, int nbCols);
void creer_t_mat_char_dyn(t_mat_char_star_dyn * s_tabmots);

void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp);
void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp);
void affiche_t_mat_char_star_dyn(t_mat_char_star_dyn t_tabmots, FILE *logfp);
