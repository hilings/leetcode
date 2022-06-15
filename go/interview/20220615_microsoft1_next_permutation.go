package main

import (
	"sort"
)

// find next permutation

func nextPermutation(arr []int) []int {
	// 1 3 2
	// 1 2 3
	// 1 2 4 5 3
	tail := len(arr) - 1
	for i := tail - 1; i >= 0 && arr[i] > arr[i+1]; i-- {
		tail--
	}

	if tail < 0 { // last permutation
		sort.Ints(arr)
		return arr
	}

	//tail 5
	swap := len(arr) - 1
	for arr[swap] <= arr[tail-1] {
		swap--
	}

	// swap 5, tail-1= 4
	arr[swap], arr[tail-1] = arr[tail-1], arr[swap]

	sort.Ints(arr[tail:])
	// 1 2 5 3 4
	return arr
}

// func main() {
// 	fmt.Printf("next permutation, with Microsoft R1 ...\n\n")

// 	arr := []int{1, 2, 4, 5, 3} // 1,2,5,3,4
// 	r := nextPermutation(arr)
// 	fmt.Println(r)
// }
