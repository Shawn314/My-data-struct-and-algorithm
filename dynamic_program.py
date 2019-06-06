
# see details at:
# https://mp.weixin.qq.com/s?__biz=MzI1MTIzMzI2MA==&mid=2650564079&idx=1&sn=d7b336a62ac01f4cdd13270644fb6623&chksm=f1fed36cc6895a7a7550b1eab800e255cec8f73b7e71998ed2102faf650eea7c4adb656d4f0a&mpshare=1&scene=24&srcid=#rd

import pdb
# fundament function
def Fibonacci(n):
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return Fibonacci(n-1) + Fibonacci(n-2)
# bottom-up
def FibonacciLookup(n, lookup):
    # pdb.set_trace()
    if n <= 0:
        lookup[n] = 0
    if n == 1:
        lookup[n] = 1
    if n not in lookup:
        lookup[n] = FibonacciLookup(n-1, lookup) + FibonacciLookup(n-2, lookup)
    return lookup[n]
# Tabulation
def FinonacciTabulation(n):
    arr = {}
    arr[0] = 0
    arr[1] = 1
    for i in range(2, n+1):
        arr[i] = arr[i-1] + arr[i-2]
    return arr[n]
    
if __name__ == "__main__":
    # print("result is %d" % Fibonacci(100))
    # dictLookup = {}
    # print("result is %d" % FibonacciLookup(200, dictLookup))
    print("result is %d" % FinonacciTabulation(200))

