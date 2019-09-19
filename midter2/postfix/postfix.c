#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int idx = -1;

void push(float *stack, float val){
    stack[++idx] = val;
}

float pop(float *stack){
    return stack[idx--];   
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    char *line, *ptr, *qtr;
    int val;
    float stack[100];
    float val1, val2, val3;

    line = (char *)malloc(sizeof(char) * MaxLine);

    for(int i=0; i<100; i++){
        stack[i] = 0;
    }

    while(fgets(line, MaxLine, stdin)){
        rmnewline(line);
        ptr = line;
        while(1){
            /* for(int i=0; i<=idx; i++) */
            /*     printf("%f ", stack[i]); */
            /* printf("\n"); */
            if(isdigit(*ptr)){
                val = atoi(ptr);
                /* printf("push %d\n", val); */
                push(stack, val);
                while(isdigit(*ptr)){
                    ptr++;
                }
                ptr++;
                continue;
            }
            else if(*ptr == '-'){
                qtr = ptr;
                qtr++;
                if(isdigit(*qtr)){
                    val = atoi(ptr);
                    /* printf("%d\n", val); */
                    push(stack, val);
                    ptr++;
                    while(isdigit(*ptr)){
                        ptr++;
                    }
                    ptr++;
                    continue;
                }
                else{
                    val1 = pop(stack);
                    val2 = pop(stack);
                    val3 = val2 - val1;
                    push(stack, val3);
                    ptr += 2;
                }
            }
            else if(*ptr == '\0'){
                break;
            }
            else{
                val1 = pop(stack);
                val2 = pop(stack);
                /* printf("val1 = %f\tval2 = %f\n", val1, val2); */
                /* printf("*ptr = %c\n", *ptr); */
                switch(*ptr){
                    case '+':
                    {
                            val3 = val1 + val2;
                            break;
                    }
                    case '-':
                    {
                            val3 = val2 - val1;
                            break;
                    }
                    case '*':
                    {
                            val3 = val2 * val1;
                            break;
                    }
                    case '/':
                    {
                            val3 = val2 / val1;
                            break;
                    }
                }
                push(stack, val3);
                ptr += 2;
            }
        }
        float a = stack[0];
        a = (float)(((a * 100) + 0.5) / 100);
        printf("%.1f\n", a);

    }
    return 0;
}
