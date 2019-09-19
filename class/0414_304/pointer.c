#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    int *a, b=3;
    printf("before asign a = %p\n", a);
    a = &b;
    printf("after asign a = %p\n", a);
    printf("b = %p\n", &b);
    printf("*a = %d\n", *a);
    printf("*b = %d\n", b);

    return 0;
}
