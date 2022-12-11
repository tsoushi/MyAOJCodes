package main

import "fmt"

func main() {
	var length int
	array := make([]int, 0, 100)

	fmt.Scan(&length)
	for i := 0; i < length; i++ {
		var buf int
		fmt.Scan(&buf)
		array = append(array, buf)
	}

	insertionSort(array)
	printArray(array)
}

func insertionSort(array []int) {
	for i := 1; i < len(array); i++ {
		buf := array[i]
		j := i - 1

		printArray(array)

		for j >= 0 && array[j] > buf {
			array[j+1] = array[j]
			j--
		}
		array[j+1] = buf
	}
}

func printArray(array []int) {
	for i := 0; i < len(array); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(array[i])
	}
	fmt.Println()
}
