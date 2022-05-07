package main

func pos(nums []int, target int) int {
	i, j := 0, len(nums)-1
	for i < j {
		// fmt.Printf("i = %d, j = %d\n", i, j)
		mid := (i + j) / 2
		if nums[i] < nums[mid] { // first half sorted
			if target < nums[i] || target > nums[mid] {
				i = mid + 1
			} else {
				j = mid
			}
		} else { // second half sorted
			if target >= nums[i] || target <= nums[mid] {
				j = mid
			} else {
				i = mid + 1
			}
		}
	}
	if nums[i] == target {
		return i
	}

	return -1
}

// func main() {
// 	fmt.Printf("Wrap binary search, with ByteDance, R1 ...\n\n")

// 	type args struct {
// 		nums   []int
// 		target int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				nums:   []int{4, 5, 6, 7, 0, 1, 2},
// 				target: 0,
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				nums:   []int{4, 5, 6, 7, 0, 1, 2},
// 				target: 3,
// 			},
// 			want: -1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := pos(tt.args.nums, tt.args.target)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
