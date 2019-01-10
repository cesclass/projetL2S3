/**
 * @file methodes.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief Definition des fonctions de methodes.h
 * 
 * @licence MIT
 * 
 */

#include "../headers/methodes.h"


void elimination(const t_mat_str_dyn votes, FILE * logfp) {
    int nb_candidats = votes.nbCols - votes.offset; 
    int restant = nb_candidats;
    int nb_votes = votes.nbRows-1;
    int rang, id;
    int res[votes.nbCols];
    int elim[nb_candidats];

    for(int e = 0; e < nb_candidats; e++) {
        elim[e] = e+votes.offset;
    }

    while(restant > 1) {
        init_tab_int(res, votes.nbCols, 0);
        for(int i = 1; i < votes.nbRows; i++) {
            rang = votes.nbCols+1;
            id = 0;

            for(int j = 0; j < restant; j++) {
                if (atoi(votes.tab[i][ elim[j] ]) < rang) {
                    rang = atoi(votes.tab[i][ elim[j] ]);
                    id = j+votes.offset;
                }
            }

            res[id] += 1;
        }

        int perdant = 0, score = nb_votes;
        for(int p = votes.offset; p < restant+votes.offset; p++) {
            if (res[p] < score) {
                score = res[p];
                perdant = p - votes.offset;
            }
        }

        elim[perdant] = elim[restant-1];
        restant -= 1;
    }

    int gagnant = elim[0], score = 0;
    for(int s = votes.offset; s <= votes.offset+restant; s++) {
        if(res[s] > score) {
            score = res[s];
        }
    }

    fprintf(logfp, "Mode de scrutin : vote alternatif, ");
    fprintf(logfp, "%d candidats, %d votants, vainqueur = %s\n",
        nb_candidats, nb_votes, votes.tab[0][gagnant]);

}


void uninominal1(const t_mat_str_dyn votes, FILE * logfp) {
    int vote_nul, rang, id, nb_nuls = 0;
    int res[votes.nbCols];
    init_tab_int(res, votes.nbCols, 0);

    for(int i = 1; i < votes.nbRows; i++) {
        vote_nul = 0;
        rang = votes.nbCols+1;
        id = 0;

        for(int j = votes.offset; j < votes.nbCols; j++) {
            if (atoi(votes.tab[i][j]) < rang) {
                rang = atoi(votes.tab[i][j]);
                id = j;
            }
        }

        for(int k = votes.offset; k < votes.nbCols; k++) {
            if(k != id && atoi(votes.tab[i][k]) == rang) {
                vote_nul = -1;
            }
        }

        if (vote_nul != -1) {
            res[id] += 1;
        } else {
            nb_nuls += 1;
        }
    }

    int gagnant = 0, score = 0; 
    int nb_candidats = votes.nbCols-votes.offset, nb_votes = votes.nbRows-1;

    for(int c = votes.offset; c < votes.nbCols; c++) {
        if (res[c] > score) {
            score = res[c];
            gagnant = c;
        }
    }

    fprintf(logfp, "Nombre de votes nuls pour uninominal : %d\n", nb_nuls);
    fprintf(logfp, "Mode de scrutin : uninominal à un tour, ");
    fprintf(logfp, "%d candidats, %d votants, vainqueur = %s, score = %.2f%s\n",
        nb_candidats, nb_votes, votes.tab[0][gagnant], (float) score/(nb_votes-nb_nuls)*100, "%");

}


