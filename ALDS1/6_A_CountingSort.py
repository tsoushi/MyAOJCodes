def countingSort(A: list, k: int):
    n = len(A)
    C = [0 for i in range(k + 1)]
    
    for a in A:
        C[a] += 1
    
    for i in range(1, k + 1):
        C[i] = C[i] + C[i - 1]
    
    B = [0 for i in range(len(A))]
    for j in range(n - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1
    
    return B

input()
array = [int(i) for i in input().split()]
print(' '.join([str(i) for i in countingSort(array, 2000000)]))