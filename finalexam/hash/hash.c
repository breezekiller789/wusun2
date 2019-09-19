#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024
#define TableSize (1<<10)

struct hnode{
    char *key;
    int cnt;
    struct hnode *next;
};

unsigned int hash33(char *line){
    char *ptr = line;
    unsigned int hv = 13;

    while(*ptr){
        hv = (hv << 5) + hv + *ptr;
        ptr++;
    }
    /* printf("hv = %d\n", hv); */
    return hv;
}

struct hnode *HashFind(struct hnode **HashTable, char *line, unsigned int HSize){
    unsigned int hv;
    struct hnode *p;
    hv = hash33(line) % HSize;  //  去看這個字串在Hash Table哪裏
    p = HashTable[hv];
    while(p != NULL){
        if(strcmp(p->key, line) == 0){
            return p;           //  找到啦！
        }
        p = p->next;
    }
    return NULL;
};

void HashInsert(struct hnode **HashTable, char *line, unsigned int HSize){
    struct hnode *p;
    unsigned int hv;
    p = HashFind(HashTable, line, HSize);
    if(p != NULL){          //  找到了，這個字串有出現過，把他cnt給加一。
        p->cnt++;
        return;
    }

    //  整個就不爽了，這個字串沒出現過。
    //  要Insert了，先去看要Insert在哪裡，先找hv
    hv = hash33(line) % HSize;
    p = (struct hnode *)malloc(sizeof(struct hnode));
    p->key = (char *)malloc(sizeof(char) * strlen(line) + 1);
    if(p == NULL){
        printf("Malloc Error!!\n");
        exit(1);
    }
    //  這裡就是真正Insert
    strcpy(p->key, line);
    p->cnt++;
    p->next = HashTable[hv];
    HashTable[hv] = p;
    /* printf("Insert %s\thv = %d\n", p->key, hv); */
};

void HashInit(struct hnode **HashTable, unsigned int HSize){
    for(int i=0; i<HSize; i++){
        HashTable[i] = NULL;
    }
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

/* void Put_In_Array(struct hnode **HashTable, unsigned int HSize */
/*         ,struct hnode *array){ */
/*     unsigned int i, cnt=0; */
/*     struct hnode *p; */
/*     for(i=0; i<HSize+13; i++){ */
/*         p = HashTable[i]; */
/*         while(p != NULL){ */
/*             array[cnt] = p; */
/*             cnt++; */
/*             p = p->next; */
/*         } */
/*     } */
/* } */

void HTraverse(struct hnode **HashTable, unsigned int HSize){
    struct hnode *p, array;
    unsigned int i;
    int Max=0;
    for(i=0; i<HSize; i++){
        p = HashTable[i];
        /* printf("haha\n"); */
        while(p != NULL){
            /* printf("%s\n", p->key); */
            if(p->cnt > Max){
                Max = p->cnt;
                array = *p;
            }
            p = p->next;
        }
        printf("%d\n", i);
    }
    printf("%d\t%s\n", array.cnt, array.key);

}

int main(int argc, char *argv[]){
    
    char *line;
    struct hnode *HashTable[TableSize + 13], array[TableSize];
    unsigned int HSize = TableSize + 13, hv;

    line = (char *)malloc(sizeof(char) * MaxLine);

    HashInit(HashTable, HSize);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        HashInsert(HashTable, line, HSize);
        /* hv = hash33(line); */
        /* printf("%d\n", hv); */
    }

    HTraverse(HashTable, HSize);
    /* Put_In_Array(HashTable, HSize, array); */
    

    return 0;
}
