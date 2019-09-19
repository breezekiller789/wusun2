#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

//input : array A, 0, n-1
mergesort(A, i, j){
    mergesort(A, i, i+((j-1)/2));
    mergesort(A, i+((j-1)/2)+1, j);

}

int main(int argc, char *argv[]){

    

    return 0;
}
