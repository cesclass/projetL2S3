/**
 * @file argument_read.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief ...
 * 
 * @licence MIT
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Structure contenant les arguments et 
 *      un boolean attestant de leur presence ou non
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
 * @brief 
 * 
 */
void help_arguments(void);

/**
 * @brief 
 * 
 * @param a 
 */
void init_arguments(arguments *a);

/**
 * @brief 
 * 
 * @param a 
 */
void show_arguments(const arguments *a);

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @param argm 
 */
void check_arguments(int argc, char **argv, arguments *argm);
