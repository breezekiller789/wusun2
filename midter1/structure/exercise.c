#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define FAILED -1
#define SUCCESS 1

struct lnode{
    int chi, eng, math, sci, soc, sum;
    struct lnode *next;
};

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->next = NULL;
    node->chi = node->eng = node->math = node->sci = node->soc = node->sum = 0;
    return node;
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int parseline(char *line, int *chinese, int *english, int *math, int *science, int *society){
    char *ptr;
    int gotchi, goteng, gotmath, gotsci, gotsoc;
    gotchi = goteng = gotmath = gotsci = gotsoc = FAILED;
    ptr = line;
    if(isdigit(*ptr)){
        *chinese = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
        gotchi = SUCCESS;
    }
    else{
        *chinese = 0;
        ptr++;
        gotchi = SUCCESS;
    }

    if(isdigit(*ptr)){
        *english = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
        goteng = SUCCESS;
    }
    else{
        *english = 0;
        ptr++;
        goteng = SUCCESS;
    }

    if(isdigit(*ptr)){
        *math = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
        gotmath = SUCCESS;
    }
    else{
        math = 0;
        ptr++;
        gotmath = SUCCESS;
    }

    if(isdigit(*ptr)){
        *science = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        ptr++;
        gotsci = SUCCESS;
    }
    else{
        *science = 0;
        ptr++;
        gotsci = SUCCESS;
    }

    if(isdigit(*ptr)){
        *society = atoi(ptr);
        while(isdigit(*ptr))
            ptr++;
        gotsoc = SUCCESS;
    }
    else{
        *society = 0;
        ptr++;
        gotsoc = SUCCESS;
    }
    if(gotchi==SUCCESS && goteng==SUCCESS && gotmath==SUCCESS && gotsci==SUCCESS && gotsoc==SUCCESS)
        return SUCCESS;
    else
        return FAILED;
}

int main(int argc, char *argv[]){

    struct lnode *head, *node;
    char *line;
    int chinese, english, math, science, society;

    head = NewNode();
    node = head;

    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        chinese = english = math = science = society = 0;
        if(parseline(line, &chinese, &english, &math, &science, &society) == FAILED){
            continue;
        }
        node->chi = chinese;
        node->eng = english;
        node->math = math;
        node->sci = science;
        node->soc = society;
        node->sum = chinese + english + math + science + society;
        
        node->next =NewNode();
        node = node->next;

        /* printf("chinese = %d\n", chinese); */
        /* printf("english = %d\n", english); */
        /* printf("math = %d\n", math); */
        /* printf("science = %d\n", science); */
        /* printf("society = %d\n", society); */
    }
    struct lnode *tmp, *current, *next, *prev=NULL;
    current = head;
    while(current->next->next != NULL){
        if(current->sum < current->sum){
            tmp = next->next;
            prev->next = next;
            prev->next->next = current;
            current->next = tmp;
        }
    }

        
    for(node=head; node->next!=NULL; node=node->next)
        printf("%d %d %d %d %d sum = %d\n", node->chi, node->eng, node->math, node->sci, node->soc, node->sum);

    return 0;
}
