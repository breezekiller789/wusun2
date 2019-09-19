#include "kvihash.h"

//初始化之後兩個動作一定要做，第一：Insert，第二：Find

void HashInit(struct hnode ***HashTab, int32 maxHash){
    *HashTab = (struct hnode **)malloc(sizeof(struct hnode *) * maxHash);
    if(*HashTab == NULL){
        fprintf(stderr, "malloc failed\n");
    }
    for(int32 i=0; i<maxHash; i++){
        (*HashTab)[i] = NULL;
    }
}

//int32 hash65(uchar *key){
int32 hash33(uchar *key){
    int32 hv, i, len;
    hv = 13;        //  隨便給一個質數，13, 17, 23都ＯＫ
    len = strlen(key);
    for(i=0; i<len; i++){
        hv = (hv<<5) + hv + key[i];
        //hv = (hv<<6) + hv + key[i];
    }
    return hv;
}

struct hnode *HashFind(struct hnode **HashTab, int32 maxHash, uchar *key){
    int32 hashv;
    struct hnode *np;
    hashv = hash33(key) % maxHash;
    np = HashTab[hashv];
    while(np != NULL){      //  search in linked list
        if(strcmp(np->key, key) == 0){
            return np;
        }
        np = np->next;
    }
    return NULL;
}

void HashInsert(struct hnode **HashTab, int32 maxHash, uchar *key){
    int32 hashv;   // hash value
    struct hnode *np, *tmp;
    np = HashFind(HashTab, maxHash, key);
    if(np != NULL){
        np->count++;
        return;
    }
    hashv = hash33(key) % maxHash;
    tmp = (struct hnode *)malloc(sizeof(struct hnode));
    tmp->key = strdup(key);
    tmp->count = 1;
    //  Insert Linked List At Front
    tmp->next = np;
    HashTab[hashv] = tmp;
}

void HTraverse(struct hnode **HashTab, int32 maxHash){
    int i;
    struct hnode *np;   //  node pointer
    for(i=0; i<maxHash; i++){
        np = &HashTab[i];
        while(np){
            printf("%d\t%s\n", np->count, np->key);
            np = np->next;
        }
    }
}

void freeNode(struct hnode *np){
    free(np->key);  //這兩個順序千萬不可改，如果先free掉np，下一步free key
    free(np);       //就會出大事
}

void closeHashTab(struct hnode **HashTab, int32 maxHash){
    int i;
    struct hnode *np, *next;
    for(i=0; i<maxHash; i++){
        np = HashTab[i];    
        while(np){
            next = np->next;    //記得每刪除一個節點之前要把下一個記住。
            freeNode(np);   
            np = next;
        }
    }
    free(HashTab);      //  最後也要把自己本身給free掉。

}

void rmnewline(uchar *line){
    uchar *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){
    struct hnode **HashTab, *np;
    int32 maxHash = 1<<15;
    /* printf("maxHash = %d\n", maxHash); */
    uchar line[MaxLine];
    HashInit(&HashTab, maxHash);
    while(fgets(line, MaxLine, stdin) != NULL){
        /* rmnewline(line); */
        /* HashInsert(HashTab, maxHash, line); */
        np = HashFind(HashTab, maxHash, line);  //一進來就去檢查看看是否已經存
        if(np){                                 //在
            np->count += 1;
        }
        else{
            HashInsert(HashTab, maxHash, line);
        }
    }
    HTraverse(HashTab, maxHash);
    closeHashTab(HashTab, maxHash);
    

    return 0;
}
