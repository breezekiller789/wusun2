#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    long total=1;
    int i;
    for(i=1; i<=60; i++){
        total *= 2;
        printf("%ld\n", total);
    }
    printf("%ld\n", total);
    

    return 0;
}
