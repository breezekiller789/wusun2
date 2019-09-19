#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    int a = 3;
    int *b;
    b = &a;
    printf("a is = %p\n", &a);
    printf("b is = %p\n", b);
    printf("%d\n", *b);


    return 0;
}
