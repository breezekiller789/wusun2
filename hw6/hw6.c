#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#define OFFSET 1
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
#define MaxLine 1024
#define FALSE -1
#define TRUE 1
//radix sort 無法排序字串QQ
int Minusn, MinusN, Minusw, Minusm, Minusa, Auto;
int Qsort, Mergesort, Heapsort, Radixsort;
int NumberOfElement, WordLengh, MaxValue, AlphabetSetSize;
int *array;
char **words;
int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }
void heapSort(int*, int len, int(*)(int, int));
void heapTree(int*, int, int(*)(int, int));
void selectFromHeap(int*, int, int(*)(int, int));

void bubbleLeaf(int*, int, int(*)(int, int));
int isBubbleable(int*, int, int, int(*)(int, int));

void bubbleRoot(int*, int, int(*)(int, int));
int idxFromChilds(int*, int, int, int(*)(int, int));
int isRightLeafSuitable(int*, int, int, int(*)(int, int));

void print(int*, int len);
int ascending(int, int);
int descending(int, int);

void initialize(){
    Minusn = MinusN = Minusw = Minusm = Minusa = Auto = FALSE;
    Qsort = Mergesort = Heapsort = Radixsort = FALSE;   
    NumberOfElement = 100;
    WordLengh = 10;
    MaxValue = 10000;
    AlphabetSetSize = 26;
}

void parseline(int argc, char **argv){
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-n") == 0){
            Minusn = TRUE;
        }
        else if(strcmp(argv[i], "-N") == 0){
            MinusN = TRUE;
            NumberOfElement = atoi(argv[i+1]);
            i++;
        }
        else if(strcmp(argv[i], "-w") == 0){
            Minusw = TRUE;
            WordLengh = atoi(argv[i+1]);
            i++;
        }
        else if(strcmp(argv[i], "-m") == 0){
            Minusm = TRUE;
            MaxValue = atoi(argv[i+1]);
            i++;
        }
        else if(strcmp(argv[i], "-a") == 0){
            Minusa = TRUE;
            AlphabetSetSize = atoi(argv[i+1]);
            i++;
        }
        else if(strcmp(argv[i], "-auto") == 0){
            Auto = TRUE;
            NumberOfElement = 100;
            WordLengh = 10;
            MaxValue = 10000;
            AlphabetSetSize = 26;
        }
        else if(strcmp(argv[i], "-qsort") == 0){
            Qsort = TRUE;
        }
        else if(strcmp(argv[i], "-msort") == 0){
            Mergesort = TRUE;
        }
        else if(strcmp(argv[i], "-hsort") == 0){
            Heapsort = TRUE;
        }
        else if(strcmp(argv[i], "-rsort") == 0){
            Radixsort = TRUE;
        }
        else{
            printf("Usage :\n-n (string or integers)\n");
            printf("-N <Number Of Elements>\n");
            printf("-w <Word Length>\n");
            printf("-m <Max Value>\n");
            printf("-a <Alphabe Set Size>\n");
            printf("-auto (default)\n");
            printf("-qsort or -msort\n");
            exit(1);
            /* return 0; */
        }
    }
}
void inputgenerator(){
    /* srand(time(NULL));  //如果要每次run time都有不一樣的測資，把這註解拿掉 */
    if(Minusn == TRUE){
        int i;
        int j;
        words = (char **)malloc(sizeof(char *) * NumberOfElement);
        for(i=0; i<NumberOfElement; i++){
            *(words+i) = (char *)malloc(sizeof(char) * WordLengh + 1);
        }
        for(i=0; i<NumberOfElement; i++){
            for(j=0; j<WordLengh; j++){
                words[i][j] = 'a'+(char)(rand() % AlphabetSetSize);
            }
            words[i][j] = '\0';
            /* printf("%s\n", *(words+i)); */
        }
    }
    else if(Minusn == FALSE){
        int i;
        array = (int *)malloc(sizeof(int) * NumberOfElement);
        for(i=0; i<NumberOfElement; i++){
            array[i] = (rand() % MaxValue) + 1;
            /* printf("%d\n", array[i]); */
        }
    }
    else
        printf("Generating Input Error!!\n");
}

void printarguments(){
    printf("-n : %d\n", Minusn);
    printf("-N : %d\t%d\n", MinusN, NumberOfElement);
    printf("-w : %d\t%d\n", Minusw, WordLengh);
    printf("-m : %d\t%d\n", Minusm, MaxValue);
    printf("-a : %d\t%d\n", Minusa, AlphabetSetSize);
    printf("-auto : %d\n", Auto);
}

int mycomparewords(const void *p, const void *q){
    char **x = (char **)p;
    char **y = (char **)q;
    return strcmp(*x, *y);
}
int mycomparearray(const void *p, const void *q){
    int *x = (int*)p;
    int *y = (int*)q;
    return *x - *y;
}

