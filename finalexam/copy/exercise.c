#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#define MaxLine 1024


int main(int argc, char **argv){
    ssize_t numin, numout;
    int InputFd, OutputFd;
    char buffer[MaxLine];
    InputFd = open(argv[1], O_RDONLY);
    OutputFd = open(argv[2], O_WRONLY | O_CREAT, S_IROTH);
    /* printf("I = %d\nO = %d\n", InputFd, OutputFd); */

    while((numin = read(InputFd, buffer, MaxLine)) > 0){
        numout = write(OutputFd, buffer, (ssize_t)numin);
        /* if(numin != numout){ */
        /*     printf("what??\n"); */
        /* } */
    }
    return 0;   



}
