//  prog#2  //  addrbook,
//  due date:   2019/3/5
//  addrbook
//  supported operations
//  i       insert
//          e.g., f john 0912123123 john@gmail.com
//          基本要求：固定格式，name\tphone\temail
//          順序不限，也可以，p : 0912012012\te:jo@gt.co\tn:jo
//  p       print out the content
//  s       sort the content and output *   //bonus
//  f key   find matched addr records
//  d key   delete addr records according to key
//          e.g., d john
//          we assume that key is unique int the data
//
//  the program supports command line interaction
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

// insert a record into the addrbook array, by appending
// it to the tail of the array
// return the number of elements after insertion.
//int insert(struct addr *addbook, int cnt, char *name, char *phone, char *email){
//
////    ...
//    cnt++;
//    return cnt;
//
//}

//      find can have several versions:
//      find and print, 找到並印出
//      findall 找到match到得注標
//      findnext 找到下一筆符合的record之注標

/* int findall(struct addr *addrbook, int cnt, char *key, int *matchlist){ */
/*     if(strcmp(addrbook[i], key) == 0){ */
/*         matchlist[k] = i; */
/*         k++; */
/*     } */

/* } */

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
}


int parseline(char *line, char *name, char *phone, char *email) 
{ 
    char *ptr, *qtr; 

    //Remove newline
    ptr = line; 
    while(*ptr != '\n' && *ptr != '\0') { ptr++; } 
    if(*ptr == '\n') *ptr = '\0'; 

    //get name
    ptr = line; 
    qtr = name; 
    if(*ptr == 'n')    // 當遇上ｎ：就跳過去
        ptr++;         // 不然name會拿到n:name
    if(*ptr == ':')     
        ptr++;
    while(*ptr != '\t' && *ptr != ' ') { 
        *qtr++ = *ptr++; 
    } 
    *qtr = '\0'; 
    if(*ptr != '\t') return FAILED; 
    else { ptr++; } 

    //get phone
    if(*ptr == 'p'){
        ptr++;
        if(*ptr == ':')
            ptr++;
        qtr = phone; 
        while(*ptr != '\t' && *ptr != '\0') { 
            *qtr++ = *ptr++; 
        } 
        *qtr = '\0'; 
        if(*ptr != '\t') return SUCCESS; 
        else { ptr++; } 
    }

    //get email
    if(*ptr == 'e'){
        ptr++;
        if(*ptr == ':')
            ptr++;
        qtr = email; 
        while(*ptr != '\t' && *ptr != '\0') { 
            *qtr++ = *ptr++; 
        } 
        *qtr = '\0'; 
    }
    return SUCCESS; 
} 

/* void find(struct addr addrbook[MaxStuCnt], char *line, int addrCnt){ */
/*     int len, i; */
/*     len = strlen(line); */
/*     printf("len =%d\n", len); */
/*     for(i=0; i<addrCnt; i++){ */
/*         if(strncmp(addrbook[i].name, line) == 0) */
/*             printf("haha\n"); */

/*     } */
/* } */

int main() 
{ 
    struct addr { 
        char name[MaxName]; 
        char phone[MaxPhone]; 
        char email[MaxEmail]; 
    };//addrbooktmp;
    struct addr addrbook[MaxStuCnt]; 
//    struct addr *addrbookp; 
    struct addr *addrp; 
    struct addr tmpaddr;
    char line[MaxLine], *ptr; 
    char name[MaxName], phone[MaxPhone], email[MaxEmail]; 
    int addrCnt = 0; 
    int i; 

    while(fgets(line, MaxLine, stdin) != NULL) { 
        rmnewline(line);
        ptr = line;
        if(line[0] == 'i'){
            name[0] = phone[0] = email[0] = '\0';
            if(parseline(&line[2], name, phone, email) == FAILED){
                continue;
            }
            strcpy(addrbook[addrCnt].name, name); 
            strcpy(addrbook[addrCnt].phone, phone); 
            strcpy(addrbook[addrCnt].email, email); 
            /* printf("name =%s\n", name); */
            /* printf("phone =%s\n", phone); */
            /* printf("email =%s\n", email); */
            /* printf("addrbook[%d].name =%s\n", addrCnt, addrbook[addrCnt].name); */
            /* printf("addrbook[%d].phone =%s\n", addrCnt, addrbook[addrCnt].phone); */
            /* printf("addrbook[%d].email =%s\n", addrCnt, addrbook[addrCnt].email); */
            addrCnt++; 
        }
        if(line[0] == 'f'){
            /* printf("%s\n", &line[4]); */
            for(i=0; i<addrCnt; i++){
                /* printf("addrbook[%d].name =%s\n", i, addrbook[i].name); */
                /* printf("&line[4] =%s\n", &line[4]); */
                if(strcmp(addrbook[i].name, &line[4]) == 0){
                    printf("%s\t%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email);
                }
            }


        }
        if(line[0] == 'd'){
            for(i=0; i<addrCnt; i++){
                if(strcmp(addrbook[i].name, &line[4]) == 0){
                    addrbook[i].name[0] = addrbook[i].phone[0] = addrbook[i].email[0] = '\0';
                }
            }
        }

        if(line[0] == 'p'){
//            printf("addrCnt =%d\n", addrCnt);
            for(i=0; i<addrCnt; i++) { 
                if(addrbook[i].name[0] == '\0')
                    continue;
                printf("%s\t\%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email); 
            } 
        }


        /* if(parseline(line, name, phone, email) == FAILED) { */ 
        /*     continue; */ 
        /* } */ 
    } 
    /* printf("\tName\tPhone\t\tEmail\n"); */ 
    /* printf("---------------------------------------------------\n"); */ 
    /* for(i=0; i<addrCnt; i++) { */ 
    /*     printf("%s\t\%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email); */ 
    /* } */ 
    return 0;

}
