package main

import (
	"math"
)

func largestTriangleArea(points [][]int) float64 {
	n := len(points)
	var r float64
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				s := areaTriangle(points[i], points[j], points[k])
				if s > r {
					r = s
				}
			}
		}
	}
	return r
}

func areaTriangle(p1, p2, p3 []int) float64 {
	x1, y1, x2, y2, x3, y3 := p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]
	return 0.5 * math.Abs(float64((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)))
}

// func main() {
// 	fmt.Printf("LeetCode 812. Largest Triangle Area ...\n\n")

// 	type args struct {
// 		points [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want float64
// 	}{
// 		{
// 			args: args{
// 				points: [][]int{
// 					{0, 0},
// 					{0, 1},
// 					{1, 0},
// 					{0, 2},
// 					{2, 0},
// 				},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				points: [][]int{
// 					{1, 0},
// 					{0, 0},
// 					{0, 1},
// 				},
// 			},
// 			want: 0.5,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := largestTriangleArea(tt.args.points)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
