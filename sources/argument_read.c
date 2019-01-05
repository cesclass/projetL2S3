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
    fprintf(stderr, "+-----------------------------------------------+\n");
    fprintf(stderr, "|  REV_PARTY Helper                             |\n");
    fprintf(stderr, "+-----------------------------------------------+\n");
    fprintf(stderr, "|  Ecriture des arguments :                     |\n");
    fprintf(stderr, "|                                               |\n");
    fprintf(stderr, "|  -i | -d <file.csv> (obligatoire)             |\n");
    fprintf(stderr, "|  i : le fichier csv contient la liste         |\n");
    fprintf(stderr, "|      des votes avec l'id du votant            |\n");
    fprintf(stderr, "|  d : le fichier csv contient la matrice       |\n");
    fprintf(stderr, "|      des duels                                |\n");
    fprintf(stderr, "|                                               |\n");
    fprintf(stderr, "|  -l <log_file.txt> (optionnel)                |\n");
    fprintf(stderr, "|  l : enregistre les logs (etapes de calculs)  |\n");
    fprintf(stderr, "|      dans le fichier specifie                 |\n");
    fprintf(stderr, "|                                               |\n");
    fprintf(stderr, "|  -m <methode> (optionnel)                     |\n");
    fprintf(stderr, "|  m : specifie la methode de scrutin a employe |\n");
    fprintf(stderr, "|  <methode> :                 (compatibilite)  |\n");
    fprintf(stderr, "|    va : elemination successive          (-i)  |\n");
    fprintf(stderr, "|    uni1 : uninominal a 1 tour           (-i)  |\n");
    fprintf(stderr, "|    uni2 : uninominal a 2 tours          (-i)  |\n");
    fprintf(stderr, "|    cm : condorcet minimax          (-i | -d)  |\n");
    fprintf(stderr, "|    cs : condorcet schulze          (-i | -d)  |\n");
    fprintf(stderr, "|    cp : condorcet paire            (-i | -d)  |\n");
    fprintf(stderr, "|                                               |\n");
    fprintf(stderr, "+-----------------------------------------------+\n");
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
                fprintf(stderr, "ERR : <%s> <%s>\n", argv[c], argm->csv_type);
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
                fprintf(stderr, "ERR : <%s> <%d>\n", argv[c], argm->logging);
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
                fprintf(stderr, "ERR : <%s> <%d>\n", argv[c], argm->method);
                help_arguments();
                exit(EXIT_FAILURE);
            }

        } else {
            fprintf(stderr, "ERR : Unknow <%s>\n", argv[c]);
            help_arguments();
            exit(EXIT_FAILURE);
        }

    } // for argc

    if (strcmp(argm->csv_path, "\0") == 0 || (
        argm->logging && strcmp(argm->log_path, "\0") == 0) || (
        argm->method && strcmp(argm->methode_type, "\0") == 0 ))
    {
        fprintf(stderr, "ERR : Arguments manquants\n");
        help_arguments();
        exit(EXIT_FAILURE);
    }

    if (argm->method) {
        if ((strcmp(argm->methode_type, "cm") != 0 &&
            strcmp(argm->methode_type, "cp") != 0 &&
            strcmp(argm->methode_type, "cs") != 0 ) &&
            (strcmp(argm->csv_type, "-i") == 0 &&
            strcmp(argm->methode_type, "va") != 0 &&
            strcmp(argm->methode_type, "uni1") != 0 &&
            strcmp(argm->methode_type, "uni2") != 0 ))
        {   
            fprintf(stderr, "ERR : Methode incorrecte <%s>\n", argm->methode_type);
            help_arguments();
            exit(EXIT_FAILURE);
        }
    }

    // debug
    // show_arguments(argm);
}