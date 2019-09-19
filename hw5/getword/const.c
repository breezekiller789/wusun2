#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    const int i=1, b = 1000;
    while(i > 0){
        i += b;
        printf("%d\n", i);
    }

    return 0;
}
