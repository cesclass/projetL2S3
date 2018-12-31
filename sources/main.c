/**
 * @file main.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief ...
 * 
 * @licence MIT
 * 
 */

#include <stdio.h>
#include "../headers/argument_read.h"
#include "../headers/squelette.h"

int main(int argc, char **argv) {

    arguments argm;
    check_arguments(argc, argv, &argm);

    FILE * csv = fopen(argm.csv_path, "r");
    FILE * logfp;
    
    if (argm.logging) {
        logfp = fopen(argm.log_path, "a");
    } else {
        logfp = stdout;
    }

    t_mat_str_dyn votes;
    t_mat_int_dyn duels;

    if (strcmp(argm.csv_type, "-i") == 0) {
        read_csv(csv, argm.csv_type, &votes, &duels);
        if (!argm.method) {
            // appel methodes
        }
    } else {
        read_csv(csv, argm.csv_type, &votes, &duels);
        if (!argm.method) {
            // appel methodes
        }
    }

    if (strcmp(argm.methode_type, "va") == 0) {

    } else if (strcmp(argm.methode_type, "uni1") == 0) {

    } else if (strcmp(argm.methode_type, "uni2") == 0) {

    } else if (strcmp(argm.methode_type, "cm") == 0) {

    } else if (strcmp(argm.methode_type, "cp") == 0) {

    } else if (strcmp(argm.methode_type, "cs") == 0) {

    }

    return 0;
}
