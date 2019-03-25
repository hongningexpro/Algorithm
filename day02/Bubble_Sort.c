#include "Bubble_Sort.h"

int bubble_sort(int *array, unsigned int len){
    int i,j;
    int tmp;
    if(array == NULL){
        return -1;
    }
    for(i = 0;i<len-1;++i){
        for(j = 0; j<len-i-1;++j){
            if(array[j]>array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    return 0;
}
