'''
knuth洗牌算法
source:https://mp.weixin.qq.com/s/OipavTRvi98WKLfnSSnJLQ
'''
from random import randrange
def shuffle(arr:[]):
    length = len(arr)
    if length <= 1:
        return
    for i in range(length-1, -1, -1):
        rand = randrange(0, i+1)
        arr[i], arr[rand] = arr[rand], arr[i]

if __name__ == '__main__':
    a = [1,2,3,4,5,6,7,8]
    cnt = 10
    while (cnt):
        shuffle(a)
        print(a)
        cnt -= 1
    
