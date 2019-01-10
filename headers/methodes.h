/**
 * @file methodes.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des fonctions permettant d'appliquer
 *      les differentes methodes de scrutins
 * 
 * @copyright Licence MIT
 * 
 */

#ifndef METHODES
#define METHODES

#include <stdio.h>
#include <stdlib.h>
#include "../headers/squelette.h"


/**
 * @brief Mode de scrutin : Elimination successive
 * 
 * @param votes     Liste des votes (balots)
 * @param logfp     Sortie de l'affichage
 */
void elimination(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief Mode de scrutin : Uninominal a 1 tour
 * 
 * @param votes     Liste des votes (balots)
 * @param logfp     Sortie de l'affichage
 */
void uninominal1(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief Mode de scrutin : Uninominal a 2 tours
 * 
 * @param votes     Liste des votes (balots)
 * @param logfp     Sortie de l'affichage
 */
void uninominal2(const t_mat_str_dyn votes, FILE * logfp);

/**
 * @brief Mode de scrutin : Condorcet Minimax
 * 
 * @param votes     Liste des votes (candidats + duels)
 * @param duels     Matrice de duels
 * @param logfp     Sortie de l'affichage
 */
void condorcet_m(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief Mode de scrutin : Condorcet Paires
 * 
 * @param votes     Liste des votes (candidats + duels)
 * @param duels     Matrice de duels
 * @param logfp     Sortie de l'affichage
 */
void condorcet_p(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief Mode de scrutin : Condorcet Shulze
 * 
 * @param votes     Liste des votes (candidats + duels)
 * @param duels     Matrice de duels
 * @param logfp     Sortie de l'affichage
 */
void condorcet_s(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

/**
 * @brief Appel des fonctions (modes de scrutin) compatibles en fonction du type de fichier.
 * 
 * @param csv_type  type de fichier (balot (-i) ou duel (-d))
 * @param votes     Liste des votes (balots) OU (candidats + duels)
 * @param duels     Matrice de duels
 * @param logfp     Sortie de l'affichage
 */
void default_mtd(const char * csv_type, const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp);

#endif
