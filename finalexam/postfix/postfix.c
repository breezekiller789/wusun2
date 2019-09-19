#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxLine 1024

int idx = -1;

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

float pop(float *stack){
    float ret;
    ret = stack[idx--];
    return ret;
}

void push(float *stack, float val){
    stack[++idx] = val;
}

int main(int argc, char *argv[]){

    char line[MaxLine];
    char *ptr, *qtr;
    float stack[100], val, val1, val2, val3;
    for(int i=0; i<100; i++)
        stack[i] = 0;       //  Initialize

    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        while(1){
            if(isdigit(*ptr)){
                val = atoi(ptr);
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
                switch(*ptr){
                    case '+':
                    {
                        val3 = val2 + val1;
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
        a = (((a * 100) + 0.5) / 100);
        printf("%.1f\n", a);
        idx--;
    }

    return 0;
}
