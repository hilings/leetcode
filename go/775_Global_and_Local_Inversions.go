package main

import (
	"fmt"
)

func isIdealPermutation0(nums []int) bool {
	global, local := 0, 0
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			local++
		}

		for j := i + 1; j < len(nums); j++ {
			if nums[i] > nums[j] {
				global++
			}
		}
	}
	return global == local
}

func isIdealPermutation(nums []int) bool {
	for i := 0; i < len(nums); i++ {
		if nums[i]-i > 1 || nums[i]-i < -1 {
			return false
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 775. Global and Local Inversions ...\n\n")

// 	type args struct {
// 		nums []int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				nums: []int{1, 0, 2},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				nums: []int{1, 2, 0},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := isIdealPermutation(tt.args.nums)
// 		fmt.Println(r)
// 	}
// }
