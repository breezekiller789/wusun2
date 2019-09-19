#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define uchar unsigned char

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

char *utf8getchar(uchar *text, uchar *Ch){
    int len;
    char *ptr, *qtr;
    if(*text == '\0')
        return NULL;
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
    /* printf("len: %d\n", len); */
    while(len){
        *qtr++ = *ptr++;
        len--;
    }
    *qtr = '\0';
    /* printf("ptr-text: %ld\n", ptr - text); */
    /* fflush(stdout); */
    return ptr;
}

int main(int argc, char *argv[]){
    
    uchar line[MaxLine];
    uchar utf8Char[4];
    uchar *ptr, *qtr;

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(ptr){
        /* while(ptr = utf8getchar(ptr, utf8Char)){ */
            ptr = utf8getchar(ptr, utf8Char);
            if(strlen(utf8Char) < 3)
                continue;
            else if(ptr == NULL)
                break;
            printf("%s\n", utf8Char);
            /* printf("%s\n", utf8Char); */
            /* printf("ptr - line: %ld \n", ptr-line); */
            /* ptr = qtr; */
            /* if(strlen(utf8Char) < 3){ */
            /*     continue;       //長度小於三就不是utf8，先不要印出來。 */
            /* } */
        }
    }

    return 0;
}
