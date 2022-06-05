package main

func matrixScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		if grid[i][0] == 1 {
			continue
		}
		for j := 0; j < n; j++ {
			grid[i][j] ^= 1
		}
	}

	for j := 1; j < n; j++ {
		count := 0
		for i := 0; i < m; i++ {
			count += grid[i][j]
		}
		if count >= (m+1)/2 {
			continue
		}
		for i := 0; i < m; i++ {
			grid[i][j] ^= 1
		}
	}

	r := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			r += grid[i][j] << (n - 1 - j)
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 861. Score After Flipping Matrix ...\n\n")

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
// 					{0, 0, 1, 1},
// 					{1, 0, 1, 0},
// 					{1, 1, 0, 0},
// 				},
// 			},
// 			want: 39,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{0},
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{0, 1},
// 					{0, 1},
// 					{0, 1},
// 					{0, 0},
// 				},
// 			},
// 			want: 11,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := matrixScore(tt.args.grid)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
