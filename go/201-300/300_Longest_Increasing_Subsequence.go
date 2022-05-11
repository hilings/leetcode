package main

func lengthOfLIS(nums []int) int {
	l := []int{} // increasing subsequence
	for _, a := range nums {
		if len(l) == 0 || a > l[len(l)-1] {
			l = append(l, a)
		} else if a < l[0] {
			l[0] = a
		} else {
			i, j := 0, len(l)-1
			for i < j { // binary search
				mid := i + (j-i)/2
				if l[mid] < a {
					i = mid + 1
				} else {
					j = mid
				}
			}
			l[i] = a // replace first number in l that is >= a
		}
	}

	return len(l)
}

func lengthOfLIS0(nums []int) int {
	r := 0
	l := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		l[i] = 1
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] && l[i] < l[j]+1 {
				l[i] = l[j] + 1
			}
		}
		if l[i] > r {
			r = l[i]
		}
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 300. Longest Increasing Subsequence ...\n\n")

// 	type args struct {
// 		nums []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				nums: []int{10, 9, 2, 5, 3, 7, 101, 18},
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				nums: []int{0, 1, 0, 3, 2, 3},
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				nums: []int{7, 7, 7, 7, 7, 7, 7},
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := lengthOfLIS(tt.args.nums)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
