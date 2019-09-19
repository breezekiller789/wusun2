#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLine 1024

struct words{
    char word[MaxLine];
    struct words *next;
};

struct words *NewNode(){
    struct words *node;
    node = (struct words *)malloc(sizeof(struct words));
    node->next = NULL;
    return node;
}

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
}

int MystrCmp(const void *p, const void *q){
    char **x = (char **) p;
    char **y = (char **) q;
    return strcmp(*x, *y);
}

int main(){
    struct words *head;
    struct words *node;
    char line[MaxLine];
    char *lines[MaxLine];
    int i, TermCnt=0;
    head = NewNode();
    node = head;

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        for(node=head; node->next != NULL; node = node->next){
            if(strcmp(node->word, line) == 0){
                break;
            }
        }
        if(node->next == NULL){
            node->next = NewNode();
            strcpy(node->word, line);
            TermCnt++;
        }

    }
    int idx = 0;
    for(node=head; node->next != NULL; node = node->next){
        /* printf("%s\n", node->word); */
        strcpy(line, node->word);
        lines[idx] = strdup(line);
        /* printf("%s\n", lines[idx]); */
        idx++;
    }
    qsort(lines, idx, sizeof(char *), MystrCmp);
    for(i=0; i<idx; i++)
        printf("%s\n", lines[i]);

    /* qsort(head, TermCnt, sizeof(struct words *), MyStrCmp); */
    /* for(node=head; node->next != NULL; node = node->next) */
    /*     printf("%s\n", node->word); */



}

