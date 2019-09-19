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

    char **line, *bufline, *ptr, *qtr;
    line = (char **)malloc(sizeof(char *) * MaxLine);
    /* *line = (char *)malloc(sizeof(char) *MaxLine); */
    /* strcpy(*line, "apple"); */
    /* printf("%s\n", *line); */
    /* ++*line; */
    /* *line = (char *)malloc(sizeof(char) *MaxLine); */
    /* strcpy(*line, "banana"); */
    /* printf("%s\n", *line); */

    while(fgets(bufline, MaxLine, stdin) != NULL){
        rmnewline(bufline);
        *line = (char *)malloc(sizeof(char) * strlen(bufline) + 1);
        ptr = *line;
        strcpy(ptr, bufline);
        ptr += strlen(bufline);
    }


    return 0;
}
