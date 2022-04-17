package main

import "fmt"

func allPathsSourceTarget(graph [][]int) [][]int {
	n := len(graph)
	r := [][]int{}

	q := [][]int{{0}} // todo queue
	for len(q) > 0 {
		fmt.Printf("another round, q = %v ...\n", q)
		todo := [][]int{} // next round
		for _, path := range q {
			fmt.Printf("\tpath = %v\n", path)
			tail := path[len(path)-1]
			for _, neighbor := range graph[tail] {
				fmt.Printf("\t\tneighbor = %d\n", neighbor)
				p := make([]int, len(path))
				copy(p, path)
				p = append(p, neighbor)
				if neighbor == n-1 {
					r = append(r, p)
					fmt.Printf("\t\tfound one %v\n", p)
				} else {
					todo = append(todo, p)
					fmt.Printf("\t\tappending path %v\n", p)
				}
			}
		}
		q = todo
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 797. All Paths From Source to Target ...\n\n")

// 	type args struct {
// 		graph [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{1, 2},
// 					{3},
// 					{3},
// 					{},
// 				},
// 			},
// 			want: [][]int{
// 				{0, 1, 3},
// 				{0, 2, 3},
// 			},
// 		},
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{4, 3, 1},
// 					{3, 2, 4},
// 					{3},
// 					{4},
// 					{},
// 				},
// 			},
// 			want: [][]int{
// 				{0, 4},
// 				{0, 3, 4},
// 				{0, 1, 3, 4},
// 				{0, 1, 2, 3, 4},
// 				{0, 1, 4},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := allPathsSourceTarget(tt.args.graph)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
