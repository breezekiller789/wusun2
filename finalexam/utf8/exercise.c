#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024
#define uchar unsigned char

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

uchar utf8(uchar *line, uchar utf8char[4]){
    uchar *ptr, *qtr;
    int len;
    printf("hello\n");
    if(*line == '\0')
        return NULL;
    if(*ptr >= 224){
        len = 3;
    }
    else if(*ptr >= 192){
        len = 2;
    }
    else if(*ptr >= 128){
        utf8char = '\0';
        return line+1;
    }
    else
        len = 1;
    qtr = utf8char;
    ptr = line;
    while(len){
        *qtr = *ptr;
        ptr++;
        qtr++;
        len--;
    }
    *qtr = '\0';
    return ptr;

}

int main(int argc, char *argv[]){

    uchar line[MaxLine], *ptr, utf8char[4];

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(*ptr){
            ptr = utf8(ptr, utf8char);
            printf("%s\n", utf8char);

        }

    }


    return 0;
}
