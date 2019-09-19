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

    char line[MaxLine], copyline[MaxLine], **words;
    char *ptr, *qtr;
    int i, idx=0, spacecnt=0;

    words = (char **)malloc(sizeof(char *) * MaxLine);

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        ptr = line;
        qtr = copyline;
        idx = 0;
        while(1){
            while(*ptr == ' '){
                ptr++;
            }
            words[idx] = (char *)malloc(sizeof(char) * MaxLine);
            qtr = words[idx++];
            while(*ptr && *ptr != ' '){
                *qtr++ = *ptr++;
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
            else
                break;
        }
        /* printf("idx = %d\n", idx); */
        for(i=0; i<=idx; i++){
            if(i != idx){
                printf("%s", words[i]);
            }
            if(i != idx-1)
                printf(" ");
            else{
                printf("\n");
                break;
            }
        }

    }

    return 0;
}
