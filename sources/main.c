/**
 * @file main.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief (Main) Fichier principal
 * 
 * @copyright Licence MIT
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

    // Gestion des arguments
    arguments argm;
    check_arguments(argc, argv, &argm);

    // Gestion des fichiers CSV (TSV) et du Log
    FILE * csv = fopen(argm.csv_path, "r");
    FILE * logfp;
    
    if (argm.logging) {
        logfp = fopen(argm.log_path, "a");
    } else {
        logfp = stdout;
    }

    check_file(csv, logfp);

    // Lecture du CSV et remplissage des matrices
    t_mat_str_dyn votes;
    t_mat_int_dyn duels;

    read_csv(csv, argm.csv_type, &votes, &duels);
    fclose(csv);

    // Affichage des matrices
    affiche_t_mat_str_dyn(votes, logfp);
    fprintf(logfp, "\n");
    affiche_t_mat_int_dyn(duels, logfp);
    fprintf(logfp, "\n");

    // Appel de fonction pour appliquer la/les methodes de scrutins
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

    // Generation des arcs et config du fichier python pour les graphes
    FILE * fpy = fopen("./graph.py", "w");
    fprintf(fpy, "\n");
    fclose(fpy);
    fpy = fopen("./graph.py", "a");

    liste arcs;
    createList(&arcs);
    remplir_liste_arcs(duels, &arcs);
    graph_python(arcs, fpy);
    fclose(fpy);

    // Fermeture du Log, Free, return et FIN
    fprintf(logfp, "\n");
    if(logfp != stdout) {
        fclose(logfp);
    }
    
    free(votes.tab);
    free(duels.tab);

    return 0;
}
