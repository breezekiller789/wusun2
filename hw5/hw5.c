#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#define MaxLine 1024
#define NotFound -1
#define FoundIt 1
int cnt=0;
struct lnode{
    char *data;
    int idx;
    struct lnode *right;
    struct lnode *left;
};

struct lnode *NewNode(){
    struct lnode *node;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->idx = 0;
    node->right = NULL;
    node->left = NULL;
    return node;
};

struct lnode *BST_Insert(struct lnode *tp, char *key){
    if(tp == NULL){
        tp = NewNode();
        tp->data = (char *)malloc(sizeof(char) * strlen(key));
        strcpy(tp->data, key);
        tp->idx++;
        tp->right = NULL;
        tp->left = NULL;
        return tp;
    }
    if(strcmp(tp->data, key) > 0){
        tp->left = BST_Insert(tp->left, key);
    }
    else if(strcmp(tp->data, key) < 0){
        tp->right = BST_Insert(tp->right, key);
    }
    else if(strcmp(tp->data, key) == 0){
        tp->idx++;
        return tp;
    }
    return tp;
};
void Put_In_Array(struct lnode *tp, struct lnode array[100]){
    if(tp == NULL)
        return;
    Put_In_Array(tp->left, array);
    array[cnt++] = *tp;
    /* printf("%s\t%d\n", tp->data, tp->idx); */
    Put_In_Array(tp->right, array);
};

void BST_Find(struct lnode *tp, char *line){
    if(tp == NULL){
        printf("error\n");
        return;
    }
    if(strcmp(tp->data, line) > 0){
        BST_Find(tp->left, line);
    }
    else if(strcmp(tp->data, line) == 0){
        if(tp->idx == 0)
            printf("error\n");
        else
            printf("%s\t%d\n", tp->data, tp->idx);
    }
    else if(strcmp(tp->data, line) < 0){
        BST_Find(tp->right, line);
    }
}

void BST_Delete(struct lnode *tp, char *line){
    if(tp == NULL){
        return;
    }
    if(strcmp(tp->data, line) > 0){
        BST_Delete(tp->left, line);
    }
    else if(strcmp(tp->data, line) < 0){
        BST_Delete(tp->right, line);
    }
    else if(strcmp(tp->data, line) == 0){
        if(tp->idx == 0)
            return;
        else
            tp->idx--;
        return;
    }
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int mycompar(const void *p, const void *q){
    struct lnode *x, *y;
    x = (struct lnode *)p;
    y = (struct lnode *)q;
    /* printf("%s\t%s", x->data, y->data); */
    return y->idx - x->idx;
}

int mycompardata(const void *p, const void *q){
    struct lnode *x, *y;
    x = (struct lnode *)p;
    y = (struct lnode *)q;
    return strcmp(x->data, y->data);
}

int main(int argc, char *argv[]){

    struct lnode *root, *node;
    struct lnode array[100];
    char *line, *ptr;
    FILE *fp;
    line = (char *)malloc(sizeof(char) * MaxLine);
    root = NULL;

    fp = fopen(argv[2], "r");

    if(strcmp(argv[1], "-f") == 0){
        while(fgets(line, MaxLine, fp) != NULL){
            rmnewline(line);
            root = BST_Insert(root, line);
        }
        Put_In_Array(root, array);
        qsort(array, cnt, sizeof(struct lnode), mycompar);
        int tmp=0, i=0, num=0, num1;
        num1 = array[0].idx; 
        while(1){
            while(num1 == array[i].idx){
                i++;
                if(i==cnt)
                    break;
            }
            qsort(&array[num], i-num, sizeof(struct lnode), mycompardata);
            num = i;
            i++;
            num1 = array[i].idx;
            if(i>=cnt)
                break;
        }
        for(int i=0; i<cnt; i++){
            printf("%s\t%d\n", array[i].data, array[i].idx);
        }
    }
    else if(strcmp(argv[1], "-s") == 0){
        while(fgets(line, MaxLine, fp) != NULL){
            rmnewline(line);
            ptr = line;
            ptr++;
            while(isspace(*ptr)){
                ptr++;
            }
            if(*line == 'i'){
                root = BST_Insert(root, ptr);
            }
            else if(*line == 'f'){
                BST_Find(root, ptr);
            }
            else if(*line == 'd'){
                BST_Delete(root, ptr);
            }
            else if(*line == 'p'){
                int tmp=0, i=0, num=0, num1;
                Put_In_Array(root, array);
                qsort(array, cnt, sizeof(struct lnode), mycompar);
                num1 = array[0].idx; 
                while(1){
                    while(num1 == array[i].idx){
                        i++;
                        if(i==cnt)
                            break;
                    }
                    qsort(&array[num], i-num, sizeof(struct lnode), mycompardata);
                    num = i;
                    i++;
                    num1 = array[i].idx;
                    if(i>=cnt)
                        break;
                }
                for(int i=0; i<cnt; i++){
                    if(array[i].idx <= 0)
                        continue;
                    printf("%s\t%d\n", array[i].data, array[i].idx);
                }
                cnt=0;
            }
            else{
                continue;
            }

        }


    }
    else{
        return 0;
    }

    return 0;
}
