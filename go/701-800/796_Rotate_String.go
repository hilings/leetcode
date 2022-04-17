package main

import (
	"strings"
)

func rotateString(s string, goal string) bool {
	return len(s) == len(goal) && strings.Contains(s+s, goal)
}

// func main() {
// 	fmt.Printf("LeetCode 796. Rotate String ...\n\n")

// 	type args struct {
// 		s    string
// 		goal string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				s:    "abcde",
// 				goal: "cdeab",
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				s:    "abcde",
// 				goal: "abced",
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := rotateString(tt.args.s, tt.args.goal)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
