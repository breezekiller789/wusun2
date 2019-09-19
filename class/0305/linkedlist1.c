#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxKey 64
#define MaxValue 64

struct lnode{
    char key[MaxKey];
    char value[MaxValue];
    struct lnode *next;
};

//  insert a new node to the linked represented by listp
//  return new head if the linked list
//  this  insertion will insert the new node at front
struct lnode *lInsertH(struct lnode *listp, char *key, char *value){
    struct lnode *p;    //指到了一個新的節點
    p = (struct lnode *) malloc(sizeof(struct lnode));
    if(p == NULL){
        fprintf(stderr, "malloc failed: p, lInsertH()\n");
        exit(1);
    }
    strcpy(p->key, key);
    strcpy(p->value, value);
    p->next = listp;
    return p;
}

int listTraverse(struct lnode *listp){
    struct lnode *p = listp;
    int cnt = 0;
    while(p != NULL){
        printf("%s\t%s\n", p->key, p->value);
        cnt++;
        p = p->next;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    struct lnode *dictionary = NULL;    //  initialization
    int cnt;
    
    dictionary = lInsertH(dictionary, "apple", "蘋果");
    dictionary = lInsertH(dictionary, "banana", "香蕉");

    cnt = listTraverse(dictionary);
    printf("%d elements in the linked list\n", cnt);
    
    return 0;

}


