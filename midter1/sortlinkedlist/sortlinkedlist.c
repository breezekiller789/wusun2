#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

struct lnode{
    char *word;
    struct lnode *next;
};

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->word = (char *)malloc(sizeof(char) * MaxLine);
    node->next = NULL;
    return node;
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    char *line;
    struct lnode *head, *node;
    int idx=0;
    head = NewNode();

    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        for(node = head; node->next != NULL; node = node->next){
            if(strcmp(node->word, line) == 0){
                break;
            }
        }
        if(node->next == NULL){     //代表走到底了都沒有找到一樣的字串，要Insert
            strcpy(node->word, line);
            node->next = NewNode();
            idx++;
        }
    }
    for(int i=0; i<idx-1; i++){
        for(node = head; node->next->next; node = node->next){
            if(strcmp(node->word, node->next->word) > 0){
                char *tmp;
                tmp = node->word;
                node->word = node->next->word;
                node->next->word = tmp;
            }
        }
    }
    for(node = head; node->next != NULL; node = node->next)
        printf("%s\n", node->word);

    return 0;
}
