#include <stdio.h>

int main(){
    long cnt=0;
    int c;
    while((c=getchar()) != EOF){
        cnt++;
    }
    printf("%ld\n", cnt);
    return 0;

}
