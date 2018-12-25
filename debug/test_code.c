#include <stdio.h>
#include <stdlib.h>

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

int main(void) {

    int ** k = creer_mat_int(4, 5);
    init_mat_int(k, 4, 5, 2);
    affiche_mat_int(k, 4, 5, stdout);

    return 0;
}