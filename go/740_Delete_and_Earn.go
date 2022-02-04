package main

import (
	"sort"
)

func deleteAndEarn(nums []int) int {
	m := map[int]int{}
	keys := []int{}
	for _, a := range nums {
		if _, ok := m[a]; !ok {
			keys = append(keys, a)
		}
		m[a]++
	}
	sort.Ints(keys)

	h := map[int]int{
		-1: 0,
	}
	for i, a := range keys {
		earn := a * m[a]
		if i == 0 || a > keys[i-1]+1 {
			h[i] = h[i-1] + earn
		} else {
			h[i] = max(h[i-1], h[i-2]+earn)
		}
	}

	return h[len(keys)-1]
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// func main() {
// 	fmt.Printf("LeetCode 740. Delete and Earn ...\n\n")

// 	tests := [][]int{
// 		// {3, 4, 2}, // 6
// 		// {2, 2, 3, 3, 3, 4}, // 9
// 		// {3, 3, 4, 4, 5}, // 11
// 		// {2, 2, 3, 3, 4, 4, 5}, // 12
// 		// {2, 3, 3, 3, 4, 4, 4, 5}, // 14
// 		{12, 32, 93, 17, 100, 72, 40, 71, 37, 92, 58, 34, 29, 78, 11, 84, 77, 90, 92, 35, 12, 5, 27, 92, 91, 23, 65, 91, 85, 14, 42, 28, 80, 85, 38, 71, 62, 82, 66, 3, 33, 33, 55, 60, 48, 78, 63, 11, 20, 51, 78, 42, 37, 21, 100, 13, 60, 57, 91, 53, 49, 15, 45, 19, 51, 2, 96, 22, 32, 2, 46, 62, 58, 11, 29, 6, 74, 38, 70, 97, 4, 22, 76, 19, 1, 90, 63, 55, 64, 44, 90, 51, 36, 16, 65, 95, 64, 59, 53, 93}, //
// 	}
// 	for _, nums := range tests {
// 		r := deleteAndEarn(nums)
// 		fmt.Println(r)
// 	}

// }
