package main

import (
	"fmt"
)

func largestSumOfAverages(nums []int, k int) float64 {
	m := make(map[[2]int]float64)
	sums := []int{0} // sums[i] == sum of first i elements in nums
	for i := 0; i < len(nums); i++ {
		sums = append(sums, sums[i]+nums[i])
	}
	return dp813(sums, k, len(nums), m)
}

func dp813(sums []int, k int, i int, m map[[2]int]float64) float64 {
	if v, ok := m[[2]int{k, i}]; ok {
		return v
	}

	if k == 1 {
		return float64(sums[i]) / float64(i)
	}

	var max float64
	for j := k - 1; j < i; j++ { // leave at least k-1 elements
		t := dp813(sums, k-1, j, m) + float64(sums[i]-sums[j])/float64(i-j)
		if t > max {
			max = t
		}
	}

	m[[2]int{k, i}] = max
	return max
}

func main() {
	fmt.Printf("LeetCode 813. Largest Sum of Averages ...\n\n")

	type args struct {
		nums []int
		k    int
	}
	tests := []struct {
		args args
		want float64
	}{
		{
			args: args{
				nums: []int{
					9, 1, 2, 3, 9,
				},
				k: 3,
			},
			want: 20,
		},
		{
			args: args{
				nums: []int{
					1, 2, 3, 4, 5, 6, 7,
				},
				k: 4,
			},
			want: 20.5,
		},
		{
			args: args{
				nums: []int{
					4, 1, 7, 5, 6, 2, 3,
				},
				k: 4,
			},
			want: 18.16667,
		},
	}
	for _, tt := range tests {
		r := largestSumOfAverages(tt.args.nums, tt.args.k)
		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
	}
}
