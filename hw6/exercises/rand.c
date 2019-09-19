#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#define MaxLine 1024

int main(int argc, char *argv[]){
    int *arr;
    arr = (int *)malloc(sizeof(int) * 100);
    for(int i=0; i<100; i++){
        arr[i] = rand()%10000+1;
        printf("%d\n", arr[i]);
    }

    

    return 0;
}
