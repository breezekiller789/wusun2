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

int main(int argc, char **argv){
    

    char *line, *ptr, *qtr, *copyline;

    line = (char *)malloc(sizeof(char) * MaxLine);
    copyline = (char *)malloc(sizeof(char) * MaxLine);


    ptr = argv[1];
    qtr = copyline;
    while(*ptr != '\0')
        *qtr++ = *ptr++;
    /* printf("%s\n", copyline); */


    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(*ptr != '\0'){
            *qtr++ = *ptr++;
        }

    }
    printf("%s\n", copyline);

    return 0;
}
