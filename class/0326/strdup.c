#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char line1[20] = "Hello, world";
    char **line2;
    line2 = (char **) malloc(sizeof(char *)*20);
    for(int i=0; i<20; i++){
        line2[i] = strdup(line1);
        printf("%s\n", line2[i]);
    }
    
    return 0;
}


