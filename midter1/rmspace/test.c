#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MaxLine 1024
#define FAILED -1
#define SUCCESS 1
 
int rmnewline(char *line){
    int i=0;
    while(line[i] != '\n' || line[i] == '\0')
        i++;
    line[i] = '\0';
    return i;
}
 
 
 
int main(){
    char line[MaxLine], finalline[MaxLine];
    /* int i = isspace('\n'); */
    /* printf("%d\n", i); */
    char *ptr, *qtr;
    int i, len, HasSpace, StartWithSpace, idx;
    while(fgets(line, MaxLine, stdin) != NULL){
        /* if(line[0] == '\n') */
        /*     continue; */
        len = rmnewline(line);
        ptr = line;
        qtr = finalline;
        StartWithSpace = FAILED;
        for(i=0; i<len; i++){
            HasSpace = FAILED;
            while(isspace(*ptr)){
                if(i==0)
                    StartWithSpace = SUCCESS;
                HasSpace = SUCCESS;
                ptr++;
            }
            while(*ptr != ' ' && *ptr != '\0' && *ptr != '\t'){
                printf("%c", *ptr);
                *qtr++ = *ptr++;
                if(isspace(*ptr))
                    printf(" ");
            }
        }
        printf("\n");
        
 
 
    }
 
 
 
 
 
 
}
