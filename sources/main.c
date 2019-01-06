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
#include "../headers/file_read.h"
#include "../headers/squelette.h"
#include "../headers/methodes.h"
#include "../headers/liste.h"
#include "../headers/arc.h"

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

    check_file(csv, logfp);

    t_mat_str_dyn votes;
    t_mat_int_dyn duels;

    read_csv(csv, argm.csv_type, &votes, &duels);

    // debug
    // affiche_t_mat_str_dyn(votes, stdout);
    // printf("\n");
    // affiche_t_mat_int_dyn(duels, stdout);

    fclose(csv);

    if (strcmp(argm.methode_type, "va") == 0) {
        elimination(votes, logfp);
    } else if (strcmp(argm.methode_type, "uni1") == 0) {
        uninominal1(votes, logfp);
    } else if (strcmp(argm.methode_type, "uni2") == 0) {
        uninominal2(votes, logfp);
    } else if (strcmp(argm.methode_type, "cm") == 0) {
        condorcet_m(votes, duels, logfp);
    } else if (strcmp(argm.methode_type, "cp") == 0) {
        condorcet_p(votes, duels, logfp);
    } else if (strcmp(argm.methode_type, "cs") == 0) {
        condorcet_s(votes, duels, logfp);
    } else {
        default_mtd(argm.csv_type, votes, duels, logfp);
    }

    FILE * fpy = fopen("./graph.py", "w");
    fprintf(fpy, "\n");
    fclose(fpy);
    fpy = fopen("./graph.py", "a");

    liste arcs;
    createList(&arcs);
    remplir_liste_arcs(duels, &arcs);
    graph_python(arcs, fpy);
    fclose(fpy);

    fprintf(logfp, "\n");
    if(logfp != stdout) {
        fclose(logfp);
    }
    
    free(votes.tab);
    free(duels.tab);

    return 0;
}
