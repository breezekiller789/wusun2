#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char **argv){

    char *line, *ptr, *qtr, *copyline;
    double final;
    int len=0;

    line = (char *)malloc(sizeof(char) * MaxLine);

    ptr = *argv;
    while(*ptr && *ptr != ' '){
        len++;
        ptr++;
    }
    ptr++;

    /* printf("%ld\n", strlen(*argv)); */
    /* printf("%s\n", ptr); */

    copyline = (char *)malloc(sizeof(char) * len+1);
    qtr = copyline;
    while(*ptr != ' ' && *ptr){
        *qtr++ = *ptr++;
    }
    /* printf("%s\n", copyline); */


    /* ptr = argv */
    /* qtr = copyline; */

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        ptr = line;
        while(*ptr && *ptr != ' '){
            *qtr++ = *ptr++;
        }
    }
    final = atof(copyline);
    /* printf("%s\n", copyline); */
    printf("%f\n", final);



    return 0;
}
