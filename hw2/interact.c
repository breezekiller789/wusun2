#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLine 1024

int main(){
    char line[MaxLine];
    while(1){
        printf(">");
        fgets(line, MaxLine, stdin);
        if(strncmp(line, "quit", 4) == 0)
            exit(0);//  通常exit(1)代表不正常結束，這裡用break也可以
        if(line[0] == 'i'){
            printf("insert\n");
            //  insert(line, addrbook);
            continue;
        }
        if(line[0] == 'd'){
            printf("delete\n");
            continue;
        }
        if(line[0] == 'f'){
            printf("find\n");
            continue;
        }
        else{
            printf("unknown\n");
            continue;
        }


    }




}
