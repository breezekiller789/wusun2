#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

struct lnode{
    char *word;
    struct lnode *right;
    struct lnode *left;
};

struct lnode *NewNode(char *key){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->word = (char *)malloc(sizeof(char) * strlen(key) + 1);
    node->right = NULL;
    node->left = NULL;
    return node;
}

struct lnode *BST_Insert(struct lnode *tp, char *key){
    if(tp == NULL){
        tp = NewNode(key);
        strcpy(tp->word, key);
        return tp;
    }
    if(strcmp(tp->word, key) > 0){      //左邊大
        tp->left = BST_Insert(tp->left, key);
    }
    else{
        tp->right = BST_Insert(tp->right, key);
    }
    return tp;
}

void print_linked_list(struct lnode *tp){
    if(tp == NULL){
        return;
    }
    print_linked_list(tp->left);   
    printf("%s\n", tp->word);
    print_linked_list(tp->right);
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    struct lnode *tp = NULL, *node;
    char *line;
    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        tp = BST_Insert(tp, line);
    }
    print_linked_list(tp);
    return 0;
}
