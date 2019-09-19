#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024

struct lnode *head = NULL;

struct lnode{
    char *key;
    struct lnode *next;
};

void Insert(char *line){
    struct lnode *node = NULL;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->key = (char *)malloc(sizeof(char) * strlen(line) + 1);
    strcpy(node->key, line);
    node->next = NULL;
    if(head == NULL){
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr !='\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){
    char line[MaxLine];
    
    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        Insert(line);
    }
    struct lnode *node = head;
    while(node != NULL){
        printf("%s\n", node->key);
        node = node->next;
    }

    return 0;
}
