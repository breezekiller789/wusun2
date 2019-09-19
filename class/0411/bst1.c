#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define MaxName 64

struct tNode{
    char name[MaxName];
    struct tNode *left;
    struct tNode *right;
    int cnt;
};

void rmnewline(char *line){
    char *ptr = line;
    /* 跑到換行或者跑到檔案結尾停下來 */
    while(*ptr && *ptr != '\n'){
        ptr++;
    }
    *ptr = '\0';
}

struct tNode *BST_insert(struct tNode *tp, char *key){

    struct tNode *p;
    if(tp == NULL){
        p = (struct tNode *)malloc(sizeof(struct tNode));
        if(p == NULL){      //檢查malloc有沒有成功
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        strcpy(p->name, key);
        p->cnt = 1;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    if(strcmp(tp->name, key) < 0){
        tp->right = BST_insert(tp->right, key);  //意思是右邊比較大
    }
    else if (strcmp(tp->name, key) == 0) {
        tp->cnt += 1;
    }
    else{ 
        tp->left = BST_insert(tp->left, key);   //意思是左邊比較大，key比較小
    }
    return tp;
}

/* Traverse ，是一個遞迴函式，要記得設條件讓他停下來*/
void BST_inorder(struct tNode *tp){

    if(tp == NULL)
        return;
    BST_inorder(tp->left);
    printf("%d\t%s\n", tp->cnt, tp->name);
    BST_inorder(tp->right);
}

void BST_preorder(struct tNode *tp){

    if(tp == NULL)
        return;
    printf("%s\n", tp->name);
    BST_preorder(tp->left);
    BST_preorder(tp->right);
}

void BST_postorder(struct tNode *tp){

    if(tp == NULL)
        return;
    BST_postorder(tp->left);
    BST_postorder(tp->right);
    printf("%s\n", tp->name);
}


int main(int argc, char *argv[]){

    struct tNode *bst = NULL;
    char line[MaxLine];


    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        bst = BST_insert(bst, line);   //回傳一個新的root
    }
    printf("Inorder traversal: \n");
    BST_inorder(bst);
    /* printf("Preorder traversal: \n"); */
    /* BST_preorder(bst); */
    /* printf("Postorder traversal: \n"); */
    /* BST_postorder(bst); */

    return 0;
}
