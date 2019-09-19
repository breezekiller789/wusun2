#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int enq = -1;
int deq = -1;

struct lnode{
    char *word;
    struct lnode *right;
    struct lnode *left;
};

struct lnode *BST_Inorder(struct lnode *tp, char *line){
    if(tp == NULL){
        tp = (struct lnode *)malloc(sizeof(struct lnode));
        tp->word = (char *)malloc(sizeof(char) * strlen(line) + 1);
        strcpy(tp->word, line);
        tp->right = NULL;
        tp->left = NULL;
        return tp;
    }
    if(strcmp(tp->word, line) > 0){
        tp->left = BST_Inorder(tp->left, line);
    }
    else if(strcmp(tp->word, line) < 0){
        tp->right = BST_Inorder(tp->right, line);
    }
    else
        return tp;
    return tp;
};
struct lnode *dequeue(struct lnode *Queue[]){
    struct lnode *ret = NULL;
    ret = Queue[++deq];
    return ret;
};

void enqueue(struct lnode *Queue[], struct lnode *tp){
    Queue[++enq] = tp;
}

void level_order(struct lnode Queue[], struct lnode *tp){
    struct lnode *tmpnode = NULL;
    tmpnode = tp;
    while(tmpnode != NULL){
        printf("%s\n", tmpnode->word);
        if(tmpnode->left != NULL){
            enqueue(Queue, tmpnode->left);
        }
        if(tmpnode->right != NULL){
            enqueue(Queue, tmpnode->right);
        }
        tmpnode = dequeue(Queue);
    }
}


void inorder(struct lnode *tp){
    if(tp == NULL)
        return;
    inorder(tp->left);
    printf("%s\n", tp->word);
    inorder(tp->right);
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    struct lnode *root = NULL;
    struct lnode *Queue[100];
    char *line;

    for(int i=0; i<100; i++)
        Queue[i] = NULL;

    line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        root = BST_Inorder(root, line);
    }
    /* inorder(root); */
    level_order(Queue, root);

    return 0;
}
