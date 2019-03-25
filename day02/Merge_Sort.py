import random
import time

def merge_sort(sort_list):
    if len(sort_list) == 1:
        return sort_list
    idx = len(sort_list)//2
    pre_list = merge_sort(sort_list[:idx])
    tail_list = merge_sort(sort_list[idx:])
    return sort(pre_list, tail_list)


def sort(pre_list, tail_list):
    sort_list = list()
    pre_len = len(pre_list)
    tail_len = len(tail_list)
    pre_idx = 0
    tail_idx = 0
    for i in range(0, pre_len + tail_len):
        if pre_idx < pre_len and tail_idx < tail_len:
            if pre_list[pre_idx] <= tail_list[tail_idx]:
                sort_list.append(pre_list[pre_idx])
                pre_idx +=1
            else:
                sort_list.append(tail_list[tail_idx])
                tail_idx +=1
        elif pre_idx == pre_len:
            sort_list.append(tail_list[tail_idx])
            tail_idx +=1
        elif tail_idx == tail_len:
            sort_list.append(pre_list[pre_idx])
            pre_idx +=1
    return sort_list

if __name__ == "__main__":
    l = list()
    for i in range(0,10000000):
        l.append(random.randint(0,3000000))
    #print(l)
    start = time.time()
    sort_l = merge_sort(l)
    end = time.time()
    print("sort time is %s seconds"%(end-start))
    #print(sort_l)
