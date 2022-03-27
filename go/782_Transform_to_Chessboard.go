package main

func movesToChessboard(board [][]int) int {
	n := len(board)

	typeRow, typeCol := []int{1, 0}, []int{1, 0}
	for i := 1; i < n; i++ {
		// check row
		if board[i][0] == board[0][0] { // if row i is same with row 0
			typeRow[0]++
			for j := 1; j < n; j++ { // each col of row i must be same with row 0
				if board[i][j] != board[0][j] {
					return -1
				}
			}
		} else { // row i is different from row 0
			typeRow[1]++
			for j := 1; j < n; j++ { // each col of row i must be different from row 0
				if board[i][j] == board[0][j] {
					return -1
				}
			}
		}

		// check col
		if board[0][i] == board[0][0] { // if col i is same with col 0
			typeCol[0]++
			for j := 1; j < n; j++ { // each row of col i must be same with col 0
				if board[j][i] != board[j][0] {
					return -1
				}
			}
		} else { //	col i is different from col 0
			typeCol[1]++
			for j := 1; j < n; j++ { // each row or col i must be different from col 0
				if board[j][i] == board[j][0] {
					return -1
				}
			}
		}
	}

	if n%2 == 0 { // two types must be same amount
		if typeRow[0] != typeRow[1] || typeCol[0] != typeCol[1] {
			return -1
		}
	} else { // two types must be within 1 diff
		if typeRow[0]-typeRow[1] > 1 || typeRow[0]-typeRow[1] < -1 ||
			typeCol[0]-typeCol[1] > 1 || typeCol[01]-typeCol[1] < -1 {
			return -1
		}
	}

	// count of moves needed
	swapRow, swapCol := []int{0, 0}, []int{0, 0}
	for i := 0; i < n; i++ { // if first cell is 0
		if board[0][i] != i%2 {
			swapRow[0]++
		}
		if board[i][0] != i%2 {
			swapCol[0]++
		}
	}
	swapRow[1], swapCol[1] = n-swapRow[0], n-swapCol[0] // if first cell is 1

	minRow, minCol := n, n
	for i := 0; i < 2; i++ {
		if swapRow[i]%2 == 0 && swapRow[i] < minRow {
			minRow = swapRow[i]
		}
		if swapCol[i]%2 == 0 && swapCol[i] < minCol {
			minCol = swapCol[i]
		}
	}

	return minRow/2 + minCol/2
}

// func main() {
// 	fmt.Printf("LeetCode 782. Transform to Chessboard ...\n\n")

// 	type args struct {
// 		board [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				board: [][]int{
// 					{0, 1, 1, 0},
// 					{0, 1, 1, 0},
// 					{1, 0, 0, 1},
// 					{1, 0, 0, 1},
// 				},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{0, 1},
// 					{1, 0},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{1, 0},
// 					{1, 0},
// 				},
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{1, 1, 0},
// 					{1, 1, 0},
// 					{0, 0, 1},
// 				},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{1, 0},
// 					{0, 1},
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{0, 0, 1, 1},
// 					{1, 1, 0, 0},
// 					{0, 1, 0, 1},
// 					{1, 0, 1, 0},
// 				},
// 			},
// 			want: -1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := movesToChessboard(tt.args.board)
// 		fmt.Printf("got = %v, expect = %v\n", r, tt.want)
// 	}
// }
