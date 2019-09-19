#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024

struct lnode{
    char *key;
    struct lnode *next;
};

struct lnode *NewNode(){
    struct lnode *node = NULL;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->next = NULL;
    return node;
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    char line[MaxLine];
    struct lnode *head, *node;
    head = NewNode();
    node = head;

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        node->next = NewNode();
        node->key = (char *)malloc(sizeof(char) * strlen(line) + 1);
        strcpy(node->key, line);
        node = node->next;
    }
    node = head;
    while(node->next != NULL){
        printf("%s\n", node->key);
        node = node->next;
    }

    return 0;
}
