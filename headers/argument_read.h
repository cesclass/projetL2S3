/**
 * @file argument_read.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des fonctions de verification des arguments et 
 *      d'affichage du helper
 * 
 * @copyright Licence MIT
 * 
 */

#ifndef ARGUMENT_READ
#define ARGUMENT_READ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief structure representant les arguments traites
 * 
 */
typedef struct arguments {
    char *csv_type;
    char *csv_path;
    bool logging;
    char *log_path;
    bool method;
    char *methode_type;
} arguments;

/**
 * @brief Affichage d'un helper
 * 
 */
void help_arguments(void);

/**
 * @brief Initialisation d'une structure "arguments"
 * 
 * @param a     Structure arguments
 */
void init_arguments(arguments *a);

/**
 * @brief Affichage du contenue d'une structure "arguments"
 * 
 * @param a     Structure arguments
 */
void show_arguments(const arguments *a);

/**
 * @brief Lecture des arguemnts passes en parametre lors de l'execution
 * 
 * Cette fonction lie et traite les arguments avant de les ranges dans une structure.
 * Elle verifie ensuite la presence, l'absance et la coherence des arguments
 * 
 * @param argc  Nombre d'arguments passes
 * @param argv  Tableau d'arguments
 * @param argm  Structure contenant les arguments apres leur traitement
 */
void check_arguments(int argc, char **argv, arguments *argm);

#endif