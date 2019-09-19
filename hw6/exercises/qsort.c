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

    char *line, **words;
    FILE *fp;
    int i=0;
    fp = fopen("input", "r");
    line = (char *)malloc(sizeof(char) * MaxLine);
    words = (char **)malloc(sizeof(char *) * 1000);

    while(fgets(line, MaxLine, fp) != NULL){
        rmnewline(line);
        /* printf("%s\n", line); */
        *(words + i) = strdup(line);
        i++;
    }
    qsort(words, i, sizeof(char *), mycompare);
    for(int k=0; k<i; k++){
        printf("%s\n", *(words+k));
    }


    return 0;
}
