package main

func dominantIndex(nums []int) int {
	if len(nums) == 1 {
		return 0
	}

	max, second := 0, 1 // index of largest and 2nd largest
	if nums[1] > nums[0] {
		max, second = 1, 0
	}
	for i := 2; i < len(nums); i++ {
		if nums[i] > nums[max] {
			second = max
			max = i
		} else if nums[i] > nums[second] {
			second = i
		}
	}

	if nums[max] >= 2*nums[second] {
		return max
	}
	return -1
}

// func main() {
// 	fmt.Printf("LeetCode 747. Largest Number At Least Twice of Others ...\n\n")

// 	type args struct {
// 		nums []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				nums: []int{3, 6, 1, 0},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				nums: []int{1, 2, 3, 4},
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				nums: []int{1},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				nums: []int{1, 2},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := dominantIndex(tt.args.nums)
// 		fmt.Println(r)
// 	}
// }
