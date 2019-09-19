#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    int i=2;
    for(int j=0; j<14; j++)
        i *= 2;
    printf("%d\n", i);

    return 0;
}
