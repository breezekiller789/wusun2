#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){
    char line[MaxLine];
    fgets(line, MaxLine, stdin);
    printf("%s\n", line);

    return 0;
}
