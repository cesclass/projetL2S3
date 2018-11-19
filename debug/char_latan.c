#include <stdio.h>

int main(int argc, char *argv[]) {

    char b;
    b = (char) 0;
    printf("&b : %d\n", &b);
    printf("*b : %s\n", b);
    printf("*b : %d\n", b);

    char *c;
    (*c) = (char) 0;
    printf("&c : %d\n", c);
    printf("*c : %s\n", (*c));
    printf("*c : %d\n", (*c));
    
    printf("\n");
    return 0;
}