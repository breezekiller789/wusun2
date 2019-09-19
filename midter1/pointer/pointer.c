#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 100000
#define FAILED -1
#define SUCCESS 1
#define GotLineNum 2

int linenum;

struct words{
    char *word;
    struct words *next;
    struct words *prev;
};

struct words *NewNode(){
    struct words *node;
    node = (struct words *)malloc(sizeof(struct words));
    node->next = NULL;
    return node;
};


void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int getinput(char *bufline, long *linelen, char *line, struct words *node){
    char *ptr, *input;
    ptr = bufline;
    if(isdigit(*ptr)){
        linenum = atoi(ptr);
        /* printf("linenum = %d\n", linenum); */
        return GotLineNum;
    }
    else{
        if((ptr = strstr(bufline, "INSERT "))){
            ptr += strlen("INSERT ");
            *linelen = atol(ptr);
            /* printf("linelen = %d\n", *linelen); */
            long len = *linelen;
            input = (char *)malloc(sizeof(char) * len);
            fgets(input, len+1, stdin);
            line = strdup(input);
            rmnewline(line);
            /* printf("line = %s\n", line); */
            node->word = (char *)malloc(sizeof(char) * linenum);
            strcpy(node->word, line);
            /* printf("%s\n", line); */
        }
        else
            return FAILED;
    }
    return SUCCESS;
}

int main(int argc, char *argv[]){
    char *line, *bufline, **ptr;
    int linecnt=0, val;
    long linelen;
    struct words *head, *node;

    head = NewNode();
    head->next = NewNode();
    head->prev = NULL;
    node = head->next;
    node->prev = head;

    line = (char *)malloc(sizeof(char) * MaxLine);
    bufline = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(bufline, MaxLine, stdin) != NULL){
        rmnewline(bufline);
        if(*bufline == '\0')        //不懂為啥會需要加這兩行...
            continue;
        /* printf("bufline = %s\n", bufline); */
        if(strcmp(bufline, "OUTPUT") == 0)
            break;
        if((val = getinput(bufline, &linelen, line, node)) == FAILED){
            continue;
        }
        if(val == GotLineNum)
            continue;
        node->next = NewNode();
        node->next->prev = node;
        node = node->next;
        /* printf("%s\n", line); */
        /* node->word = (char *)malloc(sizeof(char) * linelen); */
        /* strcpy(node->word, line); */
        /* node->next = NewNode(); */
        /* node = node->next; */
        /* bufline = (char *)malloc(sizeof(char) * MaxLine); */
        /* printf("%s\n", *line); */
    }
    /* for(node = head; node->next != NULL; node = node->next){ */
    /*     printf("%s\n", node->word); */
    /* } */
    for(node = node->prev; node->prev != NULL; node = node->prev){
        printf("%s\n", node->word);
    }
    /* struct words *current, *prev, *next; */
    /* current = head; */
    /* while(current != NULL){ */
    /*     next = current->next; */
    /*     current->next = prev; */
    /*     prev = current; */
    /*     current = next; */
    /* } */





    return 0;
}
