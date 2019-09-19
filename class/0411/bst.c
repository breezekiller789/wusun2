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
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    if(strcmp(tp->name, key) < 0){
        tp->right = BST_insert(tp->right, key);  //意思是右邊比較大
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
    printf("%s\n", tp->name);
    BST_inorder(tp->right);
}


int main(int argc, char *argv[]){

    struct tNode *bst = NULL;
    char line[MaxLine];


    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        bst = BST_insert(bst, line);   //回傳一個新的root
        /* 下面這兩行可以看出程式的insert行為！！ */
        printf("insert %s\n", line);
        BST_inorder(bst);               //這邊可以檢查看是insert的問題還是inorder
    }
    BST_inorder(bst);   //in order traversal

    return 0;
}
