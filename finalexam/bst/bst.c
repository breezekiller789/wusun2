#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024
struct lnode{
    char *key;
    struct lnode *right;
    struct lnode *left;
};

struct lnode *BST_Insert(struct lnode *tp, char *line){
    if(tp == NULL){
        tp = (struct lnode *)malloc(sizeof(struct lnode));
        tp->key = (char *)malloc(sizeof(char) * strlen(line) + 1);
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
    else
        return tp;
    return tp;
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

void inorder(struct lnode *tp){
    if(tp == NULL)
        return;
    inorder(tp->left);
    printf("%s\n", tp->key);
    inorder(tp->right);
}

int main(int argc, char *argv[]){
    char line[MaxLine];
    struct lnode *root = NULL;

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        root = BST_Insert(root, line);
    }
    inorder(root);
    return 0;
}
