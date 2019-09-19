#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    float a, b, c;
    scanf("%f", &a);
    b = (float)(((a * 1000)+0.5) / 1000);
    printf("%.2f\n", b);

    return 0;
}
