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

void creer_t_tab_int_dyn(t_tab_int_dyn *stTab, int dim) {
    stTab->dim = dim;
    stTab->tab = creer_tab_int(dim);
}

void creer_t_mat_int_dyn(t_mat_int_dyn *stTab, int nbRows, int nbCols) {
    stTab->nbRows = nbRows;
    stTab->nbCols = nbCols;
    stTab->tab = creer_mat_int(nbRows, nbCols);
}

void creer_t_mat_str_dyn(t_mat_str_dyn * s_tabmots) {
    s_tabmots->nbRows = 0;
    s_tabmots->nbCols = 0;

    s_tabmots->tab = malloc(DEFAULT_ROWS*sizeof(char **));
    for(int i = 0; i < DEFAULT_ROWS; i++) {
        s_tabmots->tab[i] = malloc(DEFAULT_COLS*sizeof(char *));
        for(int j = 0; j < DEFAULT_COLS; j++) {
            s_tabmots->tab[i][j] = malloc(DEFAULT_LEN*sizeof(char));
        }
    }
}

void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp) {
    affiche_tab_int(t_tab.tab, t_tab.dim, logfp);
}

void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp) {
    affiche_mat_int(t_tab.tab, t_tab.nbRows, t_tab.nbCols, logfp);
}

void affiche_t_mat_str_dyn(t_mat_str_dyn t_tabmots, FILE *logfp) {
    for(int i = 0; i < t_tabmots.nbRows; i++) {
        for(int j = 0; j < t_tabmots.nbCols; j++) {
            fprintf(logfp, "%s\t", t_tabmots.tab[i][j]);
        }
        fprintf(logfp, "\n");
    }
}

// CONVERT =================================================

void reduire_t_mat_str_dyn(t_mat_str_dyn *mat) {
    mat->tab = realloc(mat->tab, mat->nbRows*sizeof(char **));
    for(int i = 0; i < mat->nbRows; i++) {
        mat->tab[i] = realloc(mat->tab[i], mat->nbCols*sizeof(char *));
    }
}

void remplir_duels(t_mat_str_dyn * votes, t_mat_int_dyn * duels) {
    for(int i = 0; i < duels->nbRows; i++) {
        for(int j = 0; j < duels->nbCols; j++) {
            duels->tab[i][j] = atoi(votes->tab[i+1][j]);
        }
    }
}

void convertir_en_duels(t_mat_str_dyn * votes, t_mat_int_dyn * duels) {
    init_mat_int(duels->tab, duels->nbRows, duels->nbCols, 0);
    for(int i = 1; i < votes->nbRows; i++) {
        for(int j = votes->offset; j < votes->nbCols; j++) {
            for(int k = votes->offset; k < votes->nbCols; k++) {
                if(j != k && atoi(votes->tab[i][j]) < atoi(votes->tab[i][k])) {
                    duels->tab[j-votes->offset][k-votes->offset] += 1;
                }
            }
        }
    }
}

