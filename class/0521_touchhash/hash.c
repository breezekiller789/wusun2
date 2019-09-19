/* tcount using Hashing */
/* 輸入資料：一行一個term */
/* 輸出每個term的出現次數 */
/* Data structure: */
/* 採用array of linked list */

/* Hash Table */
/* Data Node List */
/* HashTable size : maxHash */
/* jash function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define TableSizeA (1<<15)
#define MaxName 1024
/* #define unsigned int unsigned int */

struct hnode{
    char key[MaxName];
    int cnt;
    struct hnode *next;
};

//      string polynomial
//      "apple" -> 'a' * r^4 + 'p' * r^3 + 'p' * r^2 + 'l' * r^1 + 'e' * r^0
//      ((((a*r + p) * r + p) * r + l) * r + e)
unsigned int hash33(char *key){     //Hash Function
    unsigned int hv;
    char *ptr;
    hv = 13;
    ptr = key;
    while(*ptr){
        /* printf("hv + *ptr = %d\n", hv + *ptr); */
        /* printf("hv<<5 = %d\n", (hv<<5)); */
        hv = (hv<<5) + (hv + *ptr);      //往左shift五個bit，再加上自己，就是33
        /* printf("hv = %d\n", hv); */
        ptr++;
        /* hv = hv * 33 + *ptr;        //這樣寫會比較慢，因為電腦做加法比做乘法快。 */
    }
    return hv;
}

void HashInit(struct hnode **hashTab, unsigned int HSize){
    int i;
    for(i=0; i<HSize; i++){
        hashTab[i] = NULL;
    }
}

struct hnode *HashFind(struct hnode *hashTab[], unsigned int HSize, char *key){
    unsigned int hv;
    struct hnode *p;
    hv = hash33(key) % HSize;
    /* printf("hv = %d\n", hv); */
    p = hashTab[hv];        //這邊就拿到linked list的頭。
    while(p != NULL){
        if(strcmp(p->key, key) == 0){
            return p;       //找到了就直接回傳p
        }
        p = p->next;
    }
    return NULL;            //代表沒有找到
}

void HashInsert(struct hnode *hashTab[], unsigned int HSize, char *key){
    struct hnode *p;
    unsigned int hv;
    p = HashFind(hashTab, HSize, key);
    if(p){          //key存在，把cnt加一。
        p->cnt++;
        return;
    }
    //Insert 之前要先知道他要insert在Hash Table 的哪裡。
    hv = hash33(key) % HSize;   //得到Hash Value
    p = (struct hnode *)malloc(sizeof(struct hnode));
    if(p == NULL){          //如果malloc有錯誤，要記得印出錯誤訊息。
        fprintf(stderr, "malloc failed at HashInsert() !\n");
    }
    strcpy(p->key, key);
    p->cnt = 1;
    p->next = hashTab[hv];  //Insert At Front!!!
    hashTab[hv] = p;

}

void HTraverse(struct hnode *hashTab[], unsigned int HSize){
    int i;
    struct hnode *p;
    for(i=0; i<HSize; i++){
        p = hashTab[i];     //  把hashtable的頭交給p。
        while(p != NULL){
            printf("%d\t%s\n", p->cnt, p->key);
            p = p->next;
        }
    }
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}


int main(int argc, char *argv[]){
    
    char *line;
    struct hnode *hashTab[TableSizeA + 13];
    unsigned int HSize = TableSizeA + 13;     //Hash Table Size
    /* printf("Hsize = %d\n", HSize); */

    line = (char *)malloc(sizeof(char) * MaxLine);

    HashInit(hashTab, HSize);
    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        /* printf("HSize = %d\n", HSize); */
        /* printf("line = %s\n", line); */
        HashInsert(hashTab, HSize, line);
    }

    /* for(int i=0; i<HSize; i++){ */
        HTraverse(hashTab, HSize);
    /* } */

    return 0;
}
