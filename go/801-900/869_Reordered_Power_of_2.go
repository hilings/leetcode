package main

import (
	"math"
)

func reorderedPowerOf2(n int) bool {
	target := digitMap(n)
	for i := 0; i < 32; i++ { // loop all possible power of 2 within int32
		if digitMap(1<<i) == target {
			return true
		}
	}
	return false
}

func digitMap(n int) int64 { // count per digit
	var r int64
	for ; n > 0; n /= 10 {
		r += int64(math.Pow10(n % 10))
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 869. Reordered Power of 2 ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				n: 1,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				n: 10,
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := reorderedPowerOf2(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
