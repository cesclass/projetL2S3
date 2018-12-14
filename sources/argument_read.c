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
    printf("Utilisation des arguments :\n");
    printf("-i | -d file.csv\n");
    printf("-l log_file.txt\n");
    printf("-m method\n");
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
    // debug //
    for(int i = 0 ; i < argc ; i++) {printf("argv[%d] : %s\n", i, argv[i]);}

    init_arguments(argm);
    printf("\n");
    show_arguments(argm);

    for(int c = 1 ; c < argc ; c++) {

        if (strcmp(argv[c], "-i") == 0 || strcmp(argv[c], "-d") == 0) {
            if (strcmp(argm->csv_type, "\0") == 0) {
                argm->csv_type = argv[c];
                c++;
                if (c < argc) {
                    argm->csv_path = argv[c];
                }
            } else {
                help_arguments();
                printf("ERR : <%s> <%s>\n", argv[c], argm->csv_type);
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
                help_arguments();
                printf("ERR : <%s> <%d>\n", argv[c], argm->logging);
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
                help_arguments();
                printf("ERR : <%s> <%d>\n", argv[c], argm->method);
                exit(EXIT_FAILURE);
            }

        } else {
            help_arguments();
            printf("ERR : Unknow <%s>\n", argv[c]);
            exit(EXIT_FAILURE);
        }

    } // for argc

    if (strcmp(argm->csv_path, "\0") == 0 || (
        argm->logging && strcmp(argm->log_path, "\0") == 0) || (
        argm->method && strcmp(argm->methode_type, "\0") == 0 ))
    {
        help_arguments();
        printf("ERR\n");
        exit(EXIT_FAILURE);
    }

    if (argm->method) {
        if ((strcmp(argm->methode_type, "cm") != 0 &&
            strcmp(argm->methode_type, "cp") != 0 &&
            strcmp(argm->methode_type, "cs") != 0 ) || 
            (strcmp(argm->csv_type, "-i") &&
            strcmp(argm->methode_type, "va") != 0 &&
            strcmp(argm->methode_type, "uni1") != 0 &&
            strcmp(argm->methode_type, "uni2") != 0 ))
        {
            help_arguments();
            printf("ERR\n");
            exit(EXIT_FAILURE);
        }
    }

    show_arguments(argm);
}