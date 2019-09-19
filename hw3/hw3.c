#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MaxName 64 
#define MaxPhone 32 
#define MaxEmail 128 
#define MaxStuCnt 10000 
#define MaxLine 1024 
#define FAILED 0 
#define SUCCESS 1 
#define ALLGET 3

struct addr { 
    char name[MaxName]; 
    char phone[MaxPhone]; 
    char email[MaxEmail]; 
    struct addr *next;
};//addrbooktmp;

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
}

void swap(short *order, int x, int y){
    int tmp;
    tmp = order[x];
    order[x] = order[y];
    order[y] = tmp;
}

int parseline(char *line, char *name, char *phone, char *email) 
{ 
    char *ptr, *qtr, *itr; 
    short getname, getphone, getemail;
    short i; 
    getname = getphone = getemail = FAILED;


    //Remove newline
    ptr = line; 
    while(*ptr != '\n' && *ptr != '\0') { ptr++; } 
    if(*ptr == '\n') *ptr = '\0'; 

    //get name
    for(i=0; i<ALLGET; i++){
        if((ptr = strstr(line, "n:")) && getname == FAILED){
//            printf("oh hi name\n");
            qtr = name; 
            if(*ptr == 'n')    
                ptr++;         
            if(*ptr == ':')     
                ptr++;
            while(*ptr != '\t' && *ptr != '\0') { 
                *qtr++ = *ptr++; 
            } 
            *qtr = '\0'; 
            getname = SUCCESS;
            continue;
            /* if(*ptr != '\t' || *ptr == '\n') return FAILED; */ 
            /* else { ptr++; } */ 
        }

        //get phone
        if((ptr = strstr(line, "p:")) && getphone == FAILED){
//            printf("oh hi phone\n");
            qtr = phone; 
            if(*ptr == 'p')
                ptr++;
            if(*ptr == ':')
                ptr++;
            while(*ptr != '\t' && *ptr != '\0') { 
                *qtr++ = *ptr++; 
            } 
            *qtr = '\0'; 
            getphone = SUCCESS;
            continue;
        }

        //get email
        if((ptr = strstr(line, "e:")) && getemail == FAILED){
//            printf("oh hi email\n");
            qtr = email; 
            if(*ptr == 'e')
                ptr++;
            if(*ptr == ':')
                ptr++;
            while(*ptr != '\t' && *ptr != '\0') { 
                *qtr++ = *ptr++; 
            } 
            *qtr = '\0'; 
            getemail = SUCCESS;
            continue;
        }
    }
    return SUCCESS; 
} 

struct addr *NewNode(){
    struct addr *node;
    node = (struct addr*) malloc(sizeof(struct addr));
    node->next = NULL;
    return node;
}

int main() 
{ 
    struct addr *head;
    struct addr *node;
    struct addr *addrtmp;
    struct addr *addrptr;
    struct addr *follow;
    struct addr addrbook[MaxStuCnt]; 
    char line[MaxLine], *ptr; 
    char name[MaxName], phone[MaxPhone], email[MaxEmail]; 
    int addrCnt = 0; 
    int i, j;
    short order[MaxStuCnt], IsSorted=FAILED;

    head = NewNode();
    head->next = NewNode();
    node = head;

    for(i=0; i<MaxStuCnt; i++)
        order[i] = i;

    while(fgets(line, MaxLine, stdin) != NULL) { 
        rmnewline(line);
        ptr = line;
        /* if(line[0] == 's' && IsSorted == FAILED){ */
        /*     IsSorted = SUCCESS; */
        /*     for(i=0; i<addrCnt-1; i++){ */
        /*         for(j=0; j<addrCnt-i-1; j++){ */
        /*             if(strcmp(addrbook[j].name, addrbook[j+1].name) > 0){ */
        /*                 swap(order, j, j+1); */
        /*                 char CopyTmp[MaxLine]; */
        /*                 strcpy(CopyTmp, addrbook[j].name); */
        /*                 strcpy(addrbook[j].name, addrbook[j+1].name); */
        /*                 strcpy(addrbook[j+1].name, CopyTmp); */
        /*             } */
        /*         } */
        /*     } */
        /*     continue; */
        /* } */

        if(line[0] == 'i'){
            node->next = NewNode();
            name[0] = phone[0] = email[0] = '\0';
            if(parseline(&line[2], name, phone, email) == FAILED){
                continue;
            }
            strcpy(node->name, name); 
            strcpy(node->phone, phone); 
            strcpy(node->email, email); 
            addrCnt++; 
            node = node->next;
            continue;
        }
        if(line[0] == 'f'){
            addrtmp = head;
            for(i=0; i<addrCnt && addrtmp->next != NULL; i++){
                if(strcmp(addrtmp->name, &line[4]) == 0){
                    printf("%s\t%s\t%s\n", addrtmp->name, addrtmp->phone, addrtmp->email);
                }
                addrtmp = addrtmp->next;
            }
            continue;
        }
        if(line[0] == 'd'){
            addrptr = head;
            for(addrtmp = head; addrtmp != NULL; follow = addrtmp, addrtmp = addrtmp->next){
//                printf("%s\n", head->name);
                if(strcmp(addrtmp->name, &line[4]) == 0){
                    follow->next = addrtmp->next;
                    free(addrtmp);
                }

            }
            continue;
        }

        if(line[0] == 'p'){
                addrtmp = head;
                for(i=0; i<addrCnt && addrtmp->next !=NULL; i++) { 
                    if(addrtmp->name[0] == '\0')
                        continue;
                    printf("%s\t%s\t%s\n", addrtmp->name, addrtmp->phone, addrtmp->email);
                    /* if(IsSorted == FAILED) */
                    /*     printf("%s\t\%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email); */ 
                    /* else */
                    /*     printf("%s\t\%s\t%s\n", addrbook[i].name, addrbook[order[i]].phone, addrbook[order[i]].email); */ 
                    addrtmp = addrtmp->next;
                } 
            continue;
        }
        

    } 
    return 0;

}
