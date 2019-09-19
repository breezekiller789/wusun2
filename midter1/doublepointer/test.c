#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    char **line, *bufline, *ptr;
    bufline = (char *)malloc(sizeof(char) * MaxLine);
    line = (char **)malloc(sizeof(char *) * 3);
    *line = (char *)malloc(sizeof(char) * 6);
    return 0;
}
