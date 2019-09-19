#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 100000
struct lnode *head = NULL;

struct lnode{
    char *word;
    struct lnode *next;
};

void BST_Insert_At_Front(char *line){
    struct lnode *NewNode;
    NewNode = (struct lnode *)malloc(sizeof(struct lnode));
    NewNode->word = (char *)malloc(sizeof(char) * strlen(line)+1);
    strcpy(NewNode->word, line);
    NewNode->next = NULL;
    if(head == NULL){
        head = NewNode;
    }
    else{
        NewNode->next = head;
        head = NewNode;
    }
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){
    char *line;
    struct lnode *node;
    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        BST_Insert_At_Front(line);
    }
    
    node = head;
    while(node!=NULL){
        printf("%s\n", node->word);
        node = node->next;
    }

    return 0;
}
