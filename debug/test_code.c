#include <stdio.h>

int main(int argc, char *argv[]) {

    char *c;
    c = "\0";

    printf(" c : %d\n", c);
    printf(" c : %s\n", c);
    printf("&c : %d\n", &c);
    printf("*c : %s\n", (*c));
    printf("*c : %d\n", (*c));

    if ( c == "\0" ) {
        printf("c == \\0");
    } else {
        printf("c != \\0");
    }
    
    printf("\n");

    return 0;
}