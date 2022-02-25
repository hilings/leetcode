package main

func orderOfLargestPlusSign(n int, mines [][]int) int {
	grid := make([][]int, 0, n)
	for i := 0; i < n; i++ {
		row := make([]int, n, n)
		for j := 0; j < n; j++ {
			row[j] = 1
		}
		grid = append(grid, row)
	}
	for _, ij := range mines {
		grid[ij[0]][ij[1]] = 0
	}
	// fmt.Println(grid)

	for k := (n + 1) / 2; k >= 1; k-- {
		for i := -1 + k; i <= n-k; i++ {
			for j := -1 + k; j <= n-k; j++ {
				if isPlus(grid, i, j, k) {
					return k
				}
			}
		}
	}
	return 0
}

func isPlus(grid [][]int, r int, c int, k int) bool {
	for i := r - k + 1; i <= r+k-1; i++ {
		if grid[i][c] == 0 {
			return false
		}
	}
	for j := c - k + 1; j <= c+k-1; j++ {
		if grid[r][j] == 0 {
			return false
		}
	}
	return true
}

func orderOfLargestPlusSign2(n int, mines [][]int) int {
	grid := make([][]int, 0, n)
	for i := 0; i < n; i++ {
		row := make([]int, n, n)
		for j := 0; j < n; j++ {
			row[j] = n
		}
		grid = append(grid, row)
	}
	for _, ij := range mines {
		grid[ij[0]][ij[1]] = 0
	}
	// fmt.Println(grid)

	for i := 0; i < n; i++ { // check four direction in one loop
		for j, left := 0, 0; j < n; j++ { // left
			if grid[i][j] == 0 {
				left = 0
			} else {
				left++
			}
			if left < grid[i][j] {
				grid[i][j] = left
			}
		}
		for j, right := n-1, 0; j >= 0; j-- { // right
			if grid[i][j] == 0 {
				right = 0
			} else {
				right++
			}
			if right < grid[i][j] {
				grid[i][j] = right
			}
		}
		for j, up := 0, 0; j < n; j++ { // up
			if grid[j][i] == 0 {
				up = 0
			} else {
				up++
			}
			if up < grid[j][i] {
				grid[j][i] = up
			}
		}
		for j, down := n-1, 0; j >= 0; j-- { // down
			if grid[j][i] == 0 {
				down = 0
			} else {
				down++
			}
			if down < grid[j][i] {
				grid[j][i] = down
			}
		}
	}

	r := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] > r {
				r = grid[i][j]
			}
		}
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 764. Largest Plus Sign ...\n\n")

// 	type args struct {
// 		n     int
// 		mines [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 5,
// 				mines: [][]int{
// 					{4, 2},
// 				},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				n: 1,
// 				mines: [][]int{
// 					{0, 0},
// 				},
// 			},
// 			want: 0,
// 		},
// 	}

// 	for _, tt := range tests {
// 		r := orderOfLargestPlusSign(tt.args.n, tt.args.mines)
// 		fmt.Println(r)
// 		r2 := orderOfLargestPlusSign2(tt.args.n, tt.args.mines)
// 		fmt.Println(r2)
// 	}
// }