void uninominal2(const t_mat_str_dyn votes, FILE * logfp) {
    int vote_nul, rang, id, nb_nuls = 0;
    int res[votes.nbCols];
    init_tab_int(res, votes.nbCols, 0);

    for(int i = 1; i < votes.nbRows; i++) {
        vote_nul = 0;
        rang = votes.nbCols+1;
        id = 0;

        for(int j = votes.offset; j < votes.nbCols; j++) {
            if (atoi(votes.tab[i][j]) < rang) {
                rang = atoi(votes.tab[i][j]);
                id = j;
            }
        }

        for(int k = votes.offset; k < votes.nbCols; k++) {
            if(k != id && atoi(votes.tab[i][k]) == rang) {
                vote_nul = -1;
            }
        }

        if (vote_nul != -1) {
            res[id] += 1;
        } else {
            nb_nuls += 1;
        }
    }

    int gagnant1 = 0, gagnant2 = 0, score1 = 0, score2 = 0; 
    int nb_candidats = votes.nbCols-votes.offset, nb_votes = votes.nbRows-1;

    for(int c = votes.offset; c < votes.nbCols; c++) {
        if (res[c] > score1) {
            score2 = score1;
            score1 = res[c];
            gagnant2 = gagnant1;
            gagnant1 = c;
        } else if (res[c] > score2) {
            score2 = res[c];
            gagnant2 = c;
        }
    }

    if((float)score1/(nb_votes-nb_nuls)*100 > 50.0) {
        fprintf(logfp, "Nombre de votes nuls pour uninominal : %d\n", nb_nuls);
        fprintf(logfp, "Mode de scrutin : uninominal à deux tours, tour 1, "); 
        fprintf(logfp, "%d candidats, %d votants, vainqueur = %s, score = %.2f%s)\n",
            nb_candidats, nb_votes, votes.tab[0][gagnant2], (float) score2/(nb_votes-nb_nuls)*100, "%");
        return;
    } else {
        fprintf(logfp, "Nombre de votes nuls pour uninominal : %d\n", nb_nuls);
        fprintf(logfp, "Mode de scrutin : uninominal à deux tours, tour 1, ");
        fprintf(logfp, "%d candidats, %d votants, vainqueur = %s, score = %.2f%s)\n",
            nb_candidats, nb_votes, votes.tab[0][gagnant1], (float) score1/(nb_votes-nb_nuls)*100, "%");
        fprintf(logfp, "Mode de scrutin : uninominal à deux tours, tour 1, "); 
        fprintf(logfp, "%d candidats, %d votants, vainqueur = %s, score = %.2f%s)\n",
            nb_candidats, nb_votes, votes.tab[0][gagnant2], (float) score2/(nb_votes-nb_nuls)*100, "%");
    }

    nb_nuls = 0;
    init_tab_int(res, votes.nbCols, 0);

    for(int i = 1; i < votes.nbRows; i++) {
        vote_nul = 0;
        rang = votes.nbCols+1;
        id = 0;

        for(int j = votes.offset; j < votes.nbCols; j++) {
            if ((j == gagnant1 || j == gagnant2) && 
                atoi(votes.tab[i][j]) < rang) 
            {
                rang = atoi(votes.tab[i][j]);
                id = j;
            }
        }

        for(int k = votes.offset; k < votes.nbCols; k++) {
            if(k != id && (k == gagnant1 || k == gagnant2) && 
                atoi(votes.tab[i][k]) == rang) 
            {
                vote_nul = -1;
            }
        }

        if (vote_nul != -1) {
            res[id] += 1;
        } else {
            nb_nuls += 1;
        }
    }

    int gagnant = 0, score = 0;

    for(int c = votes.offset; c < votes.nbCols; c++) {
        if (res[c] > score) {
            score = res[c];
            gagnant = c;
        }
    }

    fprintf(logfp, "Nombre de votes nuls pour uninominal : %d\n", nb_nuls);
    fprintf(logfp, "Mode de scrutin : uninominal à deux tours, tour 2, "); 
    fprintf(logfp, "2 candidats, %d votants, vainqueur = %s, score = %.2f%s)\n",
        nb_votes, votes.tab[0][gagnant], (float) score/(nb_votes-nb_nuls)*100, "%");
}


void condorcet_m(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp) {
    fprintf(logfp, "Condorcet minimax : indisponnible\n");
}


void condorcet_p(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp) {
    fprintf(logfp, "Condorcet paire : indisponnible\n");
}


void condorcet_s(const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp) {
    fprintf(logfp, "Condorcet shoulze : indisponnible\n");
}


void default_mtd(const char * csv_type, const t_mat_str_dyn votes, const t_mat_int_dyn duels, FILE * logfp) {
    if (strcmp(csv_type, "-i") == 0) {
        elimination(votes, logfp); 
        fprintf(logfp, "\n");
        uninominal1(votes, logfp); 
        fprintf(logfp, "\n");
        uninominal2(votes, logfp); 
        fprintf(logfp, "\n");
    }
    condorcet_m(votes, duels, logfp); 
    fprintf(logfp, "\n");
    condorcet_p(votes, duels, logfp); 
    fprintf(logfp, "\n");
    condorcet_s(votes, duels, logfp); 
    fprintf(logfp, "\n");
}
