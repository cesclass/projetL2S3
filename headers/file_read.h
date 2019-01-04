/**
 * @file file_read.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#ifndef FILE_READ
#define FILE_READ

#include <stdlib.h>
#include "../headers/squelette.h"

void read_csv(FILE * csv, char * csv_type, t_mat_str_dyn * votes, t_mat_int_dyn * duels);

void check_file(FILE * csv, FILE * logfp);

#endif