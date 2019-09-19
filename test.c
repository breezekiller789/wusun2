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

int mycompare(const void *p, const void *q){
    char **x = (char **)p;
    char **y = (char **)q;
    return strcmp(*x, *y);
}

int main(int argc, char *argv[]){

    char **line, *bufline;
    int i=0;
    bufline = (char *)malloc(sizeof(char)*MaxLine);
    line =  (char **)malloc(sizeof(char *) * MaxLine);

    while(fgets(bufline, MaxLine, stdin)){
        rmnewline(bufline);
        line[i] = (char *)malloc(sizeof(char) * strlen(bufline));
        strcpy(line[i], bufline);
        i++;
    }
    qsort(line, i, sizeof(char *), mycompare);
    /* printf("i = %d\n", i); */
    for(int k=0; k<i; k++){
        printf("%s\n", line[k]);
    }
    

    return 0;
}
