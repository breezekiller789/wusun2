#include <stdlib.h>
#include <stdio.h>
#define MaxLine 1024


int main(int argc, char **argv){
    char line[MaxLine];
    char totalline[MaxLine];
    char *ptr, *qtr;
    int i;
    ptr = argv[1];
    qtr = totalline;
    while(*ptr != '\0'){
        *qtr = *ptr;
        qtr++;
        ptr++;
    }
    /* printf("%s\n", totalline); */


    while(fgets(line, MaxLine, stdin)){
               



    }




}

