#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int idx = -1;

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

void push(float *stack, float value){
    stack[++idx] = value;
}

float pop(float *stack){
    float returnval;
    returnval = stack[idx--];
    return returnval;
}

int main(int argc, char *argv[]){
    char *line, *bufline, *ptr, *qtr;
    int i;
    float stack[MaxLine], value, value1, value2, value3;

    for(i=0; i<MaxLine; i++)
        stack[i] = 0;

    line = (char *)malloc(sizeof(char) * MaxLine);

    fgets(line, MaxLine, stdin);
    rmnewline(line);

    ptr = line;

    while(1){
        qtr = ptr;
        qtr++;
        if(isdigit(*ptr)){
            value = atoi(ptr);
            push(stack, value);
            while(isdigit(*ptr)){
                ptr++;
            }
            ptr++;
            continue;
        }
        else if(*ptr == '-' && isdigit(*qtr)){
            value = atoi(ptr);
            push(stack, value);
            while(isdigit(*qtr)){
                qtr++;
            }
            qtr++;
            ptr = qtr;
            continue;
        }
        else if(*ptr == '\0'){
            break;
        }
        else{
            value1 = pop(stack);
            value2 = pop(stack);
            switch(*ptr){
                case '+':
                {
                    value3 = value1 + value2;
                    break;
                }
                case '-':
                {
                    value3 = value2 - value1;
                    break;
                }
                case '*':
                {
                    value3 = value1 * value2;
                    break;
                }
                case '/':
                {
                    value3 = value2 / value1;
                    break;
                }
            }
            ptr += 2;
            push(stack, value3);
        }
    }
    float f = stack[0];
    float a = (float) ((((f * 100) + 0.5) / 100));
    printf("%.1f\n", a);
    return 0;
}
