#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

struct lnode{
    char *key;
    struct lnode *left;
    struct lnode *right;
};

struct lnode *BST_Insert(struct lnode *tp, char *line){
    if(tp == NULL){
        tp = (struct lnode *)malloc(sizeof(struct lnode));
        tp->key = (char *)malloc(sizeof(char) * strlen(line));
        strcpy(tp->key, line);
        /* printf("Insert = %s\n", tp->key); */
        tp->right = NULL;
        tp->left = NULL;
        return tp;
    }
    if(strcmp(tp->key, line) > 0){
        tp->left = BST_Insert(tp->left, line);
    }
    else if(strcmp(tp->key, line) < 0){
        tp->right = BST_Insert(tp->right, line);
    }
    else{
        return tp;
    }
    return tp;
}

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->left = NULL;
    node->right = NULL;
    return NULL;
};

void BST_inorder(struct lnode *tp){
    if(tp == NULL)
        return;
    BST_inorder(tp->left);
    printf("%s\n", tp->key);
    BST_inorder(tp->right);
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){
    struct lnode *root = NULL;
    char *line;
    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        root = BST_Insert(root, line);
    }
    BST_inorder(root);
    

    return 0;
}
