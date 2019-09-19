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

    char **line, *bufline;
    int idx=0;
    line = (char **)malloc(sizeof(char *) * MaxLine);
    bufline = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(bufline, MaxLine, stdin) != NULL){
        rmnewline(bufline);
        *(line+idx) = (char *)malloc(sizeof(char) * strlen(bufline) + 1);
        strcpy(*(line+idx), bufline);
        idx++;
    }
    int i=0;
    while(i < idx){
        printf("%s\n", *line++);
        i++;
    }

    return 0;
}
