#ifndef __ARRAY_H_
#define __ARRAY_H_

typedef struct _Tag_Array{
    int *p_data;
    int length;
    int size;
}T_Array;

typedef T_Array* pT_Array;

pT_Array init_array(int size);
void release_array(pT_Array p_array);
int add(pT_Array p_array, int data);
pT_Array clone(pT_Array p_array);
int atIndex(pT_Array p_array, int index);
int isExist(pT_Array p_array, int data);
void Traverse(pT_Array p_array, void(*func)(int));

#endif
