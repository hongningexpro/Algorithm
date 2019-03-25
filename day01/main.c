#include <stdio.h>
#include <stdlib.h>
#include "Array.h"


void print(int a){
    printf("%d ", a);
}

void calc1(int total, pT_Array pArray){
    int i;
    pT_Array p_array = NULL;
    static int rewards[4] = {1,2,5,10};
    if(pArray == NULL){
        return;
    }
    if(0 == total){
        printf("===========\n");
        printf("[ ");
        Traverse(pArray, print);
        printf("]\n");
        printf("===========\n");
        release_array(pArray);
    }else if(total<0){
        release_array(pArray);
        return;
    }else{
        for(i=0;i<4;++i){
            p_array = clone(pArray);
            if(p_array == NULL){
                release_array(pArray);
                return;
            }
            add(p_array, rewards[i]);
            calc1(total-rewards[i], p_array);
        }
    }
}


void calc2(int val, int total, pT_Array pArray){
    int i;
    pT_Array p_array = NULL;
    if(pArray == NULL){
        return;
    }
    if(val == total){
        printf("===========\n");
        printf("[ ");
        Traverse(pArray, print);
        printf("]\n");
        printf("===========\n");
        release_array(pArray);
    }else if(val > total){
        release_array(pArray);
    }else{
        for(i=1;i<=total;++i){
            p_array = clone(pArray);
            if(1 == i){
                if(isExist(p_array, 1)){
                    continue;
                }
            }
            add(p_array, i);
            if(total == i){
                if(!isExist(p_array, 1)){
                    add(p_array, 1);
                }
            }
            calc2(val*i, total,p_array);
        }
    }
}
int main(){
    pT_Array p_array = init_array(10);
    /*calc1(10, p_array);*/
    calc2(1, 8, p_array);
    release_array(p_array);
    return 0;
}


