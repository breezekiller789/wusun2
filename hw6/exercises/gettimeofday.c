#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/time.h>
#define MaxLine 1024

int main(int argc, char *argv[]){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sleep(1);
    gettimeofday(&end, NULL);
    printf("%ld\n", end.tv_sec - start.tv_sec);
    

    return 0;
}
