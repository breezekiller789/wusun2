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

    char **lines, *ptr, *bufline;
    int idx=0;

    lines = (char **)malloc(sizeof(char *) * MaxLine);
    bufline = (char *)malloc(sizeof(char) * MaxLine);

    ptr = *lines;

    while(fgets(bufline, MaxLine, stdin)){
        ptr = (char *)malloc(sizeof(char) * strlen(bufline));
        rmnewline(bufline);
        strcpy(ptr, bufline);
        *lines = strdup(ptr);
        /* printf("%s\n", ptr); */

    }
    ptr = *lines;
    printf("%s\n", *lines);
    for(int i=0; i<idx; i++)
        printf("%s\n", ptr++);

    free(lines);
    free(bufline);


    return 0;

}
/* lines -> 0x1234 -> 0x2234 */
/* *lines -> 0x2234 -> apple */
/* *lines++ -> 0x2235 -> banana */
/* *lines++ -> 0x2236 -> candy */


