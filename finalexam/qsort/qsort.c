#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024

int option = -1;

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int mycompare(const void *p, const void *q){
    char **x = (char **)p;
    char **y = (char **)q;
    if(option == 1){
        return strcmp(*y, *x);
    }
    return strcmp(*x, *y);
}

int main(int argc, char *argv[]){

    char line[MaxLine], *words[MaxLine];
    int cnt=0;
    if(argc == 2){
        option = 1;
    }

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        words[cnt] = (char *)malloc(sizeof(char) * strlen(line) + 1);
        strcpy(words[cnt], line);
        /* printf("%s\n", words[cnt]); */
        cnt++;
    }
    qsort(words, cnt, sizeof(char *), mycompare);
    for(int i=0; i<cnt; i++){
        printf("%s\n", words[i]);
    }

    return 0;
}
