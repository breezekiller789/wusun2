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
    
    char line[MaxLine], *src = argv[1], *trg = argv[2], *copyline;
    char *ptr, *qtr, *words[MaxLine];
    int linecnt=0;
    /* printf("src = %s\ntrg = %s\n", src, trg); */

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        if(strcmp(src, trg) < 0){
            if((ptr = qtr = strstr(line, src))){
                qtr += strlen(src);
                copyline = (char *)malloc(sizeof(char) * strlen(src));
                strcpy(copyline, qtr);
                *ptr = '\0';
                strcat(line, argv[2]);
                ptr = copyline;
                qtr = copyline;
                qtr += strlen(copyline)-1;
                for(int i=0; i<(strlen(copyline))/2; i++){
                    char tmp;
                    tmp = *ptr;
                    *ptr = *qtr;
                    *qtr = tmp;
                    qtr--;
                    ptr++;
                }
                strcat(line, copyline);
                words[linecnt] = (char *)malloc(sizeof(char) * strlen(line));
                strcpy(words[linecnt], line);
                linecnt++;
                /* strcat(line, copyline); */
                /* printf("%s\n", line); */
            }
        }
        else if(strcmp(src, trg) > 0){
            if((ptr = qtr = strstr(line, src))){
                qtr += strlen(src);
                copyline = (char *)malloc(sizeof(char) * strlen(src));
                strcpy(copyline, qtr);
                *ptr = '\0';
                strcat(line, trg);
                strcat(line, copyline);
                ptr--;
                /* printf("%s\n", line); */
                /* printf("%c\n", *ptr); */
                int len = (ptr - line) + 1;
                /* printf("len = %d\n", len); */
                qtr = line;
                for(int i=0; i < len/2; i++){
                    char tmp;
                    tmp = *qtr;
                    *qtr = *ptr;
                    *ptr = tmp;
                    ptr--;
                    qtr++;
                    /* printf("%s\n", line); */
                }
                words[linecnt] = (char *)malloc(sizeof(char) * strlen(line));
                strcpy(words[linecnt], line);
                /* printf("%s\n", line); */
                linecnt++;
            }
        }
        else{
            strcpy(words[linecnt], line);
            linecnt++;
        }
    }
    /* for(int i=0; i<linecnt; i++){ */
    /*     printf("%s\n", words[i]); */
    /* } */
    /* printf("%d\n", linecnt); */
    for(int i=linecnt-1; i>=0; i--){
        printf("%s\n", words[i]);
    }


    return 0;
}
