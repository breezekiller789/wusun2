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

int main(int argc, char *argv[]){

    char *line, *ptr, *qtr, *copyline, *src, *trg;

    line = (char *)malloc(sizeof(char) * MaxLine);

    src = argv[1];
    trg = argv[2];

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        if((ptr = qtr = strstr(line, src))){
            qtr += strlen(src);
            copyline = (char *)malloc(sizeof(char) * strlen(line) + 1);
            strcpy(copyline, qtr);
            *ptr = '\0';
            strcat(line, trg);
            strcat(line, copyline);
        }
        printf("%s\n", line);
    }

    return 0;
}
