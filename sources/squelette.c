/**
 * @file squelette.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief ...
 * 
 * @licence MIT
 * 
 */

#include "../headers/squelette.h"

int * creer_tab_int(int dim) {
    int * i;
    i = malloc(dim*sizeof(int));
    return i;
}

int ** creer_mat_int(int nbRows, int nbCols) {
    int ** i;
    i = malloc(nbRows*sizeof(int *));
    for(int c = 0; c < nbRows; c++) {
        i[c] = malloc(nbCols*sizeof(int));
    }
    return i;
}
