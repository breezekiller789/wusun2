#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024

int enq = -1;
int deq = -1;

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
}

struct lnode *dequeue(struct lnode *Queue[]){
    struct lnode *ret;
    ret = Queue[++deq];
    return ret;
};

void enqueue(struct lnode *Queue[], struct lnode *tp){
    Queue[++enq] = tp;
}

void level_order(struct lnode *Queue[], struct lnode *tp){
    struct lnode *tmpnode = NULL;
    tmpnode = tp;
    while(tmpnode != NULL){
        printf("%s\n", tmpnode->key);
        if(tmpnode->left != NULL){
            enqueue(Queue, tmpnode->left);
        }
        if(tmpnode->right != NULL){
            enqueue(Queue, tmpnode->right);
        }
        tmpnode = dequeue(Queue);
    }

}

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
    struct lnode *Queue[100];

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        root = BST_Insert(root, line);
    }
    /* inorder(root); */
    level_order(Queue, root);
    return 0;
}
