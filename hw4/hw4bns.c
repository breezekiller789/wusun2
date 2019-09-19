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

void Put_In_Array(struct words *head, struct words *array){
    struct words *node;
    int i=0;
    node = head;
    while(node != NULL){
        array[i] = *node;
        node = node->next;
        i++;
    }
}

int main(){
    char line[MaxLine];
    char word[MaxLine];
    int i, TermCnt=0;
    short FoundOne;
    struct words *head;  
    struct words *node;
    struct words *follow;
    head = NewNode();
    node = head;

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        FoundOne = FAILED;
        if(parseline(line, word) == FAILED){
            continue;
        }
        if(line[0] == '+'){
            for(node=head; node->next != NULL; node=node->next){
                if(strcmp(node->word, word) == 0){
//                    printf("%s\n", word);
                    node->cnt++;
//                    printf("%d\n", node->cnt);
                    break;
                }
            }
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
    /* printf("TermCnt = %d\n", TermCnt); */
    struct words array[TermCnt];
    Put_In_Array(head, array);
    printf("Hello\n");
    printf("array[0] = %d\t%s\n", array[0].cnt, array[0].word);
    i=0;
    while(array[i].next != NULL){
        printf("%d\t%s\n", array[i].cnt, array[i].word);
        i++;
    }

    /* for(node=head; node->next!=NULL; node=node->next){ */
    /*     if(node->cnt <= 0) */
    /*         continue; */
    /*     else */
    /*         printf("%d\t%s\n", node->cnt, node->word); */
    /* } */
    

}


