package main

func swimInWater(grid [][]int) int {
	n := len(grid)
	reachable := map[int]bool{
		0: true,
	}
	todo := [][]int{
		{0, 0},
	}
	moves := [][]int{
		{0, -1}, // left
		{0, 1},  // right
		{-1, 0}, // up
		{1, 0},  // down
	}
	start := grid[0][0]
	if grid[n-1][n-1] > grid[0][0] {
		start = grid[n-1][n-1]
	}
	for t := start; t < n*n; t++ {
		todoNext := [][]int{}
		for k := 0; k < len(todo); k++ {
			i, j := todo[k][0], todo[k][1]
			stay := false             // whether need to check in next round
			for _, m := range moves { // check adjacent squares
				ii, jj := i+m[0], j+m[1]
				if ii < 0 || ii == n || jj < 0 || jj == n {
					continue
				}
				if grid[i][j] > t || grid[ii][jj] > t {
					stay = true
					continue
				}
				if ii == n-1 && jj == n-1 { // arrived~
					return t
				}

				key := ii*n + jj
				if _, ok := reachable[key]; !ok {
					todo = append(todo, []int{ii, jj})
					reachable[key] = true
				}
			}
			if stay {
				todoNext = append(todoNext, todo[k])
			}
		}
		todo = todoNext
	}

	return n*n - 1
}

// func main() {
// 	fmt.Printf("LeetCode 778. Swim in Rising Water ...\n\n")

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
// 					{0, 2},
// 					{1, 3},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{0, 1, 2, 3, 4},
// 					{24, 23, 22, 21, 5},
// 					{12, 13, 14, 15, 16},
// 					{11, 17, 18, 19, 20},
// 					{10, 9, 8, 7, 6},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{3, 2},
// 					{0, 1},
// 				},
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := swimInWater(tt.args.grid)
// 		fmt.Println(r)
// 	}
// }
