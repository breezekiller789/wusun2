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

    char *line, *ptr, *qtr, **words;
    int i=0;

    line = (char *)malloc(sizeof(char) * MaxLine);
    words = (char **)malloc(sizeof(char *) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        i = 0;
        while(1){
            while(*ptr == ' '){
                ptr++;
            }
            *(words+i) = (char *)malloc(sizeof(char) * strlen(line) + 1);
            qtr = *(words+i);
            i++;
            while(*ptr && *ptr != ' '){
                *qtr = *ptr;
                ptr++;
                qtr++;
            }
            if(*ptr == ' '){
                while(*ptr == ' '){
                    ptr++;
                }
                if(*ptr == '\0'){
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                break;
            }
        }
        /* printf("i = %d\n", i); */
        for(int k=0; k<i; k++){
            printf("%s", *(words+k));
            if(k != i-1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}
