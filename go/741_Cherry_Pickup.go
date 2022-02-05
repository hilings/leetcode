package main

import "fmt"

func cherryPickup(grid [][]int) int {
	return max741(f741(grid, 0, 0, [][]int{{1, 0}, {0, 1}}), 0)
}

func f741(grid [][]int, i int, j int, d [][]int) int {
	// fmt.Println(i, j, d)
	if i < 0 || i == len(grid) || j < 0 || j == len(grid) || grid[i][j] == -1 {
		return -100
	}
	if len(grid) == 1 {
		return grid[0][0]
	}
	if i == 0 && j == 0 && d[0][0]+d[0][1] == -1 { // back
		return 0
	}
	if i == len(grid)-1 && j == len(grid)-1 && d[0][0]+d[0][1] == 1 { // return
		d = [][]int{{0, -1}, {-1, 0}}
	}
	pick := grid[i][j]
	grid[i][j] = 0
	s := max741(f741(grid, i+d[0][0], j+d[0][1], d), f741(grid, i+d[1][0], j+d[1][1], d))
	grid[i][j] = pick

	return pick + s
}

func max741(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func cherryPickup2(grid [][]int) int {
	return max741(dp741(grid, 0, 0, 0, map[string]int{}), 0)
}

func dp741(grid [][]int, r1 int, c1 int, c2 int, dp map[string]int) int {
	n, r2 := len(grid), r1+c1-c2
	if r1 == n || r2 == n || c1 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1 {
		return -4 * n
	}
	if r1 == n-1 && c1 == n-1 {
		return grid[r1][c1]
	}
	key := fmt.Sprintf("%d-%d-%d", r1, c1, c2)
	if v, ok := dp[key]; ok {
		return v
	}
	pick := grid[r1][c1]
	if r1 != r2 && c1 != c2 {
		pick += grid[r2][c2]
	}
	pick += max741(
		max741(
			dp741(grid, r1+1, c1, c2+1, dp), // ^ <
			dp741(grid, r1, c1+1, c2+1, dp), // < <
		),
		max741(
			dp741(grid, r1+1, c1, c2, dp), // ^ ^
			dp741(grid, r1, c1+1, c2, dp), // < ^
		),
	)
	dp[key] = pick
	return pick
}

// func main() {
// 	fmt.Printf("LeetCode 741. Cherry Pickup ...\n\n")

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
// 					{0, 1, -1},
// 					{1, 0, -1},
// 					{1, 1, 1},
// 				},
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{1, 1, -1},
// 					{1, -1, 1},
// 					{-1, 1, 1},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{1, 1, 1, 1, 0, 0, 0},
// 					{0, 0, 0, 1, 0, 0, 0},
// 					{0, 0, 0, 1, 0, 0, 1},
// 					{1, 0, 0, 1, 0, 0, 0},
// 					{0, 0, 0, 1, 0, 0, 0},
// 					{0, 0, 0, 1, 0, 0, 0},
// 					{0, 0, 0, 1, 1, 1, 1},
// 				},
// 			},
// 			want: 15,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{1, 1, -1, 1, 1},
// 					{1, 1, 1, 1, 1},
// 					{-1, 1, 1, -1, -1},
// 					{0, 1, 1, -1, 0},
// 					{1, 0, -1, 1, 0},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{1},
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{1, 1, 1, 1, -1, -1, -1, 1, 0, 0},
// 					{1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
// 					{0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
// 					{1, 1, 0, 1, 1, 1, 0, -1, 1, 1},
// 					{0, 0, 0, 0, 1, -1, 0, 0, 1, -1},
// 					{1, 0, 1, 1, 1, 0, 0, -1, 1, 0},
// 					{1, 1, 0, 1, 0, 0, 1, 0, 1, -1},
// 					{1, -1, 0, 1, 0, 0, 0, 1, -1, 1},
// 					{1, 0, -1, 0, -1, 0, 0, 1, 0, 0},
// 					{0, 0, -1, 0, 1, 0, 1, 0, 0, 1},
// 				},
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := cherryPickup2(tt.args.grid)
// 		fmt.Println(r)
// 	}

// }
