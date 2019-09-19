#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define FAILED -1
#define SUCCESS 1

struct lNode {
    int value;
    struct lNode *next;
};

struct lNode *NewNode(){
    struct lNode *node;
    node = (struct lNode *)malloc(sizeof(struct lNode));
    node->value = 0;
    node->next = NULL;
    return node;
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int getinput(struct lNode *node, char *line){
    int val;
    if(!isdigit(*line)){
        printf("Type Only Integers\n");
        return FAILED;
    }
    val = atoi(line);
    node->value = val;
    /* printf("%d\n", val); */
    return SUCCESS;
}

int main(int argc, char *argv[]){
    char *bufline;
    int i, j, idx=0;
    struct lNode *head, *node;
    head = NewNode();
    node = head;
    bufline = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(bufline, MaxLine, stdin)){
        rmnewline(bufline);
        if(getinput(node, bufline) == FAILED)
            continue;
        node->next = NewNode();
        node = node->next;
        idx++;
    }
    for(i=0; i<idx-1; i++){
        for(node=head; node->next->next!=NULL; node = node->next){
            if(node->value > node->next->value){
                int tmp;
                tmp = node->value;
                node->value = node->next->value;
                node->next->value = tmp;
            }
        }
    }
    for(node=head; node->next != NULL; node = node->next){
        printf("%d\n", node->value);
    }



    return 0;
}
