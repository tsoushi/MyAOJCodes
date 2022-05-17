def call(n):
    for i in range(1, n+1):
        x = i
        if x % 3 == 0:
            print(' ', i, end='')
            continue
        while x != 0:
            if x % 10 == 3:
                print(' ', i, end='')
                break
            x = int(x/10)
    print()

call(int(input()))