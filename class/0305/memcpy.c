#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    char line[] = "apple is sweet";
    char *ptr;
    ptr = (char *)malloc(sizeof(strlen(line)+1));
    memcpy(ptr, line, 7);
    printf("%s\n", ptr);

    return 0;
}
