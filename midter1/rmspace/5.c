#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MaxLine 1024
#define FAILED -1
#define SUCCESS 1

int rmnewline(char *line){
    int i=0;
    while(line[i] != '\n' || line[i] == '\0')
        i++;
    line[i] = '\0';
    return i;
}



int main(){
    char line[MaxLine], finalline[MaxLine];
    /* int i = isspace('\n'); */
    /* printf("%d\n", i); */
    char *ptr, *qtr;
    int i, len, HasSpace, StartWithSpace, idx;
    while(fgets(line, MaxLine, stdin) != NULL){
        len = rmnewline(line);
        ptr = line;
        StartWithSpace = FAILED;
        for(i=0; i<len; i++){
            HasSpace = FAILED;
            while(*ptr == ' '){
                if(i==0)
                    StartWithSpace = SUCCESS;
                HasSpace = SUCCESS;
                ptr++;
            }
            while(*ptr != ' ' && *ptr != '\0'){
                char *itr = ptr;
                char *ltr;
                while(isspace(*itr) && *itr != '\0')
                    itr++;
                if(*itr == '\0')
                    break;
                printf("%c", *ptr);
                ptr++;
                ltr = ptr;
                while(isspace(*ltr) && *ltr != '\0')
                    ltr++;
                if(*ltr == '\0')
                    break;
                if(isspace(*ptr))
                    printf(" ");
            }
        }
        /* if(line[0] == '\0') */
        /*     continue; */
        printf("\n");
        


    }



    return 0;


}


