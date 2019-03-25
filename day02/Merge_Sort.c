#include "Merge_Sort.h"

int* merge_sort(int *sort_array, unsigned int len){
    int *pre_array, *tail_array;
    int pre_len,tail_len;
    int pre_idx,tail_idx;
    int i;
    int *p_array = NULL;
    if(len == 0||sort_array == NULL){
        return NULL;
    }
    if(len == 1){
        return sort_array;
    }
    pre_len = len/2;
    tail_len = len/2+len%2;
    pre_array = merge_sort(sort_array, pre_len);
    tail_array = merge_sort(sort_array+pre_len, tail_len);

    p_array = (int*)malloc(sizeof(int)*(len));
    if(p_array == NULL){
        return NULL;
    }
    pre_idx = 0;
    tail_idx = 0;
    for(i = 0;i< len;++i){
        if(pre_idx<pre_len&&tail_idx<tail_len){
            if(pre_array[pre_idx]<=tail_array[tail_idx]){
                p_array[i] = pre_array[pre_idx];
                pre_idx++;
            }else{
                p_array[i] = tail_array[tail_idx];
                tail_idx++;
            }
        }else if(pre_idx == pre_len){
            p_array[i] = tail_array[tail_idx];
            tail_idx++;
        }else if(tail_idx == tail_len){
            p_array[i] = pre_array[pre_idx];
            pre_idx++;
        }
    }
    memcpy(sort_array, p_array, len*sizeof(int));
    free(p_array);
    return sort_array;
}

