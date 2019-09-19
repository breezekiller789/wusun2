#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define TableSizeA (1<<8)
#define MaxName 1024
#define uchar unsigned char

int TermCnt = 0;
struct hnode result;

struct hnode{
    char key[MaxName];
    int cnt;
    struct hnode *next;
};

//      string polynomial
//      "apple" -> 'a' * r^4 + 'p' * r^3 + 'p' * r^2 + 'l' * r^1 + 'e' * r^0
//      ((((a*r + p) * r + p) * r + l) * r + e)
unsigned int hash33(unsigned char *key){     //Hash Function
    unsigned int hv;
    uchar *ptr;
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

struct hnode *HashFind(struct hnode *hashTab[], unsigned int HSize, uchar *key){
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

void HashInsert(struct hnode *hashTab[], unsigned int HSize, uchar *key){
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
    TermCnt++;
    strcpy(p->key, key);
    p->cnt = 1;
    p->next = hashTab[hv];  //Insert At Front!!!
    hashTab[hv] = p;

}

void HTraverse(struct hnode *hashTab[], unsigned int HSize, struct hnode array[]){
    int i, cnt=0, Max=0;
    struct hnode *p;
    for(i=0; i<HSize; i++){
        p = hashTab[i];     //  把hashtable的頭交給p。
        while(p != NULL){
            array[cnt] = *p;
            if(p->cnt > Max){
                Max = p->cnt;
                result = *p;
            }
            cnt++;
            /* printf("%d\t%s\n", p->cnt, p->key); */
            p = p->next;
        }
    }
    printf("%d\t%s\n", result.cnt, result.key);
}

void rmnewline(uchar *line){
    uchar *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

uchar *utf8getchar(uchar *text, uchar *Ch){
    int len;
    uchar *ptr, *qtr;
    if(*text == '\0')
        return NULL;
    if(*text >= 224){   //  1110 -> 128+64+32 = 224
        len = 3;
    }
    else if(*text >= 192){  //  110 -> 128+64 = 192
        len = 2;
    }
    else if(*text >= 128){
        Ch[0] = '\0';       //  代表如果碰到10，就不取
        return text+1;
    }
    else
        len = 1;
    ptr = text;
    qtr = Ch;
    /* printf("len: %d\n", len); */
    while(len){
        *qtr++ = *ptr++;
        len--;
    }
    *qtr = '\0';
    /* printf("ptr-text: %ld\n", ptr - text); */
    /* fflush(stdout); */
    return ptr;
}

int mycompare(const void *p, const void *q){
    struct hnode *x = (struct hnode *)p;
    struct hnode *y = (struct hnode *)q;
    return y->cnt - x->cnt;
}

int mycomparekey(const void *p, const void *q){
    struct hnode *x = (struct hnode *)p;
    struct hnode *y = (struct hnode *)q;
    if(x->cnt != y->cnt)
        return 0;
    return memcmp(x->key, y->key, 3);
}

/* void PutInArray(struct lnode *head, struct lnode *array, int TermCnt){ */
/*     int i; */
/*     struct lnode *node = head; */
/*     for(i=0; i<TermCnt; i++){ */
/*         array[i] = *node; */
/*         node = node->next; */
/*     } */
/* } */

int main(int argc, char *argv[]){
    
    uchar line[MaxLine];
    uchar utf8Char[4];
    uchar *ptr, *qtr;
    struct lnode *node, *head, *tmp;
    struct hnode *hashTab[TableSizeA + 13];
    unsigned int HSize = TableSizeA + 13;     //Hash Table Size
    /* printf("Hsize = %d\n", HSize); */
    HashInit(hashTab, HSize);

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        HashInsert(hashTab, HSize, line);
        /* while(ptr){ */
        /* while(ptr = utf8getchar(ptr, utf8Char)){ */
            /* ptr = utf8getchar(ptr, utf8Char); */
            /* if(strlen(utf8Char) < 3) */
            /*     continue; */
            /* else if(ptr == NULL) */
            /*     break; */
            /* HashInsert(hashTab, HSize, utf8Char); */
            /* printf("%s\n", node->words); */
            /* printf("%s\n", utf8Char); */
            /* printf("ptr - line: %ld \n", ptr-line); */
            /* ptr = qtr; */
            /* if(strlen(utf8Char) < 3){ */
            /*     continue;       //長度小於三就不是utf8，先不要印出來。 */
            /* } */
        /* } */
    }
    struct hnode array[TermCnt];
    HTraverse(hashTab, HSize, array);

    /* printf("TermCnt = %d\n", TermCnt); */
    return 0;
}
