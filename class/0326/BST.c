#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLine 1024

struct tnode{
    char key[MaxKeyLen];
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

struct tnode *namep;

BST_insert(struct tnode *tree, char *key){
    struct tnode *p;
    if(tree == NULL){
        p = (struct tnode *) malloc(sizeof(struct tnode));
        strcpy(p->key, key);
        p->leftChild = NULL;
        p->rightChild = NULL;
    }
    tree->leftChild = BST_insert(tree->leftChild, key);



}

BST_traverse();

BST_find();

BST_delete();       //  Hardest

int main(int argc, char *argv[]) {
    


    
    return 0;
}



