package main

import "fmt"

func maxIncreaseKeepingSkyline(grid [][]int) int {
	n := len(grid)
	maxH, maxV := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			maxH[i] = max(maxH[i], grid[i][j])
			maxV[i] = max(maxV[i], grid[j][i])
		}
	}

	r := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			r += min(maxH[i], maxV[j]) - grid[i][j]
		}
	}

	return r
}

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }

// func min(a, b int) int {
// 	if a < b {
// 		return a
// 	}
// 	return b
// }

// func main() {
// 	fmt.Printf("LeetCode 807. Max Increase to Keep City Skyline ...\n\n")

// 	type args struct {
// 		grid [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{3, 0, 8, 4},
// 					{2, 4, 5, 7},
// 					{9, 2, 6, 3},
// 					{0, 3, 1, 0},
// 				},
// 			},
// 			want: 35,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{0, 0, 0},
// 					{0, 0, 0},
// 					{0, 0, 0},
// 				},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maxIncreaseKeepingSkyline(tt.args.grid)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
