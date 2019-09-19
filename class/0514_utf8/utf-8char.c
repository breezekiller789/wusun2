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

char *utf8getchar(char *text, char *Ch){
    int len;
    char *ptr, *qtr;
    if(*text >= 224){   //  1110 -> 128+64+32 = 224
        len = 3;
    }
    else if(*text >= 192){  //  110 -> 128+64 = 192
        len = 2;
    }
    else if(*text >= 128){
        Ch[0] = '\0';       //  代表如果碰到10，就不取
        return text+1;
    }
    else
        len = 1;
    ptr = text;
    qtr = Ch;
    while(len){
        *qtr++ = *ptr++;
        len--;
    }
    *qtr = '\0';
    return ptr;
}

int main(int argc, char *argv[]){
    
    char line[MaxLine];
    char utf8Char[4];
    char *ptr, *qtr;

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(ptr){
        /* while(ptr = utf8getchar(ptr, utf8Char)){ */
            qtr = utf8getchar(ptr, utf8Char);
            ptr = qtr;
            if(strlen(utf8Char) < 3){
                continue;       //長度小於三就不是utf8，先不要印出來。
            }
            printf("%s\n", utf8Char);
        }
    }

    return 0;
}
