/**
 * @file liste.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Definition des fonctions de liste.h
 * 
 * @copyright Licence MIT
 * 
 */

#include "../headers/liste.h"

void saisie_element(Elementliste *e) {
    return;
}

void copie_element(Elementliste *cible, Elementliste source) {
    cible->orig = source.orig;
    cible->dest = source.dest;
    cible->poids = source.poids;
}

void afficher_element(Elementliste e, FILE *fp) {
    return;
}

bool cmp_elements(Elementliste e1, Elementliste e2) {
    if (e1.orig == e2.orig &&
        e1.dest == e2.dest &&
        e1.poids == e2.poids)
    {
        return true;
    } else {
        return false;
    }
}

int nbEltList(liste lst) {
    return lst.nbElt;
}

void createList(liste *p) {
    p->nbElt = 0;
    p->Tete = 0;
}

void addFrontList(liste *p, Elementliste e) {
    p->Tete = (p->Tete-1+DIMMAX)%DIMMAX;
    copie_element(p->Tabliste + p->Tete, e);
    p->nbElt += 1;
}

void addTailList(liste *p, Elementliste e) {
    copie_element(p->Tabliste + (p->nbElt + p->Tete)%DIMMAX, e);
    p->nbElt += 1;
}

void delTailList(liste *p) {
    p->nbElt -= 1;
}

void delFrontList(liste *p) {
    p->Tete = (p->Tete+1)%DIMMAX;
    p->nbElt -= 1;
}

void headList(liste p, Elementliste *e) {
    copie_element(e, p.Tabliste[p.Tete]);
}

void tailList(liste p, Elementliste *e) {
    copie_element(e, p.Tabliste[(p.nbElt + p.Tete)%DIMMAX]);
}

bool emptyList(liste p) {
    if (p.nbElt == 0) {
        return true;
    } else {
        return false;
    }
}

bool fullList(liste p) {
    if (p.nbElt == DIMMAX) {
        return true;
    } else {
        return false;
    }
}

void dumpList(liste p, FILE *fp) {
    return;
}

void swapEltList(Elementliste *a, Elementliste *b) {
    return;
}

void bubbleSortList(liste *p) {
    return;
}

void pickEltList(liste l, Elementliste *e, int index) {
    e->orig = l.Tabliste[index].orig;
    e->dest = l.Tabliste[index].dest;
    e->poids = l.Tabliste[index].poids;
}

bool belongEltList(liste p, Elementliste e) {
    return false;
}
