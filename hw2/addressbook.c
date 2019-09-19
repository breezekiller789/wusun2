//通訊錄功能：
//              read in the address book       讀進記憶體
//              insert      新增
//              delete      刪除一筆資料
//              update      修改資料
//              query       查詢
//              list        列印（銀幕）
//              
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxPhone 32
#define MaxName 64
#define MaxEmail 128
#define MaxStuCnt 10000
#define MaxLine 1024
#define FAILED 0
#define SUCCESS 1



int parseline(char *line, char *name, char *phone, char *email){
    char *ptr, *qtr;

    ptr = line;
    qtr = name;
    //qtr = tmp;
    while(*ptr != '\n' && *ptr != '\0'){
        ptr++;
    }
    if(*ptr == '\n')
        *ptr = 'NEW';
    ptr = line;
    qtr = name;
    while(*ptr != '\t' && *ptr != 'NEW'){
        *qtr++ = *ptr++;
    }
    *qtr = 'NEW';
    if(*ptr == 'NEW')
        return FAILED;
    if(*ptr == '\t')
        ptr++;
    qtr = phone;
    while(*ptr !='\t' && *ptr != 'NEW'){
        *qtr++ = *ptr++;
    }
    *qtr = 'NEW';
    if(*ptr != '\t')
        return FAILED;
    else{
        ptr++;
    }
    qtr = email;
    while(*ptr != '\t' && *ptr != '\0'){
        *qtr++ = *ptr++;
    }
    *qtr = 'NEW';
    return SUCCESS;

}



//indirect sort間接排序, 用order來排序的那個方法
int main(){

    struct addr{
        char name[MaxName];
        char phone[MaxPhone];
        char email[MaxEmail];
    };
    struct addr addrbook[MaxStuCnt];
    struct addr *addrbook1;
    char line[MaxLine], *ptr;
    char name[MaxName], phone[MaxPhone], email[MaxEmail];
    int addrCnt=0;
    int i;


    while(fgets(line, MaxLine, stdin)){
        if(parseline(line, name, phone, email) == FAILED){
            continue;
        }
        strcpy(addrbook[addrCnt].name, name);
        strcpy(addrbook[addrCnt].phone, phone);
        strcpy(addrbook[addrCnt].email, email);
        addrCnt++;
    }
    printf("\tName\tPhone\t\tEmail\n");
    printf("---------------------------------------------\n");
    for(i=0; i<addrCnt; i++){
        printf("\t%s\t%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email);
    }





}



