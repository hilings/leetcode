package main

import "fmt"

func slidingPuzzle(board [][]int) int {
	row, col := len(board), len(board[0])

	genKey := func(board [][]int) string { // convert [][]int -> string
		key := ""
		for _, v := range board {
			for _, a := range v {
				key += fmt.Sprintf("%d", a)
			}
		}
		return key
	}

	target := genKey(board)
	start := genKey([][]int{{1, 2, 3}, {4, 5, 0}})
	if start == target {
		return 0
	}
	m := map[string]int{start: 0} // step to reach state
	l := []string{start}          // queue to process
	for i, j := 0, 0; i < len(l); i++ {
		cur := l[i]
		// fmt.Printf("l[%d] = %s, step = %d\n", i, cur, m[cur])
		for j = 0; j < len(cur); j++ {
			if cur[j] == '0' { // index of 0
				break
			}
		}
		// fmt.Printf("\t0 index = %d\n", j)

		if j%col > 0 { // 0 swap left
			next := cur[:j-1] + cur[j:j+1] + cur[j-1:j] + cur[j+1:]
			// fmt.Printf("\tnext l = %s", next)
			if next == target {
				// fmt.Printf("\tarrived\n")
				return m[cur] + 1
			}
			if _, ok := m[next]; !ok {
				l = append(l, next)
				m[next] = m[cur] + 1
				// fmt.Printf("\t+\n")
			} else {
				// fmt.Printf("\tpass\n")
			}
		}
		if j%col < col-1 { // 0 swap right
			next := cur[:j] + cur[j+1:j+2] + cur[j:j+1] + cur[j+2:]
			// fmt.Printf("\tnext r = %s", next)
			if next == target {
				// fmt.Printf("\tarrived\n")
				return m[cur] + 1
			}
			if _, ok := m[next]; !ok {
				l = append(l, next)
				m[next] = m[cur] + 1
				// fmt.Printf("\t+\n")
			} else {
				// fmt.Printf("\tpass\n")
			}
		}
		if j/col > 0 { // 0 swap up
			next := cur[:j-col] + cur[j:j+1] + cur[j-col+1:j] + cur[j-col:j-col+1] + cur[j+1:]
			// fmt.Printf("\tnext u = %s", next)
			if next == target {
				// fmt.Printf("\tarrived\n")
				return m[cur] + 1
			}
			if _, ok := m[next]; !ok {
				l = append(l, next)
				m[next] = m[cur] + 1
				// fmt.Printf("\t+\n")
			} else {
				// fmt.Printf("\tpass\n")
			}
		}
		if j/col < row-1 { // 0 swap down
			next := cur[:j] + cur[j+col:j+col+1] + cur[j+1:j+col] + cur[j:j+1] + cur[j+col+1:]
			// fmt.Printf("\tnext d = %s", next)
			if next == target {
				// fmt.Printf("\tarrived\n")
				return m[cur] + 1
			}
			if _, ok := m[next]; !ok {
				l = append(l, next)
				m[next] = m[cur] + 1
				// fmt.Printf("\t+\n")
			} else {
				// fmt.Printf("\tpass\n")
			}
		}
	}

	return -1
}

// func main() {
// 	fmt.Printf("LeetCode 773. Sliding Puzzle ...\n\n")

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
// 					{1, 2, 3},
// 					{4, 0, 5},
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{1, 2, 3},
// 					{5, 4, 0},
// 				},
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				board: [][]int{
// 					{4, 1, 2},
// 					{5, 0, 3},
// 				},
// 			},
// 			want: 5,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := slidingPuzzle(tt.args.board)
// 		fmt.Println(r)
// 	}
// }
