/**
 * @file arc.h
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#ifndef ARC
#define ARC

#include "../headers/liste.h"
#include "../headers/squelette.h"

void remplir_liste_arcs(const t_mat_int_dyn duels, liste * arcs);

void graph_python(const liste arcs, FILE * fpy);

#endif