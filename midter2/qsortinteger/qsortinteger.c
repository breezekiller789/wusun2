#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

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

    int *arr, i=0;
    char *line;
    arr = (int *)malloc(sizeof(int) * MaxLine);
    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        arr[i] =atoi(line);
        printf("arr[%d] = %d\n", i, arr[i]);
        i++;
    }
    qsort(arr, i, sizeof(int), mycompare);
    for(int k=0; k<i; k++)
        printf("%d\n", arr[k]);

    return 0;
}
