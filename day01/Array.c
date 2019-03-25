#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pT_Array init_array(int size){
    pT_Array p_array = (pT_Array)malloc(sizeof(T_Array));
    if(p_array){
        p_array->length = 0;
        p_array->size = size;
        if(size){
            p_array->p_data = (int*)malloc(sizeof(int)*size);
            if(p_array->p_data == NULL){
                free(p_array);
                p_array = NULL;
            }
        }
    }
    return p_array;
}

void release_array(pT_Array p_array){
    if(p_array){
        free(p_array->p_data);
        p_array->p_data = NULL;
    }
    free(p_array);
    p_array = NULL;
}

int add(pT_Array p_array, int data){
    int *pTmp = NULL;
    int type_size = sizeof(int);
    if(p_array == NULL){
        return -1;
    }
    if(p_array->length == p_array->size){
        //重新分配内存
        pTmp = p_array->p_data;
        p_array->p_data = (int*)malloc(type_size*(p_array->size*2));
        if(p_array->p_data){
            p_array->size = (p_array->size)*2;
            memcpy(p_array->p_data, pTmp, type_size*p_array->length);
            free(pTmp);
            pTmp = NULL;
        }else{
            p_array->p_data = pTmp;
            return -2;
        }
    }
    pTmp = p_array->p_data + p_array->length;
    *pTmp = data;
    p_array->length++;
    return 0;
}

pT_Array clone(pT_Array p_array){
    pT_Array p_new = NULL;
    if(p_array == NULL){
        return NULL;
    }
    p_new = (pT_Array)malloc(sizeof(int)*(p_array->size));
    if(p_new){
        p_new->p_data = (int*)malloc(sizeof(int)*(p_array->size));
        if(p_new->p_data){
            memcpy(p_new->p_data, p_array->p_data, sizeof(int)*(p_array->length));
            p_new->length = p_array->length;
            p_new->size = p_array->size;
        }else{
            free(p_new);
            p_new = NULL;
        }
    }
    return p_new;
}

int atIndex(pT_Array p_array, int index){
    return *(p_array->p_data+index);
}

int isExist(pT_Array p_array, int data){
    int i;
    for(i = 0;i<p_array->length;++i){
        if(*(p_array->p_data+i) == data){
            return 1;
        }
    }
    return 0;
}

void Traverse(pT_Array p_array, void(*func)(int)){
    int i;
    for(i = 0;i<p_array->length;++i){
        func(*(p_array->p_data + i));
    }
}
