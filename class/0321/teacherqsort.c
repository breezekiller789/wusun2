#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MaxLine 1024
#define MaxLineCnt (1<<18)

int MystrCmp(void *p, void *q){
    char **x = (char **) p;
    char **y = (char **) q;
    return strcmp(*x, *y);
}


int main(){
    char *lines[MaxLineCnt];
    char line[MaxLine];
    int ldx = 0;

    while(fgets(line, MaxLine, stdin)){
        lines[ldx++] = strdup(line);

    }

    printf("Original array\n");
    for(int i=0; i<ldx; i++){
        printf("%s", lines[i]);
    }

    qsort(lines, ldx, sizeof(char *), MystrCmp);

    printf("after sorting\n");
    for(int i=0; i<ldx; i++){
        printf("%s", lines[i]);
    }
    return 0;
}


