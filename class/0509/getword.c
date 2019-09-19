#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

char *mygetchar(char *text, char chr[]){
    int len = getlen(*text);        //TODO : getlen
    for(int i=0; i<len; i++){
        chr[i] = text[i];
    }
    chr[i] = '\0';
    return text+=len;
}

int main(int argc, char *argv[]){

    

    return 0;
}
