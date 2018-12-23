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

int main(int argc, char **argv) {

    arguments argm;
    check_arguments(argc, argv, &argm);

    if (strcmp(argm.csv_type, "-i") == 0) {
        // read_csv_i()
        if (!argm.method) {
            return 10;
            // appel methodes
        }
        return 11;
    } else {
        // read_csv_d()
        if (!argm.method) {
            return 20;
            // appel methodes
        }
        return 21;
    }

    /*
     * appel d'une fonction ou switch case ou if elif else
     * décision selon la simplicité et la taille de l'implémentation
     */

    return 0;
}
