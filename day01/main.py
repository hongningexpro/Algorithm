import copy

def calc1(total, res_list):
    rewards = [1,2,5,10]
    if 0 == total:
        print("="*10)
        for tmp in res_list:
            print("%d "%tmp, end="")
        print()
        print("="*10)
    elif total < 0:
        return
    else:
        for i in range(0,4):
            li = copy.deepcopy(res_list)
            li.append(rewards[i])
            calc1(total-rewards[i], li)

if __name__ == "__main__":
    res_list = list()
    calc1(8,res_list)
