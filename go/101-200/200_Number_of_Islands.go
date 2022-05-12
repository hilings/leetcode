package main

var dirs = [][]int{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},
}

func numIslands(grid [][]byte) int {
	r := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				r++
				dfs(grid, i, j)
			}
		}
	}
	return r
}

func dfs(grid [][]byte, i, j int) {
	if i < 0 || i == len(grid) || j < 0 || j == len(grid[0]) || grid[i][j] == '0' {
		return
	}
	grid[i][j] = '0'
	for _, d := range dirs {
		dfs(grid, i+d[0], j+d[1])
	}
}

// func main() {
// 	fmt.Printf("LeetCode 200. Number of Islands ...\n\n")

// 	type args struct {
// 		grid [][]byte
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				grid: [][]byte{
// 					{'1', '1', '1', '1', '0'},
// 					{'1', '1', '0', '1', '0'},
// 					{'1', '1', '0', '0', '0'},
// 					{'0', '0', '0', '0', '0'},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				grid: [][]byte{
// 					{'1', '1', '0', '0', '0'},
// 					{'1', '1', '0', '0', '0'},
// 					{'0', '0', '1', '0', '0'},
// 					{'0', '0', '0', '1', '1'},
// 				},
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numIslands(tt.args.grid)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
