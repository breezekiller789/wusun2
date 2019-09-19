#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define MaxInt 100

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int mycompare(const void *p, const void *q){
    int *x = (int *)p;
    int *y = (int *)q;
    return *x - *y;
}

int main(int argc, char *argv[]){

    int *array, value, i=0;
    char *line;

    array = (int *)malloc(sizeof(int) * MaxInt);
    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        value = atoi(line);
        *(array + i) = value;
        i++;
    }
    qsort(array, i, sizeof(int), mycompare);
    for(int k=0; k<i; k++)
        printf("%d\n", *(array + k));

    return 0;
}
