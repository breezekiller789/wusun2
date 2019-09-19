#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/fcntl.h>

#define MaxLine 1024
#define uchar unsigned char

int main(int argc, char *argv[]){
    char srcfile[MaxLine];
    char trgfile[MaxLine];
    char line[MaxLine];
    FILE *fs;
    FILE *ft;
    int fns, fnt;
    strcpy(fs, argv[1]);
    strcpy(ft, argv[2]);
    
    fns = open(srcfile, O_RDONLY);
    fnt = open(trgfile, O_RDONLY);
    printf("fns: %d, fnt: %d\n", fns, fnt);
    close(fns);
    close(fnt);

    fns = open(srcfile, O_RDONLY);
    fns = open(trgfile, O_RDONLY);
    printf("fns: %d, fnt: %d\n", fns, fnt);
    close(fns);
    close(fnt);

    fs = fopen(srcfile, "r");
    ft = fopen(trgfile, "w");

    while(fgets(line, MaxLine, fs) != NULL){
        fprintf(ft, "%s", line);
    }

    return 0;
}
