#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int enq = -1;
int deq = -1;

struct lnode {
    int value;
    struct lnode *right;
    struct lnode *left;
};

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->value = 0;
    node->right = NULL;
    node->left = NULL;
    return node;
};

struct lnode *BST_Insert(struct lnode *tp, int value){
    if(tp == NULL){
        tp = NewNode();
        tp->value = value;
        tp->right = NULL;
        tp->left = NULL;
        return tp;
    }
    if(tp->value > value){
        tp->left = BST_Insert(tp->left, value);
    }
    else{
        tp->right = BST_Insert(tp->right, value);
    }
    return tp;
};

void BST_inorder(struct lnode *tp){
    if(tp == NULL)
        return;
    BST_inorder(tp->left);
    printf("%d\n", tp->value);
    BST_inorder(tp->right);
}

struct lnode *dequeue(struct lnode *Queue[]){
    struct lnode *tp;
    tp = Queue[++deq];
    return tp;
};


void enqueue(struct lnode *Queue[], struct lnode *tp){
    Queue[++enq] = tp;
}
void BST_level_order(struct lnode *tp, struct lnode *Queue[]){
    struct lnode *tmpnode = NULL;
    tmpnode = tp;
    while(tmpnode != NULL){
        printf("%d\n", tmpnode->value);
        /* printf("now value = %d\tenq = %d\tdeq = %d\n", tp->value, enq, deq); */
        if(tmpnode->left != NULL){
            /* printf("Left Enqueue !\n"); */
            enqueue(Queue, tmpnode->left);
            /* int i=0; */
            /* while(enq > i){ */
            /*     printf("Queue[%d]->value = %d\n", i, Queue[i]->value); */
            /*     i++; */
            /* } */
        }
        if(tmpnode->right != NULL){
            /* printf("Right Enqueue !\n"); */
            enqueue(Queue, tmpnode->right);
            /* int i=0; */
            /* while(enq > i){ */
            /*     printf("Queue[%d]->value = %d\n", i, Queue[i]->value); */
            /*     i++; */
            /* } */
        }
        /* int i = deq; */
        /* while(Queue[i] != NULL){ */
        /*     printf("Queue->value = %d\n", Queue[i]->value); */
        /*     i++; */
        /* } */
        tmpnode = dequeue(Queue);
        /* printf("deq = %d\tenq = %d\n", deq, enq); */
        /* printf("%d\n", tmpnode->value); */
    }


}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    struct lnode *root = NULL;
    struct lnode *node;
    struct lnode *Queue[100];
    char *line;
    int value;
    for(int i=0; i<100; i++)
        Queue[i] = NULL;

    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        if(*line == '\0')
            continue;
        value = atoi(line);
        root = BST_Insert(root, value);
    }
    /* printf("root = %d\n", root->value); */
    /* BST_inorder(root); */
    BST_level_order(root, Queue);
    /* BST_inorder(root); */

    return 0;
}
