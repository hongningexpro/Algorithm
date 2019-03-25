#include <stdio.h>
#include <time.h>
#include "Merge_Sort.h"
#include "Bubble_Sort.h"

void printArray(int *array, unsigned int len){
    int i;
    printf("[ ");
    for(i = 0; i<len; ++i){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int main(){
    int i;
    int n = 100000;
    int a[10000000];
    clock_t start,end;
    double duration;
    srand((unsigned)time(NULL));
    for(i = 0;i<10000000;++i){
        a[i] = rand()%90000000;
    }
    //printArray(a, 10000);
    start = clock();
    merge_sort(a, 10000000);
    end = clock();
    duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("sort time is %f seconds\n", duration);
    //printArray(a, 1000000);
    return 0;
}

int main1(){
    int i;
    int n = 10;
    int a[100000];
    clock_t start,end;
    double duration;
    srand((unsigned)time(NULL));
    for(i = 0;i<100000;++i){
        a[i] = rand()%100000;
        n--;
    }
    //printArray(a, 10);
    start = clock();
    bubble_sort(a,100000);
    end = clock();
    duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("sort time is %f seconds\n", duration);
    printArray(a, 100000);
    return 0;
}