void rmnewline(char *line){
    char *ptr = line;
    while(*ptr && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

void printoutput(){
    int i;
    if(Minusn == TRUE){
        for(i=0; i<NumberOfElement; i++){
            printf("%s\n", *(words+i));
        }
    }
    else{
        for(i=0; i<NumberOfElement; i++){
            printf("%d\n", array[i]);
        }
    }
}

void myradixsort(){
    int **tmp;
    int order[10] = {0};
    long n=1;
    long numberofdigits=1;
    tmp = (int **)malloc(sizeof(int *) * 10);
    for(int j=0; j<10; j++)
        *(tmp+j) = (int *)malloc(sizeof(int) * NumberOfElement);
    /* 算出最多有幾位數。 */
    for(int i=0; i<WordLengh; i++){
        numberofdigits *= 10;
        /* printf("%ld\n", numberofdigits); */
    }
    while(n<=numberofdigits){
        /* printf("%ld\n", n); */
        int i;
        for(i=0; i<NumberOfElement; i++){
            int leastdigit = (array[i]/n)%10;
            tmp[leastdigit][order[leastdigit]] = array[i];
            order[leastdigit]++;
        } 
        int k=0;
        for(i=0; i<10; i++){
            if(order[i] != 0){
                for(int j=0; j<order[i]; j++, k++){
                    array[k] = tmp[i][j];
                }
            }
            order[i] = 0;
        }
        n *= 10;
    }
}

void Merge(char** arr,int low,int mid,int high) //Merging the Array Function
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

void MergeSort(char** arr,int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

int main(int argc, char *argv[]){

    time_t t1, t2;
    char *line;
    int i, cnt=0;
    struct timeval start, end;
    FILE *fp;
    gettimeofday(&start, NULL);
    words = (char **)malloc(sizeof(char *) * NumberOfElement);
    line = (char *)malloc(sizeof(char) * WordLengh);
    if(words == NULL || line == NULL){
        printf("Malloc Error!\n");
        return 0;
    }
    fp = fopen("./input", "r");

    initialize();
    parseline(argc, argv);
    /* printarguments(); */
    inputgenerator();
    /* printoutput(); */
    if(Minusn == TRUE){
        if(Qsort == TRUE){
            qsort(words, NumberOfElement, sizeof(char *), mycomparewords);
        }
        else if(Mergesort == TRUE){
            mergesort(words, NumberOfElement, sizeof(char *), mycomparewords);
        }
        else if(Heapsort == TRUE){
            heapsort(words, NumberOfElement, sizeof(char *), mycomparewords);
        }
        else if(Radixsort == TRUE){
            /* myradixsort(); */
            printf("-n radix sort not done yet\n");
        }
        else
            printf("Choose a sorting algorithm : -qsort or -msort\n");
    }
    else{
        if(Qsort == TRUE){
            qsort(array, NumberOfElement, sizeof(int), mycomparearray);
        }
        else if(Mergesort == TRUE){
            mergesort(array, NumberOfElement, sizeof(int), mycomparearray);
        }
        else if(Heapsort == TRUE){
            heapSort(array, NumberOfElement, ascending);
            /* heapsort(array, NumberOfElement, sizeof(int), mycomparearray); */
        }
        else if(Radixsort == TRUE){
            myradixsort();
        }
        else
            printf("Choose a sorting algorithm : -qsort or -msort\n");
    }
    /* printoutput(); */
    gettimeofday(&end, NULL);
    int diff = 1000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000;
    printf("time = %dms\n", diff);
    return 0;
}

void heapSort(int* num, int len, int(*compar)(int, int)) {
    heapTree(num, len, compar);
    selectFromHeap(num, len, compar);
}

void heapTree(int* num, int len, int(*compar)(int, int)) {
    int i, end;
    for(i = 1, end = len + 1; i < end; i++) { bubbleLeaf(num, i, compar); }
}

void selectFromHeap(int* num, int len, int(*comp)(int, int)) {
    int end;
    for(end = len; end > OFFSET; end--) {
        SWAP(num[1 - OFFSET], num[end - OFFSET]);
        bubbleRoot(num, end, comp);
    }
}

void bubbleLeaf(int* num, int eleIdx, int(*compar)(int, int)) {
    int childIdx, parentIdx;
    for(childIdx = eleIdx, parentIdx = eleIdx / 2;
        isBubbleable(num, childIdx, parentIdx, compar);
        childIdx = parentIdx, parentIdx = childIdx / 2) {
         SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]);
    }
}

int isBubbleable(int* num, int childIdx,
                 int parentIdx, int(*compar)(int, int)) {
    return childIdx > OFFSET &&
           compar(num[parentIdx - OFFSET], num[childIdx - OFFSET]) < 0;
}

void bubbleRoot(int* num, int end, int(*comp)(int, int)) {
    int parentIdx, childIdx;
    for(parentIdx = 0 + OFFSET,
        childIdx = idxFromChilds(num, parentIdx, end, comp);
        childIdx < end &&
        comp(num[childIdx - OFFSET], num[parentIdx - OFFSET]) > 0;
        parentIdx = childIdx,
        childIdx = idxFromChilds(num, parentIdx, end, comp)) {
        SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]);
    }
}

int idxFromChilds(int* num, int parentIdx, int end, int(*comp)(int, int)) {
   int childIdx = parentIdx * 2;
   return isRightLeafSuitable(num, childIdx, end, comp) ?
              childIdx + 1 : childIdx;
}

int isRightLeafSuitable(int* num, int childIdx,
                        int end, int(*comp)(int, int)) {
    return childIdx < end - 1 &&
           comp(num[childIdx + 1 - OFFSET], num[childIdx - OFFSET]) > 0;
}

void print(int* arr, int len) {
    int i;
    for(i = 0; i < len; i++) { printf("%d ", arr[i]); }
    printf("\n");
}


