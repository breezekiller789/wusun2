#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#define MaxLine 1024

void mymerge(char arr[100][100],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}

void mymergesort(char words[100][100], int front, int end){
    if(front < end){
        int mid = front + (end - front)/2;
        mymergesort(words, front, mid);
        mymergesort(words, mid+1, end);
        mymerge(words, front, mid, end);
    }
}

int main(int argc, char *argv[]){

    int *arr, j;
    char words[100][100];

    arr = (int *)malloc(sizeof(int) * 1000);
    /* srand(time(NULL)); */

    for(int i=0; i<100; i++){
        for(j=0; j<99; j++){
            words[i][j] = 'a' + rand()%26;
        }
        words[i][j] = '\0';
        /* printf("%s\n", words[i]); */
    }

    mymergesort(words, 0, 100-1);

    /* printf("%s\n", words[0]); */
    for(int i=0; i<100; i++){
        printf("%s\n", words[i]);
    }
    

    return 0;
}
