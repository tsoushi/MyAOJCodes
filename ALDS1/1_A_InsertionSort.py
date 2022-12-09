def main():
    input()
    array = [int(i) for i in input().split()]
    
    insertionSort(array)
    print(' '.join([str(i) for i in array]))


def insertionSort(array):
    for i in range(1, len(array)):
        print(' '.join([str(i) for i in array]))

        buf = array[i]
        j = i - 1
        while j >= 0 and array[j] > buf:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = buf

if __name__ == '__main__':
    main()