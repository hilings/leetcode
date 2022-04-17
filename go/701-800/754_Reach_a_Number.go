package main

import (
	"math"
)

func reachNumber(target int) int {
	if target < 0 {
		target = -target
	}

	// m := map[int]map[int]bool{
	// 	1: map[int]bool{
	// 		1:  true,
	// 		-1: true,
	// 	},
	// }
	// n := 20
	// for i := 2; i <= n; i++ {
	// 	m[i] = map[int]bool{}
	// 	for k := range m[i-1] {
	// 		m[i][k-i] = true
	// 		m[i][k+i] = true
	// 	}
	// 	// fmt.Printf("i = %d, %v\n", i, m[i])
	// }

	start := int(math.Ceil((math.Sqrt(8*float64(target)+1) - 1) / 2))
	// fmt.Printf("target = %d, start = %d, cap = %d\n", target, start, (start*(start+1))/2)
	cap := start * (start + 1) / 2
	if (cap-target)%2 == 0 {
		return start
	}
	return start + 1 + (cap+(start+1)-target)%2
}

// func main() {
// 	fmt.Printf("LeetCode 754. Reach a Number ...\n\n")

// 	type args struct {
// 		target int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				target: 1,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				target: 2,
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				target: 3,
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				target: 4,
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				target: 5,
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				target: 6,
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				target: 7,
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				target: 8,
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				target: 9,
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				target: 10,
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				target: 23,
// 			},
// 			want: 9,
// 		},
// 		{
// 			args: args{
// 				target: 29,
// 			},
// 			want: 9,
// 		},
// 	}
// 	for _, tt := range tests {
// 		got := reachNumber(tt.args.target)
// 		fmt.Printf("target = %d, got = %d, expected = %d\t%v\n\n", tt.args.target, got, tt.want, got == tt.want)
// 	}
// }
