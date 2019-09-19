#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    /* int c = 0x80000000; */
    int c =  -2147483648;
    printf("Before abs() = %d\n", c);

    c = abs(c);
    printf("After abs() = %d\n", c);

    return 0;
}
