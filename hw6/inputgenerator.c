#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#define MaxLine 1024
#define FALSE -1
#define TRUE 1
int Minusn, MinusN, Minusw, Minusm, Minusa, Qsort, Mergesort, Auto;
int NumberOfElement, WordLengh, MaxValue, AlphabetSetSize;
int *array;
char **words;

void initialize(){
    Minusn = MinusN = Minusw = Minusm = Minusa = Auto = FALSE;
    NumberOfElement = 100;
    WordLengh = 10;
    MaxValue = 10000;
    AlphabetSetSize = 26;
}

void parseline(int argc, char **argv){
    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-n") == 0){
            Minusn = TRUE;
        }
        else if(strcmp(argv[i], "-N") == 0){
            MinusN = TRUE;
            NumberOfElement = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-w") == 0){
            Minusw = TRUE;
            WordLengh = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-m") == 0){
            Minusm = TRUE;
            MaxValue = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-a") == 0){
            Minusa = TRUE;
            AlphabetSetSize = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-auto") == 0){
            Auto = TRUE;
            NumberOfElement = 100;
            WordLengh = 10;
            MaxValue = 10000;
            AlphabetSetSize = 26;
        }
        else{
            continue;
            /* printf("Usage : -n, -N, -w, -m, -a, -auto\n"); */
            /* return 0; */
        }
    }
}
void inputgenerator(){
    srand(time(NULL));
    int i, j;
    if(Minusn == TRUE){
        words = (char **)malloc(sizeof(char *) * NumberOfElement);
        for(i=0; i<NumberOfElement; i++){
            *(words+i) = (char *)malloc(sizeof(char) * WordLengh + 1);
        }
        for(i=0; i<NumberOfElement; i++){
            for(j=0; j<WordLengh-1; j++){
                words[i][j] = 'a'+(char)(rand() % AlphabetSetSize);
            }
            words[i][j] = '\0';
            /* printf("%s\n", *(words+i)); */
        }
    }
    else if(Minusn == FALSE){
        array = (int *)malloc(sizeof(int) * NumberOfElement);
        for(i=0; i<NumberOfElement; i++){
            array[i] = (rand() % MaxValue) + 1;
            /* printf("%d\n", array[i]); */
        }
    }
    else
        printf("Generating Input Error!!\n");
}

void printarguments(){
    printf("-n : %d\n", Minusn);
    printf("-N : %d\t%d\n", MinusN, NumberOfElement);
    printf("-w : %d\t%d\n", Minusw, WordLengh);
    printf("-m : %d\t%d\n", Minusm, MaxValue);
    printf("-a : %d\t%d\n", Minusa, AlphabetSetSize);
    printf("-auto : %d\n", Auto);
}

void printoutput(){
    int i;
    if(Minusn == TRUE){
        for(i=0; i<NumberOfElement; i++){
            printf("%s\n", *(words+i));
        }
    }
    else{
        for(i=0; i<NumberOfElement; i++){
            printf("%d\n", array[i]);
        }
    }
}


int main(int argc, char *argv[]){

    char *line;
    int i;
    struct timeval start, end;
    initialize();
    parseline(argc, argv);
    /* printarguments(); */
    inputgenerator();
    printoutput();
    /* int diff = 1000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000; */
    /* printf("time = %ld\n", end.tv_sec - start.tv_sec); */

    line = (char *)malloc(sizeof(char) * MaxLine);


    return 0;
}
