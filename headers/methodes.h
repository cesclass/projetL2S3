/**
 * @file methodes.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#ifndef METHODES
#define METHODES

#include <stdio.h>
#include <stdlib.h>
#include "../headers/squelette.h"

/**
 * @brief 
 * 
 * @param votes 
 * @param logfp 
 */
void elimination(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief 
 * 
 * @param votes 
 * @param logfp 
 */
void uninominal1(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief 
 * 
 * @param votes 
 * @param logfp 
 */
void uninominal2(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief 
 * 
 * @param votes 
 * @param duels 
 * @param logfp 
 */
void condorcet_m(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief 
 * 
 * @param votes 
 * @param duels 
 * @param logfp 
 */
void condorcet_p(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief 
 * 
 * @param votes 
 * @param duels 
 * @param logfp 
 */
void condorcet_s(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief 
 * 
 * @param csv_type 
 * @param votes 
 * @param duels 
 * @param logfp 
 */
void default_mtd(const char * csv_type, const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

#endif
