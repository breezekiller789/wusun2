#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    char *line;
    FILE *fp;

    line = (char *)malloc(sizeof(char)*MaxLine);

    fp = fopen(argv[1], "r");

    while(fgets(line, MaxLine, fp) != NULL){
        printf("%s", line);
    }

    return 0;
}
