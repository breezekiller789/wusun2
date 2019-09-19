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

void push(float *val, float *stack){
    stack[++idx] = *val;
}

float pop(float *stack){
    float ret;
    ret = stack[idx--];
    return ret;
}

int main(int argc, char *argv[]){
    
    char line[MaxLine];
    char *ptr, *qtr;
    int  *itr, i;
    float value3, value1, value2, value, stack[MaxLine];

    fgets(line, MaxLine, stdin);
    rmnewline(line);
    ptr = line;
    while(1){
        if(isdigit(*ptr) || *ptr == '-'){
            qtr = ptr;      //這樣寫是要針對有負數運算元的情況
            qtr++;
            if(isdigit(*ptr)){
                value = atoi(ptr);
                push(&value, stack);
                while(isdigit(*ptr))
                    ptr++;
                ptr++;
                continue;
            }
            else if(isdigit(*qtr)){
                value = atoi(ptr);
                push(&value, stack);
                while(isdigit(*qtr))
                    qtr++;
                qtr++;
                ptr = qtr;
                continue;
            }
            else if(*ptr == '-' && !isdigit(*qtr) ){
                value1 = pop(stack);
                value2 = pop(stack);
                /* printf("val1 = %.1f\n", value1); */
                /* printf("val2 = %.1f\n", value2); */
                value3 = value2 - value1;
                push(&value3, stack);
                /* printf("stack[0] = %f\nstack[1] = %f\nstack[2] = %f\n", stack[0], stack[1], stack[2]); */
                ptr += 2;
                continue;
            }
        }
        else if(*ptr == '\0')
            break;
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
                    value3 = value1 - value2;
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
            push(&value3, stack);
            ptr += 2;
        }
    }
    float f = stack[0];
    /* printf("%f\n", stack[0]); */
    float a = (float)(((f * 100) + 0.5) / 100);
    printf("%.1f\n", a);
    /* printf("%.1f\n", stack[0]); */
    /* int x; */
    /* float y, error; */
    /* x = (int)stack[0]; */
    /* y = stack[0] - x; */
    /* y = y * 10; */
    /* error = */ 
    /* if(y >= 0.5){ */
    /*     x += 1; */
    /*     printf("%.1f\n", (float)x); */
    /* } */
    /* else */
    /*     printf("%.1f\n", stack[0]); */

    return 0;
}
