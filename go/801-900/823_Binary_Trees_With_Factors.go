package main

import (
	"math"
	"sort"
)

func numFactoredBinaryTrees(arr []int) int {
	sort.Ints(arr)
	const cap = 1000000007
	r := 0
	dp := map[int]int{}
	for i := 0; i < len(arr); i++ {
		a := arr[i]
		dp[a] = 1
		for j := 0; j < i; j++ {
			f1 := arr[j]
			if a%f1 == 0 {
				f2 := a / f1 // may not in arr, then dp[f2] == 0
				dp[a] = (dp[a] + dp[f1]*dp[f2]) % cap
			}
		}
		r = (r + dp[a]) % cap
	}
	return r
}

func numFactoredBinaryTrees0(arr []int) int {
	set := map[int]bool{}
	for _, a := range arr {
		set[a] = true
	}

	const mod = 1000000007
	r := 0

	mFactor := map[int][][]int{} // e.g. {12: [][]int{ {2,6}, {3,4} }
	dp := map[int]int{}
	for _, a := range arr {
		r = (r + dfs(a, set, mFactor, dp)) % mod
	}

	return r
}

func dfs(n int, set map[int]bool, mFactor map[int][][]int, dp map[int]int) int {
	if v, ok := dp[n]; ok {
		// fmt.Printf("\tdfs %d = %d\tcached\n", n, v)
		return v
	}

	r := 1
	factors := getFactors(n, set, mFactor)
	for _, pair := range factors {
		f1, f2 := pair[0], pair[1]
		tmp := dfs(f1, set, mFactor, dp) * dfs(f2, set, mFactor, dp)
		if f1 != f2 {
			tmp *= 2
		}
		r += tmp
	}

	dp[n] = r
	// fmt.Printf("\tdfs %d = %d\n", n, r)
	return r
}

func getFactors(n int, set map[int]bool, mFactor map[int][][]int) (factors [][]int) {
	if v, ok := mFactor[n]; ok {
		// fmt.Printf("\tfactor %d = %v\tcached\n", n, factors)
		return v
	}

	limit := int(math.Sqrt(float64(n)))
	for f1 := 2; f1 <= limit; f1++ {
		if !set[f1] {
			continue
		}
		f2 := n / f1
		if !set[f2] {
			continue
		}
		if f1*f2 == n {
			factors = append(factors, []int{f1, f2})
		}
	}
	mFactor[n] = factors
	// fmt.Printf("\tfactor %d = %v\n", n, factors)
	return factors
}

// func main() {
// 	fmt.Printf("LeetCode 823. Binary Trees With Factors ...\n\n")

// 	type args struct {
// 		arr []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{2, 4},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 4, 5, 10},
// 			},
// 			want: 7,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 3, 4, 6, 12},
// 			},
// 			want: 18,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 4, 8},
// 			},
// 			want: 8,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 3, 4, 6, 8, 12, 24},
// 			},
// 			want: 68,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 3, 4, 6, 12, 24},
// 			},
// 			want: 53,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numFactoredBinaryTrees0(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = numFactoredBinaryTrees(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}

// }
