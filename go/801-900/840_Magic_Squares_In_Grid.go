package main

func numMagicSquaresInside(grid [][]int) int {
	const w = 3
	r := 0
	for i := 0; i <= len(grid)-w; i++ {
		for j := 0; j <= len(grid[0])-w; j++ {
			// fmt.Printf("%d %d\n", i, j)
			if isMagic(grid, i, j) {
				r++
			}
		}
	}
	return r
}

func isMagic(grid [][]int, row, col int) bool {
	m := map[int]bool{}
	const w = 3
	sumd1 := grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2]
	sumd2 := grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col]
	if sumd1 != sumd2 {
		return false
	}
	for i := 0; i < 3; i++ {
		sumr := 0
		sumc := 0
		for j := 0; j < 3; j++ {
			a := grid[row+i][col+j]
			if _, ok := m[a]; ok || a < 1 || a > 9 {
				return false
			}
			m[a] = true
			sumr += grid[row+i][col+j]
			sumc += grid[row+j][col+i]
		}
		if sumr != sumd1 || sumc != sumd1 {
			return false
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 840. Magic Squares In Grid ...\n\n")

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
// 					{4, 3, 8, 4},
// 					{9, 5, 1, 9},
// 					{2, 7, 6, 2},
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				grid: [][]int{
// 					{8},
// 				},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numMagicSquaresInside(tt.args.grid)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
