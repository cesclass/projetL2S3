/**
 * @file arc.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief 
 * 
 * @licence MIT
 * 
 */

#include "../headers/arc.h"

void remplir_liste_arcs(const t_mat_int_dyn duels, liste * arcs) {
    Elementliste arc;
    for(int i = 0; i < duels.nbRows; i++) {
        for(int j = 0; j < duels.nbCols; j++) {
            if(duels.tab[i][j] > duels.tab[j][i]) {
                arc.orig = i;
                arc.dest = j;
                arc.poids = duels.tab[i][j];
                if (!fullList(*arcs)) {
                    addTailList(arcs, arc);
                }
            }
        }
    }
}

void graph_python(const liste arcs, FILE * fpy) {
fprintf(fpy, "import networkx as nx\n");
fprintf(fpy, "from networkx.algorithms import tournament\n");
fprintf(fpy, "import numpy as np\n");
fprintf(fpy, "import matplotlib.pyplot as plt\n");
fprintf(fpy, "import pylab\n");
fprintf(fpy, "\n");
fprintf(fpy, "G = nx.DiGraph()\n");
fprintf(fpy, "\n");

Elementliste arc;
for(int i = 0; i < arcs.nbElt; i++) {
    pickEltList(arcs, &arc, i);
    fprintf(fpy, "G.add_edges_from([(%d,%d)], weight=%d)\n",
        arc.orig, arc.dest, arc.poids);
}

fprintf(fpy, "\n");
fprintf(fpy, "print(tournament.is_tournament(G))\n");
fprintf(fpy, "\n");
fprintf(fpy, "edge_labels=dict([((u,v,),d['weight'])\n");
fprintf(fpy, "                 for u,v,d in G.edges(data=True)])\n");
fprintf(fpy, "\n");
fprintf(fpy, "pos=nx.circular_layout(G)\n");
fprintf(fpy, "nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)\n");
fprintf(fpy, "nx.draw_networkx(G,pos, node_size=200)\n");
fprintf(fpy, "pylab.show()\n");
}