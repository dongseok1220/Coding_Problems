import sys

N = int(sys.stdin.readline())

data = []

for i in range(N) :
    data.append(int(sys.stdin.readline()))


def quick_sort(arr) :
    if len(arr) <= 1 :
        return arr

    piv = len(arr) // 2

    f_arr, p_arr,b_arr = [],[],[]
    for i in arr :
        if i < arr[piv] :
            f_arr.append(i)
        elif i > arr[piv] :
            b_arr.append(i)
        else :
            p_arr.append(i)

    return quick_sort(f_arr) + quick_sort(p_arr) + quick_sort(b_arr)

sort = quick_sort(data)

for i in range(N) :
    print(sort[i]) 
