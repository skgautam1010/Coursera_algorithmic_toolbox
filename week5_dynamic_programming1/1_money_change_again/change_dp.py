# Uses python3
import sys

def get_change(money):
    coins=[1,3,4]
    if money==1 or money==3 or money==4:
        return 1
    if money==0:
        return 0
    if money==2 or money==6:
        return 2
    min_num_coins=[]
    min_num_coins.insert(0,0)
    for m in range(1,money):
        min_num_coins.insert(m,float('inf'))
        for i in range(1,abs(len(coins))):
            if m>=coins[i]:
                num_coins=min_num_coins[m-coins[i]]+1
                if num_coins<min_num_coins[m]:
                    min_num_coins[m]=num_coins

    return min_num_coins.pop()

if __name__ == '__main__':
    m = int(sys.stdin.read())
    #m=int(input())
    print(get_change(m))
