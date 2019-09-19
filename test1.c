#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    int c = 0x80000000;
    printf("%d\n", c);

    c = abs(c);
    printf("%d\n", c);
    return 0;
}
