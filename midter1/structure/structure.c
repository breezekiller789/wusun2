#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define MaxNum 64
#define FAILED -1
#define SUCCESS 1

struct Score{
    int chinese;
    int english;
    int math;
    int science;
    int society;
    int sum;
    struct Score *next;
};

int parseline(char *line, int *chinese, int *english, int *science, int *math, int *society){
    char *ptr, *qtr;
    short gotchi, goteng, gotsci, gotmath, gotsoc;
    ptr = line;
    gotchi = goteng = gotsci = gotmath = gotsoc = FAILED;

    /* Get Chinese */
    if(*ptr == ' '){
        *chinese = 0;
        gotchi = SUCCESS;
        ptr++;
    }
    else{
        gotchi = SUCCESS;
        *chinese = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
    }
    /* printf("Chinese = %d\n", *chinese); */
    /* Get English */
    if(*ptr == ' '){
        *english = 0;
        goteng = SUCCESS;
        ptr++;
    }
    else{
        goteng = SUCCESS;
        *english = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
    }
    /* printf("English = %d\n", *english); */
    /* Get Science */
    if(*ptr == ' '){
        *science= 0;
        gotsci = SUCCESS;
        ptr++;
    }
    else{
        gotsci = SUCCESS;
        *science = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
    }
    /* printf("Science = %d\n", *science); */
    /* Get Math */
    if(*ptr == ' '){
        *math= 0;
        gotmath = SUCCESS;
        ptr++;
    }
    else{
        gotmath = SUCCESS;
        *math = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
    }
    /* printf("Math = %d\n", *math); */
    /* Get Society */
    if(*ptr == ' '){
        *society= 0;
        gotsoc = SUCCESS;
        ptr++;
    }
    else{
        gotsoc = SUCCESS;
        *society = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
    }
    /* printf("Society = %d\n", *society); */
    if(gotchi != SUCCESS && goteng != SUCCESS && gotsci != SUCCESS && gotmath != SUCCESS && gotsoc != SUCCESS){
        /* printf("ParseLine Failed!\n"); */
        return FAILED;
    }
    else{
        /* printf("ParseLine SUCCEED!!\n"); */
        return SUCCESS;
    }

}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

struct Score *NewNode(){
    struct Score *node;
    node = (struct Score *)malloc(sizeof(struct Score));
    node->next = NULL;
    node->sum = 0;
    return node;
};

int main(int argc, char *argv[]){

    char line[MaxLine];
    int chinese, english, science, math, society, stdcnt=0, i;
    struct Score *head, *node;
    head = NewNode();
    node = head;

    while(fgets(line, MaxLine, stdin)){
        chinese = english = science = math = society = 0;
        rmnewline(line);
        if(parseline(line, &chinese, &english, &science, &math, &society) == FAILED){
            continue;
        }
        node->chinese = chinese;
        node->english = english;
        node->science = science;
        node->math = math;
        node->society = society;
        node->sum = chinese + english + science + math + society;
        node->next = NewNode();
        node = node->next;
        stdcnt++;

        /* printf("%d %d %d %d %d\n", chinese, english, science, math, society); */

    }
    for(i=0; i<stdcnt-1; i++){
        for (node = head;  node->next != NULL; node = node->next) {
            int chitmp, engtmp, scitmp, mathtmp, soctmp, sumtmp;
            /* printf("--------------------Before Swap-----------------\n"); */
            struct Score *tmp;
            /* for(tmp = head; tmp->next != NULL; tmp = tmp->next){ */
            /*     printf("%d %d %d %d %d\n", tmp->chinese, tmp->english, tmp->science, tmp->math, tmp->society); */
            /* } */
            /* printf("Sum1 = %d, Sum2 = %d\n", node->sum, node->next->sum); */
            if(node->sum < node->next->sum){
                /* printf("Swaping Sum = %d and Sum = %d\n", node->sum, node->next->sum); */
                chitmp = node->chinese;
                engtmp = node->english;
                scitmp = node->science;
                mathtmp = node->math;
                soctmp = node->society;
                sumtmp = node->sum;

                node->chinese = node->next->chinese;
                node->english = node->next->english;
                node->science = node->next->science;
                node->math = node->next->math;
                node->society = node->next->society;
                node->sum = node->next->sum;

                node->next->chinese = chitmp;
                node->next->english = engtmp;
                node->next->science = scitmp;
                node->next->math = mathtmp;
                node->next->society = soctmp;
                node->next->sum = sumtmp;
            }
            /* printf("--------------------After Swap-----------------\n"); */
            /* for(tmp = head; tmp->next != NULL; tmp = tmp->next){ */
            /*     printf("%d %d %d %d %d\n", tmp->chinese, tmp->english, tmp->science, tmp->math, tmp->society); */
            /* } */
        }
    }


    for(node = head; node->next != NULL; node = node->next){
        printf("%d %d %d %d %d\n", node->chinese, node->english, node->science, node->math, node->society);
    }
    

    return 0;
}
