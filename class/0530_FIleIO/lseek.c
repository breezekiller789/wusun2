#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    int fp;
    int fsize;
    fp = open(argv[1], O_RDONLY);
    fsize = lseek(fp, 0, SEEK_END);
    printf("%d\n", fsize);

    return 0;
}
