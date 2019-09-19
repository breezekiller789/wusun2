#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MaxLine 1024

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
}

int main(){
    int linenum, len, idx=0;
    char line[MaxLine], **lines;
    char *ptr, *qtr;


    /* line = (char *)malloc(sizeof(char)*1024); */ 
    lines = (char **)malloc(sizeof(char *)*1024);
    
    while(fgets(line, MaxLine, stdin) != NULL){
        ptr = line;
        printf("line =%s", line);
        while(!isdigit(*ptr)){
            ptr++;
        }
        printf("ptr =%s", ptr);
        len = atoi(ptr);
       lines[idx] = (char *)malloc(sizeof(char)*len+1);
        fgets(lines[idx], len+1, stdin);
        idx++;
        /* printf("%d\n", len); */
    }
    /* for(int i=0; i<idx; i++) */
    /*     printf("%s", lines[i]); */

}

