#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

char *mygetchar(char *line, char *word){
    int len = strlen(line);
    int val;
    char *ptr = line;
    val = (int)*ptr;
    printf("%d\n", val);
    return NULL;
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    char *line;
    char word[MaxLine];
    char *ptr;
    line = (char *)malloc(sizeof(char) * MaxLine);
    fgets(line, MaxLine, stdin);
    rmnewline(line);
    mygetchar(line, word);
    return 0;
}
