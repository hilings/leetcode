package main

import (
	"fmt"
)

func rotatedDigits(n int) int {
	r := 0
	for i := 1; i <= n; i++ {
		if isValid(i) {
			r++
		}
	}
	return r
}

func isValid(k int) bool {
	// fmt.Printf("%d\n", k)
	rotated := 0
	for _, c := range fmt.Sprintf("%d", k) {
		switch c {
		case '0', '1', '8':
			rotated = rotated*10 + int(c-'0')
		case '2':
			rotated = rotated*10 + 5
		case '5':
			rotated = rotated*10 + 2
		case '6':
			rotated = rotated*10 + 9
		case '9':
			rotated = rotated*10 + 6
		default:
			return false
		}
	}
	// fmt.Printf("\trotated = %d\n", rotated)
	return rotated != k
}

// func main() {
// 	fmt.Printf("LeetCode 788. Rotated Digits ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 10,
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				n: 1,
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				n: 2,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				n: 10000,
// 			},
// 			want: 2320,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := rotatedDigits(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
