cnt = 0

def main():
    length = int(input())
    array = [int(input()) for i in range(length)]

    shellSort(array, length)
    print(cnt)
    print('\n'.join([str(i) for i in array]))

def insertionSort(array, length, step):
    global cnt

    for i in range(step, length):
        buf = array[i]
        j = i - step
        while j >= 0 and array[j] > buf:
            array[j + step] = array[j]
            j = j - step
            cnt += 1
        array[j + step] = buf

def shellSort(array, n):
    global cnt
    
    cnt = 0
    G = [1]
    for i in range(99):
        if 3*G[-1] + 1 < n:
            G.append(3*G[-1] + 1)
        else:
            break
    G.reverse()
    m = len(G)
    
    print(m) # 整数m
    print(' '.join([str(i) for i in G])) # m個の整数G

    for i in range(m):
        insertionSort(array, n, G[i])

main()