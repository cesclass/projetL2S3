/**
 * @file file_read.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#include "../headers/file_read.h"

void read_csv(FILE * csv, char * csv_type, t_mat_str_dyn * votes, t_mat_int_dyn * duels) {
    creer_t_mat_str_dyn(votes);

    int i = 0, j = 0, k = 0;
    char ch = fgetc(csv);
    
    while(!feof(csv)) {
        if (ch == '\t') {
            j += 1;
            k = 0;
        } else if (ch == '\n') {
            i += 1;
            j = 0;
            k = 0;
        } else {
            votes->tab[i][j][k] = ch;
            votes->nbRows = MAX(votes->nbRows, i+1);
            votes->nbCols = MAX(votes->nbCols, j+1);
            k += 1;
        }
        ch = fgetc(csv);
    }

    reduire_t_mat_str_dyn(votes);
    
    if (strcmp(csv_type, "-i") == 0) {
        votes->offset = 3;
        creer_t_mat_int_dyn(duels, votes->nbCols-votes->offset, votes->nbCols-votes->offset);
        convertir_en_duels(votes, duels);
    } else {
        votes->offset = 0;
        creer_t_mat_int_dyn(duels, votes->nbCols, votes->nbCols);
        remplir_duels(votes, duels);
    }
    
}

check_file(FILE * csv, FILE * logfp) {
    if(csv == NULL) {
        fprintf(stderr, "ERR CSV : Le fichier csv ne peut etre ouvert.\n");
        exit(1);
    }
    if(logfp == NULL) {
        fprintf(stderr, "ERR LOG : Le fhicier de log ne peut etre ouvert.\n");
        exit(1);
    }
}