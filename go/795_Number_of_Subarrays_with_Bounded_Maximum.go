package main

func numSubarrayBoundedMax(nums []int, left int, right int) int {
	r := 0
	dp := 0
	for i, lower := 0, 0; i < len(nums); i++ {
		if nums[i] > right {
			dp = 0
			lower = i + 1
		} else if nums[i] >= left {
			if i-1 >= 0 && nums[i-1] < left {
				dp = i - lower + 1
			} else {
				dp = dp + 1
			}
		} else { // nums[i] < left
			dp = dp
		}
		// fmt.Printf("%d = %d\n", nums[i], dp)
		r += dp
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 795. Number of Subarrays with Bounded Maximum ...\n\n")

// 	type args struct {
// 		nums  []int
// 		left  int
// 		right int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				nums:  []int{2, 1, 4, 3},
// 				left:  2,
// 				right: 3,
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				nums:  []int{2, 9, 2, 5, 6},
// 				left:  2,
// 				right: 8,
// 			},
// 			want: 7,
// 		},
// 		{
// 			args: args{
// 				nums:  []int{2, 1, 1, 3},
// 				left:  2,
// 				right: 8,
// 			},
// 			want: 7,
// 		},
// 		{
// 			args: args{
// 				nums:  []int{1, 3, 9, 1, 2},
// 				left:  2,
// 				right: 8,
// 			},
// 			want: 4,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numSubarrayBoundedMax(tt.args.nums, tt.args.left, tt.args.right)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
