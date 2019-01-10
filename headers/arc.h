/**
 * @file arc.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Fichier de declaration des fonctions necessaires a la construction d'un graph
 * 
 * @copyright Licence MIT
 * 
 */

#ifndef ARC
#define ARC

#include "../headers/liste.h"
#include "../headers/squelette.h"

/**
 * @brief Remplie la liste des arcs avec la matrice de duels
 * 
 * @param duels     Matrice de duels
 * @param arcs      Liste des arcs
 */
void remplir_liste_arcs(const t_mat_int_dyn duels, liste * arcs);

/**
 * @brief Redige le fichier python servant a generer le graphe
 * 
 * @param arcs  Liste des arcs
 * @param fpy   Fichier python
 */
void graph_python(const liste arcs, FILE * fpy);

#endif