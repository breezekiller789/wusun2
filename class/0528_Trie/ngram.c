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

//  char8意思是unsigned char
//  有可能會有bug，如果今天已經到尾巴了，可能只剩下兩個字，這樣就會越界。
//
/* int getNgram(uchar *text, int N, uchar *nGram){ */
    
/*     int len=0, byteLen; */
/*     uchar *ptr, *ptrEnd; */
/*     ptrEnd = text + strlen(text);   //  用來維護，避免越界。 */
/*     while(len <= N && ptr < ptrEnd){//  後面是加上去的，來保護，避免越界。 */
/*         if(*ptr >= 224){ */
/*             ptr += 3; */
/*         } */
/*         else if(*ptr >= 192){ */
/*             ptr += 2; */
/*         } */
/*         else */
/*             ptr++; */
/*         len++; */
/*     } */
/*     byteLen = ptr - text; */
/*     memcpy(nGram, text, byteLen); */
/*     nGram[byteLen] = '\0'; */
/*     return byteLen; */
/* } */

int getNgram(uchar *text, int N, uchar *nGram){
    
    int len=0, byteLen;
    uchar *ptr, *ptrEnd;
    ptrEnd = text + strlen(text);   //  用來維護，避免越界。
    ptr = text;
    while(len < N && ptr < ptrEnd){//  後面是加上去的，來保護，避免越界。
        if(*ptr >= 224){
            ptr += 3;
        }
        else if(*ptr >= 192){
            ptr += 2;
        }
        else
            ptr++;
        len++;
    }
    byteLen = ptr - text;
    memcpy(nGram, text, byteLen);
    nGram[byteLen] = '\0';
    return byteLen;
}

int main(int argc, char *argv[]){
    
    uchar line[MaxLine];
    uchar utf8Char[4], nGram[64];
    uchar *ptr, *ptrEnd;
    int N, len;

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptrEnd = line + strlen(line);
        ptr = line;
        while(ptr < ptrEnd){
            for(N = 5; N>=1; N--){
                len = getNgram(ptr, N, nGram);
                //TODO: isTerm function
                /* if(isTerm(S, nGram) || N == 1){ */
                /*     printf("%s\n", nGram); */
                /*     break; */
                /* } */
                printf("%s\n", utf8Char);
            }
            //  跳出來之後，len應該要會是1
            ptr += len;
        }
    }

    return 0;
}
