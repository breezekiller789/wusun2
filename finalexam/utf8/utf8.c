#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024
#define uchar unsigned char

void rmnewline(uchar *line){
    uchar *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

uchar *get_utf8char(uchar *line, uchar utf8char[4]){
    uchar *qtr, *ptr;
    int len;
    if(*line == NULL){
        return NULL;
    }
    if(*line >= 224){    //  1110 -> 128 + 64 + 32 = 224
        len = 3;        //  this is an utf8 word
    }
    else if(*line >= 192){
        len = 2;
    }
    else if(*line >= 128){   //  ASCII   不取
        utf8char = '\0';
        return line+1;
    }
    else
        len = 1;

    qtr = utf8char;
    ptr = line;
    /* printf("len = %d\n", len); */
    while(len){
    /* printf("hello\n"); */
        *qtr = *ptr;   
        ptr++;
        qtr++;
        len--;
    }
    *qtr = '\0';
    return ptr;
}

int main(int argc, char *argv[]){

    uchar *line, utf8char[4], *ptr;

    line = (uchar *)malloc(sizeof(uchar) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(*ptr){
            ptr = get_utf8char(ptr, utf8char);
            if(strlen(utf8char) < 3)
                continue;
            printf("%s\n", utf8char);
        }
    }

    return 0;
}
