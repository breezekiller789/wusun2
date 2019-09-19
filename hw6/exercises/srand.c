#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define MaxLine 1024

int main(int argc, char *argv[]){
    int c;
    int array[100];
    char a;
    srand(time(NULL));
    printf("%c\n", 'a' + (rand() % 26));
    /* for(int i=0; i<100; i++){ */
    /*     array[i] = (rand() % 100000) + 1; */
    /*     printf("%d\n", array[i]); */
    /* } */
    

    return 0;
}
