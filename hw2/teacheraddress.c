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


int parseline(char *line, char *name, char *phone, char *email) 
{ 
    char *ptr, *qtr; 

    ptr = line; 
    while(*ptr != '\n' && *ptr != '\0') { ptr++; } 
    if(*ptr == '\n') *ptr = '\0'; 

    ptr = line; 
    qtr = name; 
    while(*ptr != '\t' && *ptr != ' ') { 
        *qtr++ = *ptr++; 
    } 
    *qtr = '\0'; 
    if(*ptr != '\t') return FAILED; 
    else { ptr++; } 
    qtr = phone; 
    while(*ptr != '\t' && *ptr != '\0') { 
        *qtr++ = *ptr++; 
    } 
    *qtr = '\0'; 
    if(*ptr != '\t') return FAILED; 
    else { ptr++; } 
    qtr = email; 
    while(*ptr != '\t' && *ptr != '\0') { 
        *qtr++ = *ptr++; 
    } 
    *qtr = '\0'; 
    return SUCCESS; 
} 

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

/*
    strcpy(tmpaddr.phone, "0982123123");
    strcpy(tmpaddr.name, "john");
    strcpy(tmpaddr.email, "john@gmail.com");

    addrp = &tmpaddr;

    printf("%s\t%s\t%s\n", tmpaddr.name, tmpaddr.phone, tmpaddr.email);
    addrp = (struct addr *) malloc(sizeof(struct addr));
    strcpy(addrp->name, "mary");
    strcpy(addrp->phone, "0982123123");
    strcpy(addrp->email, "mary@gmail.com");
    printf("%s\t%s\t%s\n", addrp -> name, addrp -> phone, addrp -> email);

    exit(1);
*/

    while(fgets(line, MaxLine, stdin) != NULL) { 
        if(parseline(line, name, phone, email) == FAILED) { 
            continue; 
        } 
//        printf("name=%s\tphone=%s\temail=%s\n", name, phone, email);
        strcpy(addrbook[addrCnt].name, name); 
        strcpy(addrbook[addrCnt].phone, phone); 
        strcpy(addrbook[addrCnt].email, email); 
//        printf("name=%s\tphone=%s\temail=%s\n", addrbook[addrCnt].name, addrbook[addrCnt].phone, addrbook[addrCnt].email);
        addrCnt++; 
    } 
    printf("\tName\tPhone\t\tEmail\n"); 
    printf("---------------------------------------------------\n"); 
    for(i=0; i<addrCnt; i++) { 
        printf("\t%s\t\%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email); 
    } 
    return 0;

}
