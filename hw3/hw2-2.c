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

void rmnewline(char *line){
    int i=0;
    while(line[i] != '\n')
        i++;
    line[i] = '\0';
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
int main() 
{ 
    struct addr { 
        char name[MaxName]; 
        char phone[MaxPhone]; 
        char email[MaxEmail]; 
    };//addrbooktmp;
    struct addr addrbook[MaxStuCnt]; 
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
//            printf("name=%s\tphone=%s\temail=%s\n", name, phone, email);
            strcpy(addrbook[addrCnt].name, name); 
            strcpy(addrbook[addrCnt].phone, phone); 
            strcpy(addrbook[addrCnt].email, email); 
            addrCnt++; 
            continue;
        }
        if(line[0] == 'f'){
            for(i=0; i<addrCnt; i++){
                if(strcmp(addrbook[i].name, &line[4]) == 0){
                    printf("%s\t%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email);
                }
            }
            continue;
        }
        if(line[0] == 'd'){
            for(i=0; i<addrCnt; i++){
                if(strcmp(addrbook[i].name, &line[4]) == 0){
                    addrbook[i].name[0] = addrbook[i].phone[0] = addrbook[i].email[0] = '\0';
                }
            }
            continue;
        }

        if(line[0] == 'p'){
            for(i=0; i<addrCnt; i++) { 
                if(addrbook[i].name[0] == '\0')
                    continue;
                printf("%s\t\%s\t%s\n", addrbook[i].name, addrbook[i].phone, addrbook[i].email); 
            } 
            continue;
        }


    } 
    return 0;

}
