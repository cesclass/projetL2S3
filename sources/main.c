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

int main(int argc, char **argv) {

    arguments argm;
    check_arguments(argc, argv, &argm);


    return 0;
}
