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
    
    char *line, *ptr, *qtr, *src, *trg, *copyline;
    src = argv[1];
    trg = argv[2];
    /* printf("src = %s\n", src); */
    /* printf("trg = %s\n", trg); */

    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        if(strcmp(src, trg) < 0){
            if((ptr = strstr(line, src))){
                qtr = ptr;
                qtr += strlen(src);
                copyline = strdup(qtr);
                *ptr = '\0';
                strcat(line, trg);
                ptr = qtr = copyline;
                qtr += strlen(copyline) - 1;
                for(int i=0; i<strlen(copyline) / 2; i++){
                    char tmp;
                    tmp = *ptr;
                    *ptr = *qtr;
                    *qtr = tmp;
                    ptr++;
                    qtr--;
                }
                strcat(line, copyline);
                printf("%s\n", line);
            }
        }
        else{
            if((ptr = strstr(line, src))){
                qtr = ptr;
                qtr += strlen(src);
                copyline = strdup(qtr);
                *ptr = '\0';
                strcat(line, trg);
                strcat(line, copyline);
                ptr--;
                qtr = ptr;
                ptr = line;
                int len = qtr - ptr;
                for(int i=0; i<len/2; i++){
                    char tmp;
                    tmp = *ptr;
                    *ptr = *qtr;
                    *ptr = tmp;
                    ptr++;
                    qtr--;
                }
                printf("%s\n", line);



            }


        }

    }

    return 0;
}
