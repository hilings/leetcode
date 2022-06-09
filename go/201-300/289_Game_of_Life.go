package main

func gameOfLife(board [][]int) {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			next(board, i, j)
		}
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] >= 2 {
				board[i][j] = 3 - board[i][j]
			}
		}
	}
}

func next(board [][]int, i, j int) {
	m, n := len(board), len(board[0])
	count := 0
	for x := i - 1; x <= i+1; x++ {
		for y := j - 1; y <= j+1; y++ {
			if x < 0 || x == m || y < 0 || y == n || (x == i && y == j) {
				continue
			}
			if board[x][y]&1 == 1 {
				count++
			}
		}
	}
	if board[i][j] == 0 && count == 3 {
		board[i][j] = 2 // now dead, next live
	}
	if board[i][j] == 1 && (count < 2 || count > 3) {
		board[i][j] = 3 // now live, next dead
	}
}

// func main() {
// 	fmt.Printf("LeetCode 289. Game of Life ...\n\n")

// 	type args struct {
// 		board [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				board: [][]int{
// 					{0, 1, 0},
// 					{0, 0, 1},
// 					{1, 1, 1},
// 					{0, 0, 0},
// 				},
// 			},
// 			want: [][]int{
// 				{0, 0, 0},
// 				{1, 0, 1},
// 				{0, 1, 1},
// 				{0, 1, 0},
// 			},
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{1, 1},
// 					{1, 0},
// 				},
// 			},
// 			want: [][]int{
// 				{1, 1},
// 				{1, 1},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		gameOfLife(tt.args.board)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", tt.args.board, tt.want)
// 	}
// }
