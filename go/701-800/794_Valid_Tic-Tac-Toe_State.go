package main

import "fmt"

func validTicTacToe(board []string) bool {
	const n = 3
	countX, countO := 0, 0
	winX, winO := false, false
	countDiag1, countDiag2 := 0, 0
	for i := 0; i < n; i++ {
		countRow, countCol := 0, 0
		for j := 0; j < n; j++ {
			// check row i
			if board[i][j] == 'X' {
				countX++
				countRow++
			} else if board[i][j] == 'O' {
				countO++
				countRow--
			}

			// check col i
			if board[j][i] == 'X' {
				countCol++
			} else if board[j][i] == 'O' {
				countCol--
			}
		}

		if countRow == n {
			winX = true
		} else if countRow == -n {
			winO = true
		}

		if countCol == n {
			winX = true
		} else if countCol == -n {
			winO = true
		}

		// check diagonal
		if board[i][i] == 'X' {
			countDiag1++
		} else if board[i][i] == 'O' {
			countDiag1--
		}

		if board[n-1-i][i] == 'X' {
			countDiag2++
		} else if board[n-1-i][i] == 'O' {
			countDiag2--
		}
	}

	if countDiag1 == n {
		winX = true
	} else if countDiag1 == -n {
		winO = true
	}

	if countDiag2 == n {
		winX = true
	} else if countDiag2 == -n {
		winO = true
	}

	fmt.Println(countX, countO)
	fmt.Println(winX, winO)

	if countX > (n*n+1)/2 || countO > (n*n+1)/2 { // count > half board
		return false
	}
	if countX < countO || countX > countO+1 { // diff > 1
		return false
	}

	if winX && winO { // both win
		return false
	}
	if winX && countX != countO+1 { // X win, count must X = O+1
		return false
	}
	if winO && countX != countO { // O win, count must equal
		return false
	}

	return true
}

// func main() {
// 	fmt.Printf("LeetCode 794. Valid Tic-Tac-Toe State ...\n\n")

// 	type args struct {
// 		board []string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				board: []string{
// 					"O  ",
// 					"   ",
// 					"   ",
// 				},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				board: []string{
// 					"XOX",
// 					" X ",
// 					"   ",
// 				},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				board: []string{
// 					"XOX",
// 					"O O",
// 					"XOX",
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				board: []string{
// 					"XXX",
// 					"XOO",
// 					"OO ",
// 				},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				board: []string{
// 					"OXX",
// 					"XOX",
// 					"OXO",
// 				},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := validTicTacToe(tt.args.board)
// 		fmt.Printf("got = %v, want = %v\n--------\n", r, tt.want)
// 	}
// }
