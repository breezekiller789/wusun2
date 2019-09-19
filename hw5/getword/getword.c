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
    FILE *fp;
    int i=0;

    fp = fopen(argv[1], "r");

    line = (char *)malloc(sizeof(char) * MaxLine);
    words = (char **)malloc(sizeof(char *) * MaxLine);

    while(fgets(line, MaxLine, fp) != NULL){
        rmnewline(line);
        ptr = line;
        if(strstr(line, "<SOS>"))
            continue;
        if(strstr(line, "<EOS>"))
            continue;
        while(1){
            while(isspace(*ptr)){
                ptr++;
            }
            if(*ptr == '\0')
                break;
            *(words+i) = (char *)malloc(sizeof(char) * strlen(line));
            qtr = *(words+i);
            while(*ptr && !isspace(*ptr)){
                *qtr = *ptr;
                /* printf("qtr = %c\tptr = %c\n", *qtr, *ptr); */
                ptr++;
                qtr++;
            }
            /* printf("%s\n", *(words+i)); */
            i++;
            if(isspace(*ptr)){
                while(isspace(*ptr)){
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
    }

    for(int k=0; k<i; k++){
        printf("%s\n", *(words+k));
    }

    return 0;
}
