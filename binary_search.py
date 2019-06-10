#二分查找算法递归和非递归实现
#时间复杂度：最好(1), 最坏o(logn)

def binary_search(alist, item):
    #二分查找非递归方式
    n = len(alist)
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2
        if alist[mid] == item:
            return True
        elif alist[mid] > item:
            end = mid - 1
        else:
            start = mid + 1
    return False

def binary_search_recursize(alist, item):
    n = len(alist)
    if 0 == n:
        return False
    mid = n // 2
    if alist[mid] == item:
        return True
    elif alist[mid] > item:
        return binary_search_recursize(alist[:mid], item)
    else:
        return binary_search_recursize(alist[mid:], item)
if __name__ == "__main__":
    alist = [1,2,3,4,5,6]
    print("Ture of False: %d" % binary_search_recurse(alist, 4))
