/**
 * @file file_read.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des fonctions de lectures
 *          et de verification de fichiers.
 * 
 * @copyright Licence MIT
 * 
 */

#ifndef FILE_READ
#define FILE_READ

#include <stdlib.h>
#include "../headers/squelette.h"

/**
 * @brief Lecture du fichier CSV (TSV).
 * 
 * Cette fonction lie le fichier CSV (TSV), remplie une matrice de chaines de caracteres et 
 * remplie une matrice de duels en faisant la/les conversion(s) necessaire(s).
 * 
 * @param csv       fichier CSV (TSV)
 * @param csv_type  type de fichier (balot (-i) ou duel (-d))
 * @param votes     matrice de chaines qui va accueillir le contenue du fichier
 * @param duels     matrice de duels contruite a partir des votes
 */
void read_csv(FILE * csv, char * csv_type, t_mat_str_dyn * votes, t_mat_int_dyn * duels);

/**
 * @brief Fonction de verification des fichiers
 * 
 * Cette fonction verifie que les fichiers passes en parametres ne sont pas NULL
 * 
 * @param csv 
 * @param logfp 
 */
void check_file(FILE * csv, FILE * logfp);

#endif