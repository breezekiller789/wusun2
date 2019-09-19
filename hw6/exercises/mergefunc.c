#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#define MaxLine 1024

int mycompare(const void *p, const void *q){
    /* char **x = (char **)p; */
    /* char **y = (char **)q; */
    int *x = (int *)p;
    int *y = (int *)q;
    return *x - *y;
}

int main(int argc, char *argv[]){
    
    int *arr, i, j;
    char words[100][100];
    arr = (int *)malloc(sizeof(int) * 1000);

    for(i=0; i<1000; i++){
        arr[i] = rand()%100000 + 1;
    }
    /* printf("%s\n", words[0]); */
    mergesort(arr, 1000, sizeof(int), mycompare);
    for(i=0; i<1000; i++){
        printf("%d\n", arr[i]);
    }
    

    return 0;
}
