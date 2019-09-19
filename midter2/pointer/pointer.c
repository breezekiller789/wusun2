#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define FAILED -1
#define SUCCESS 1

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char **argv){

    char *line, **words, *bufline;
    int option, GotOption = FAILED;
    int i=0;

    line = (char *)malloc(sizeof(char) * MaxLine);
    words = (char **)malloc(sizeof(char *) * MaxLine);
    bufline = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        if(isdigit(*line) && GotOption == FAILED){
            option = atoi(line);
            GotOption = SUCCESS;
            /* printf("OPTION = %d\n", option); */
            continue;
        }
        if(strstr(line, "INSERT")){
            fgets(bufline, 10000, stdin);
            rmnewline(bufline);
            *(words + i) = (char *)malloc(sizeof(char) * strlen(bufline) + 1);
            strcpy(*(words + i), bufline);
            i++;
        }
        else if(i >= option){
            for(int k=i-1; k>=0; k--)
                printf("%s\n", *(words + k));
        }
        else if(strstr(line, "OUTPUT")){
            for(int k=i-1; k>=0; k--)
                printf("%s\n", *(words + k));
            break;
        }
        else
            continue;
    }

    return 0;
}
