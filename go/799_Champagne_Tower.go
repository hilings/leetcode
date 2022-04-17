package main

import (
	"math"
)

func champagneTower(poured int, query_row int, query_glass int) float64 {
	prev := []float64{float64(poured)} // how much the glass holds if no overflow
	for i := 1; i <= query_row; i++ {
		// fmt.Printf("i = %d\n", i)
		next := []float64{}
		for j := 0; j <= i; j++ {
			// fmt.Printf("\tj = %d\n", j)
			k := float64(0)
			if j < len(prev) {
				k += math.Max(prev[j]-1, 0) / 2 // get half if glass atop overflows
			}
			if j-1 >= 0 {
				k += math.Max(prev[j-1]-1, 0) / 2
			}
			if i == query_row && j == query_glass {
				return math.Min(k, 1)
			}
			next = append(next, k)
		}
		// fmt.Println(next)
		prev = next
	}
	return math.Min(prev[query_glass], 1)
}

// func main() {
// 	fmt.Printf("LeetCode 799. Champagne Tower ...\n\n")

// 	type args struct {
// 		poured      int
// 		query_row   int
// 		query_glass int
// 	}
// 	tests := []struct {
// 		args args
// 		want float64
// 	}{
// 		{
// 			args: args{
// 				poured:      1,
// 				query_row:   1,
// 				query_glass: 1,
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				poured:      2,
// 				query_row:   1,
// 				query_glass: 1,
// 			},
// 			want: 0.5,
// 		},
// 		{
// 			args: args{
// 				poured:      100000009,
// 				query_row:   33,
// 				query_glass: 17,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				poured:      8,
// 				query_row:   3,
// 				query_glass: 2,
// 			},
// 			want: 0.875,
// 		},
// 		{
// 			args: args{
// 				poured:      100,
// 				query_row:   20,
// 				query_glass: 10,
// 			},
// 			want: 0.70592,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := champagneTower(tt.args.poured, tt.args.query_row, tt.args.query_glass)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
