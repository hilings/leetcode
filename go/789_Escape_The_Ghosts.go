package main

import (
	"fmt"
	"math"
)

func escapeGhosts(ghosts [][]int, target []int) bool {
	moves := int(math.Abs(float64(target[0])) + math.Abs(float64(target[1])))
	fmt.Printf("%d\n", moves)
	for _, ghost := range ghosts {
		_moves := int(math.Abs(float64(ghost[0]-target[0])) + math.Abs(float64(ghost[1]-target[1])))
		// fmt.Printf("\t%d\n", _moves)
		if _moves <= moves {
			return false
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 789. Escape The Ghosts ...\n\n")

// 	type args struct {
// 		ghosts [][]int
// 		target []int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				ghosts: [][]int{
// 					{1, 0},
// 					{0, 3},
// 				},
// 				target: []int{0, 1},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				ghosts: [][]int{
// 					{1, 0},
// 				},
// 				target: []int{2, 0},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				ghosts: [][]int{
// 					{2, 0},
// 				},
// 				target: []int{1, 0},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				ghosts: [][]int{
// 					{1, 9},
// 					{2, -5},
// 					{3, 8},
// 					{9, 8},
// 					{-1, 3},
// 				},
// 				target: []int{8, -10},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := escapeGhosts(tt.args.ghosts, tt.args.target)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
