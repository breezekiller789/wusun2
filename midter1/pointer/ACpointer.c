#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

struct lnode {
    char *word;
    struct lnode *next;

};

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->next = NULL;
    return node;
};

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    char **lines, *ptr, *qtr, *bufline;
    int option, idx=0;
    int len;
    struct lnode *head, *node;

    head = NewNode();
    node = head;

    bufline = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(bufline, MaxLine, stdin)){
        rmnewline(bufline);
        ptr = bufline;
        if(isdigit(*ptr)){                  //第一行讀進來的是整數，表示會INSERT 幾行進來
            option = atoi(ptr);
            continue;
        }
        else if((qtr = strstr(bufline, "INSERT"))){
            qtr += strlen("INSERT")+1;      //遇到INSERT就把後面得那個數字取出來，用atoi，要加1是因為要略過空格，
            len = atoi(qtr);                //來表示說等一下要輸入的資料有多長。
            node->word = (char *)malloc(sizeof(char) * len);    //一定要malloc一塊記憶體給該linked list的data，不然會core dump。
            fgets(node->word, len+1, stdin);                    //這邊把INSERT進來的資料直接讀取進該linked list的data。
            rmnewline(node->word);                              //要記得把讀取進來的後面去掉換行，不然最後印的時候會多一行。
            node->next = NewNode();                             //準備好一個新的node給下一個資料使用，這邊設計的不好就是因為
            node = node->next;                                  //如果遇到最後一筆資料了，我還是會準備一個新的node，這樣就多一個，
            idx++;                                              //空的node了，導致我後面在做reverse的時候遇到問題，
            continue;                                           //原本只要寫while(current != NULL)
        }                                                       //而要改成現在這樣，然後再印的時候要略過空的node的資料。
        else if((qtr = strstr(bufline, "OUTPUT"))){
            struct lnode *prev = NULL, *next = NULL, *current = head;
            while(current->next != NULL){       //這邊是在做Lineked List 的 Reverse，要想一下
                next = current->next;           //https://www.geeksforgeeks.org/reverse-a-linked-list/
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
            //迴圈到這裡以上都是在做Reverse
            node = head;
            while(node != NULL){
                struct lnode *current = node;   //待會要free掉的
                if(node->word == NULL){
                    node = node->next;
                    continue;
                }
                printf("%s\n", node->word);
                node = node->next;
                free(current);
            }
            /* for(node=head; node->next != NULL; node = node->next){ */
            /*     printf("%s\n", node->word); */
            /* } */
        }
    }

    
    

    return 0;
}
