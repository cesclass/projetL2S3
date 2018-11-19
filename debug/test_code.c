#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct arguments {
    char *csv_type;
    char *csv_path;
    bool logging;
    char *log_path;
    bool method;
    char *methode_type;
} arguments;

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

int main(int argc, char *argv[]) {

    for(int i = 0 ; i < argc ; i++) {printf("argv[%d] : %s\n", i, argv[i]);}

    arguments argm;
    init_arguments(&argm);
    printf("\n");
    show_arguments(&argm);

    for(int c = 1 ; c < argc ; c++) {

        if (strcmp(argv[c], "-i") == 0 || strcmp(argv[c], "-d") == 0) {
            if (strcmp(argm.csv_type, "\0") == 0) {
                argm.csv_type = argv[c];
                c++;
                argm.csv_path = argv[c];
            } else {
                continue;
                // ERREUR
            }

        } else if (strcmp(argv[c], "-l") == 0) {
            if (!argm.logging) {
                argm.logging = true;
                c++;
                argm.log_path = argv[c];
            } else {
                continue;
                // ERREUR
            }

        } else if (strcmp(argv[c], "-m") == 0) {
            if(!argm.method) {
                argm.method = true;
                c++;
                argm.methode_type = argv[c];
            } else {
                continue;
                // ERREUR
            }

        } else {
            continue;
            // ERREUR
        }

    }

    show_arguments(&argm);

    return 0;
}
