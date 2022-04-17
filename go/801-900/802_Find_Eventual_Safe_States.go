package main

import "fmt"

func eventualSafeNodes(graph [][]int) []int {
	terminal := make([]bool, len(graph))

	for i, neighbors := range graph {
		if len(neighbors) == 0 { // find terminal node
			fmt.Printf("\toriginal terminal %d\n", i)
			terminal[i] = true
		}
	}

	for done := false; !done; {
		fmt.Printf("another round, terminal = %v\n", terminal)
		done = true
		for i, neighbors := range graph { // check node i if all adjacent nodes are terminal
			if terminal[i] {
				continue
			}
			total, count := len(neighbors), 0
			for _, adjacent := range neighbors {
				if !terminal[adjacent] {
					break
				}
				count++
			}
			if count == total {
				fmt.Printf("\tfind terminal %d\n", i)
				terminal[i] = true
				done = false
			}
		}
	}

	fmt.Println(terminal)

	r := []int{}
	for i, b := range terminal {
		if b {
			r = append(r, i)
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 802. Find Eventual Safe States ...\n\n")

// 	type args struct {
// 		graph [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{1, 2},
// 					{2, 3},
// 					{5},
// 					{0},
// 					{5},
// 					{},
// 					{},
// 				},
// 			},
// 			want: []int{2, 4, 5, 6},
// 		},
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{1, 2, 3, 4},
// 					{1, 2},
// 					{3, 4},
// 					{0, 4},
// 					{},
// 				},
// 			},
// 			want: []int{4},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := eventualSafeNodes(tt.args.graph)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
