cache = []

def fibonacci(n):
    F = [1,1]
    for i in range(2, n + 1):
        F.append(F[i - 2] + F[i - 1])
    return F[n]

print(fibonacci(int(input())))