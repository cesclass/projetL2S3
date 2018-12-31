/**
 * @file argument_read.c
 * @author Cyril E (cyril.esclassan@univ-tlse3.fr)
 * 
 * @brief ...
 * 
 * @licence MIT
 * 
 */

#include "../headers/argument_read.h"

void help_arguments(void) {
    printf("+-----------------------------------------------+\n");
    printf("|  REV_PARTY Helper                             |\n");
    printf("+-----------------------------------------------+\n");
    printf("|  Ecriture des arguments :                     |\n");
    printf("|                                               |\n");
    printf("|  -i | -d <file.csv> (obligatoire)             |\n");
    printf("|  i : le fichier csv contient la liste         |\n");
    printf("|      des votes avec l'id du votant            |\n");
    printf("|  d : le fichier csv contient la matrice       |\n");
    printf("|      des duels                                |\n");
    printf("|                                               |\n");
    printf("|  -l <log_file.txt> (optionnel)                |\n");
    printf("|  l : enregistre les logs (etapes de calculs)  |\n");
    printf("|      dans le fichier specifie                 |\n");
    printf("|                                               |\n");
    printf("|  -m <methode> (optionnel)                     |\n");
    printf("|  m : specifie la methode de scrutin a employe |\n");
    printf("|  <methode> :                 (compatibilite)  |\n");
    printf("|    va : variante (?)                    (-i)  |\n");
    printf("|    uni1 : uninominal a 1 tour           (-i)  |\n");
    printf("|    uni2 : uninominal a 2 tours          (-i)  |\n");
    printf("|    cm : condorcet minimax          (-i | -d)  |\n");
    printf("|    cs : condorcet schulze          (-i | -d)  |\n");
    printf("|    cp : condorcet paire            (-i | -d)  |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");
}

void init_arguments(arguments *a) {
    a->csv_type = "\0";
    a->csv_path = "\0";
    a->logging = false;
    a->log_path = "\0";
    a->method = false;
    a->methode_type = "\0";
}

void show_arguments(const arguments *a) {
    printf("csv_type : %s\n", a->csv_type);
    printf("csv_path : %s\n", a->csv_path);
    printf("logging : %d\n", a->logging);
    printf("log_path : %s\n", a->log_path);
    printf("method : %d\n", a->method);
    printf("methode_type : %s\n", a->methode_type);
    printf("\n");
}

void check_arguments(int argc, char **argv, arguments *argm) {
    // debug
    // for(int i = 0 ; i < argc ; i++) {printf("argv[%d] : %s\n", i, argv[i]);}
     

    init_arguments(argm);
    printf("\n");

    // debug
    // show_arguments(argm);

    for(int c = 1 ; c < argc ; c++) {

        if (strcmp(argv[c], "-i") == 0 || strcmp(argv[c], "-d") == 0) {
            if (strcmp(argm->csv_type, "\0") == 0) {
                argm->csv_type = argv[c];
                c++;
                if (c < argc) {
                    argm->csv_path = argv[c];
                }
            } else {
                printf("ERR : <%s> <%s>\n", argv[c], argm->csv_type);
                help_arguments();
                exit(EXIT_FAILURE);
            }

        } else if (strcmp(argv[c], "-l") == 0) {
            if (!argm->logging) {
                argm->logging = true;
                c++;
                if(c < argc) {
                    argm->log_path = argv[c];
                }
            } else {
                printf("ERR : <%s> <%d>\n", argv[c], argm->logging);
                help_arguments();
                exit(EXIT_FAILURE);
            }

        } else if (strcmp(argv[c], "-m") == 0) {
            if(!argm->method) {
                argm->method = true;
                c++;
                if (c < argc) {
                    argm->methode_type = argv[c];
                }

            } else {
                printf("ERR : <%s> <%d>\n", argv[c], argm->method);
                help_arguments();
                exit(EXIT_FAILURE);
            }

        } else {
            printf("ERR : Unknow <%s>\n", argv[c]);
            help_arguments();
            exit(EXIT_FAILURE);
        }

    } // for argc

    if (strcmp(argm->csv_path, "\0") == 0 || (
        argm->logging && strcmp(argm->log_path, "\0") == 0) || (
        argm->method && strcmp(argm->methode_type, "\0") == 0 ))
    {
        printf("ERR-1\n");
        help_arguments();
        exit(EXIT_FAILURE);
    }

    if (argm->method) {
        if ((strcmp(argm->methode_type, "cm") != 0 &&
            strcmp(argm->methode_type, "cp") != 0 &&
            strcmp(argm->methode_type, "cs") != 0 ) || 
            (strcmp(argm->csv_type, "-i") == 0 &&
            strcmp(argm->methode_type, "va") != 0 &&
            strcmp(argm->methode_type, "uni1") != 0 &&
            strcmp(argm->methode_type, "uni2") != 0 ))
        {   
            printf("ERR-2\n");
            help_arguments();
            exit(EXIT_FAILURE);
        }
    }

    // debug
    // show_arguments(argm);
}