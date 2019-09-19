#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){
    char line[] = "-9";
    int ret = atoi(line);
    printf("%d\n", ret);

    return 0;
}
