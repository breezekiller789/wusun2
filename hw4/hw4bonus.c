//  term count
//  計算單字出現的個數
//  +, -, ?    分別為輸入，刪除，查詢
//  +apple就是輸入apple
//  -apple就是刪除apple，如果刪到沒有apple這個單字，就輸出apple is not in list
//  ?apple就是查詢apple，如果沒有apple這個單字，就輸出No result
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxLine 1024
#define SUCCESS 1
#define FAILED -1
#define MaxOdr 100

struct words {
    char word[MaxLine];
    int cnt;
    struct words *next;
};

struct words *NewNode(){
    struct words *node;
    node = (struct words *) malloc(sizeof(struct words));
    node->cnt=0;
    node->next = NULL;
    return node;
};

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
}

void swap(short order[], int x, int y){
    int tmp;
    tmp = order[x];
    order[x] = order[y];
    order[y] = tmp;
}

int compareline(const void *p, const void *q){
    struct words *x = (struct words *) p;
    struct words *y = (struct words *) q;
    return strcmp(y->word, x->word);
}

int compareint(const void *p, const void *q){
    struct words *x = (struct words *) p;
    struct words *y = (struct words *) q;
    int result;
    result = x->cnt - y->cnt;
    return result;

}

int parseline(char *line, char *word){
    char *ptr, *qtr;
    ptr = line;
    qtr = word;
    if(*ptr == '+' || *ptr == '-' || *ptr == '?')
        ptr++;
    if(isspace(*ptr))
        return FAILED;
    while(*ptr != '\0'){
        *qtr++ = *ptr++;
    }
    *qtr = '\0';
    return SUCCESS;
}

int main(){
    char line[MaxLine];
    char word[MaxLine];
    int i, j;
    short FoundOne, order[MaxOdr], TermCnt=0;
    struct words *head;  
    struct words *node;
    struct words *follow;
    head = NewNode();
    node = head;

    for(i=0; i<MaxOdr; i++)
        order[i] = i;

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        FoundOne = FAILED;
        if(parseline(line, word) == FAILED){
            continue;
        }
        if(line[0] == '+'){
            //如果這個單字已經有了，就進去那個node裡面把cnt++
            for(node=head; node->next != NULL; node=node->next){
                if(strcmp(node->word, word) == 0){
//                    printf("%s\n", word);
                    node->cnt++;
//                    printf("%d\n", node->cnt);
                    break;
                }
            }
            //如果沒有這個單字，就創一個新的節點，然後把cnt++
            if(node->next == NULL){
//                printf("NULL!!\n");
                node->next = NewNode();
                strcpy(node->word, word);
                node->cnt++;
                TermCnt++;
            }
            /* printf("line =%s\nword =%s\n", line, word); */
        }

        if(line[0] == '-'){
            /* if(parseline(line, word) == FAILED){ */
            /*     continue; */
            /* } */
            for(node=head; node->next != NULL; node=node->next){
                if(strcmp(node->word, word) == 0){
//                    printf("%d\n", node->cnt);
                    if(node->cnt <= 0){
                        printf("%s is not in list\n", node->word);
                        FoundOne = SUCCESS;
                        break;
                    }
                    node->cnt--;
                    break;
                }
            }
            if(node->next == NULL)
                printf("%s is not in list\n", word);
//            printf("%s\n", node->word);
            /* if(node->next == NULL && node->word[0] == '\0') */
            /*     printf("%s is not in list\n", word); */

        }

        if(line[0] == '?'){
            for(node=head; node->next != NULL; node=node->next){
                if(strcmp(node->word, word) == 0){
                    if(node->cnt <= 0){
                        printf("No result\n");
                        break;
                    }
                    else{
                        printf("%d\t%s\n", node->cnt, node->word);
                        break;
                    }

                }
            }
            if(node->next == NULL){
                printf("No result\n");
            }

        }

    }

    qsort(head, TermCnt, sizeof(struct words *), compareint);
    /* qsort(head, TermCnt, sizeof(struct words *), compareline); */


//    printf("%d\n", TermCnt);
    /* for(i=0; i<TermCnt-1; i++){ */
    /*     node = head; */
    /*     for(j=0; node->next != NULL && j<TermCnt-1-i; j++, node=node->next){ */
    /*             printf("ha\n"); */
    /*         if(node->cnt < node->next->cnt && node->next != NULL){ */
    /*             int tmp; */
    /*             char *tmpline; */
    /*             tmp = node->cnt; */
    /*             strcpy(tmpline, node->word); */
    /*             node->cnt = node->next->cnt; */
    /*             strcpy(node->word, node->next->word); */
    /*             node->next->cnt = tmp; */
    /*             strcpy(node->next->word, tmpline); */
    /*         } */
    /*     } */
    /* } */



    /* for(i=0; i<TermCnt-1; i++){ */
    /*     node = head; */
    /*     for(j=0; node->next != NULL && j<TermCnt-1-i; j++, node=node->next){ */
    /*         if(strcmp(node->word, node->next->word) > 0 && node->cnt == node->next->cnt){ */
    /*             int tmp; */
    /*             char *tmpline; */
    /*             tmp = node->cnt; */
    /*             strcpy(tmpline, node->word); */
    /*             node->cnt = node->next->cnt; */
    /*             strcpy(node->word, node->next->word); */
    /*             node->next->cnt = tmp; */
    /*             strcpy(node->next->word, tmpline); */
    /*         } */
    /*     } */
    /* } */

    /* for(i=0; i<TermCnt-1; i++){ */
    /*     node = head; */
    /*     for(j= */

    /* } */


    for(node=head; node->next!=NULL; node=node->next){
        if(node->cnt <= 0)
            continue;
        else
            printf("%d\t%s\n", node->cnt, node->word);
    }
    

}


