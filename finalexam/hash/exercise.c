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

unsigned int hash33(char *key){
    unsigned int hv = 13;
    char *ptr = key;
    while(*ptr){
        hv = (hv << 5) + hv + *ptr;
        ptr++;
    }
    return hv;
}

struct hnode *Hash_Find(struct hnode **HashTable, char *line, unsigned int HSize){
    struct hnode *tp;
    unsigned int hv;
    hv = hash33(line) % HSize;
    tp = HashTable[hv];
    while(tp != NULL){
        if(strcmp(tp->key, line) == 0){
            return tp;      //  found it!!
        }
        tp = tp->next;
    }
    return NULL;
};

void Hash_Insert(struct hnode **HashTable, char *line, unsigned int HSize){
    struct hnode *tp;
    unsigned int hv;
    tp = Hash_Find(HashTable, line, HSize);
    if(tp != NULL){ //  already exists
        tp->cnt++;
        return;
    }
    hv = hash33(line) % HSize;
    tp = (struct hnode *)malloc(sizeof(struct hnode));
    tp->key = (char *)malloc(sizeof(char) * strlen(line) + 1);
    tp->cnt = 1;
    strcpy(tp->key, line);
    tp->next = HashTable[hv];
    HashTable[hv] = tp;
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr !='\n')
        ptr++;
    *ptr = '\0';
}

void Hash_Init(struct hnode **HashTable, unsigned int HSize){
    int i;
    for(i=0; i<HSize; i++){
        HashTable[i] = NULL;
    }
}

void HTraverse(struct hnode **HashTable, unsigned int HSize){
    unsigned int i=0;
    int Max = 0;
    struct hnode *tp, *array;
    for(i=0; i<HSize; i++){
        tp = HashTable[i];
        while(tp != NULL){
            if(tp->cnt > Max){
                Max = tp->cnt;
                array = tp;
            }
            tp = tp->next;
        }
    }
    printf("%d\t%s\n", array->cnt, array->key);

}

int main(int argc, char *argv[]){
    char line[MaxLine];
    struct hnode *HashTable[TableSize+13];
    unsigned int HSize = TableSize+13, hv;

    Hash_Init(HashTable, HSize);
    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        Hash_Insert(HashTable, line, HSize);
    }
    HTraverse(HashTable, HSize);   

    return 0;
}
