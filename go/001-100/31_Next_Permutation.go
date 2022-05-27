package main

import (
	"sort"
)

func nextPermutation(nums []int) {
	tail := len(nums) - 1
	var next int
	for next = tail - 1; next >= 0 && nums[next] >= nums[next+1]; next-- {
	}
	if next < 0 {
		sort.Ints(nums)
		return
	}

	for nums[tail] <= nums[next] {
		tail--
	}

	nums[next], nums[tail] = nums[tail], nums[next]
	sort.Ints(nums[next+1:])
	return
}

// func main() {
// 	fmt.Printf("LeetCode 31. Next Permutation ...\n\n")

// 	type args struct {
// 		nums []int
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				nums: []int{1, 2, 3},
// 			},
// 			want: []int{1, 3, 2},
// 		},
// 		{
// 			args: args{
// 				nums: []int{3, 2, 1},
// 			},
// 			want: []int{1, 2, 3},
// 		},
// 		{
// 			args: args{
// 				nums: []int{1, 1, 5},
// 			},
// 			want: []int{1, 5, 1},
// 		},
// 		{
// 			args: args{
// 				nums: []int{3, 3, 2},
// 			},
// 			want: []int{2, 3, 3},
// 		},
// 		{
// 			args: args{
// 				nums: []int{1, 4, 3, 1},
// 			},
// 			want: []int{3, 1, 1, 4},
// 		},
// 		{
// 			args: args{
// 				nums: []int{5, 4, 7, 5, 3, 2},
// 			},
// 			want: []int{5, 5, 2, 3, 4, 7},
// 		},
// 	}
// 	for _, tt := range tests {
// 		fmt.Println(tt.args.nums)
// 		nextPermutation(tt.args.nums)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", tt.args.nums, tt.want)
// 	}
// }
