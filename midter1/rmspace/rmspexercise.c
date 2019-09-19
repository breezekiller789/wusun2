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
    char **lines, *ptr, *qtr, *bufline;
    int idx=0;
    
    lines = (char **)malloc(sizeof(char *) * MaxLine);
    bufline = (char *)malloc(sizeof(char) * MaxLine);
    
    while(fgets(bufline, MaxLine, stdin)){
        rmnewline(bufline);
        ptr = bufline;
        idx = 0;
        while(1){
            while(*ptr == ' '){
                ptr++;
            }
            lines[idx] = (char *)malloc(sizeof(char) * strlen(bufline) + 1);
            qtr = lines[idx++];
            while(*ptr != '\0' && *ptr != ' '){
                *qtr++ = *ptr++;
            }
            *qtr = '\0';
            if(*ptr == ' '){
                while(*ptr == ' '){
                    ptr++;
                }
                if(*ptr == '\0')
                    break;
                else
                    continue;
            }
            else
                break;
        }
        /* printf("%d\n", idx); */
        for(int i=0; i<idx; i++){
            printf("%s", lines[i]);
            if(i == idx-1)
                break;
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}



