package main

import "fmt"

func reachingPoints(sx int, sy int, tx int, ty int) bool {
	q := [][]int{
		{sx, sy},
	}
	visited := map[string]bool{
		fmt.Sprintf("%d,%d", sx, sy): true,
	}

	for i := 0; i < len(q); i++ {
		x, y := q[i][0], q[i][1]
		if x == tx && y == ty {
			return true
		}
		for _, next := range [][]int{{x, x + y}, {x + y, y}} {
			if next[0] > tx || next[1] > ty { // out of range
				continue
			}
			key := fmt.Sprintf("%d,%d", next[0], next[1])
			if _, ok := visited[key]; !ok {
				q = append(q, next)
				visited[key] = true
			}
		}
	}

	return false
}

func reachingPoints2(sx int, sy int, tx int, ty int) bool {
	for tx >= sx && ty >= sy {
		if sx == tx && sy == ty {
			return true
		}
		// fmt.Printf("[sx, sy] = [%d, %d]\t[tx, ty] = [%d, %d]\n", sx, sy, tx, ty)
		if tx == ty || tx < sx || ty < sy {
			return false
		}
		if tx == sx {
			return (ty-sy)%tx == 0
		}
		if ty == sy {
			return (tx-sx)%ty == 0
		}

		if tx > ty {
			tx %= ty
		} else {
			ty %= tx
		}
	}
	return false
}

// func main() {
// 	fmt.Printf("LeetCode 780. Reaching Points ...\n\n")

// 	type args struct {
// 		sx int
// 		sy int
// 		tx int
// 		ty int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 1,
// 				tx: 3,
// 				ty: 5,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 1,
// 				tx: 2,
// 				ty: 2,
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 1,
// 				tx: 1,
// 				ty: 1,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				sx: 35,
// 				sy: 13,
// 				tx: 455955547,
// 				ty: 420098884,
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 1,
// 				tx: 455955547,
// 				ty: 420098884,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				sx: 2,
// 				sy: 1,
// 				tx: 1000000000,
// 				ty: 1,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 5,
// 				tx: 19,
// 				ty: 5,
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				sx: 2,
// 				sy: 3,
// 				tx: 4,
// 				ty: 7,
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				sx: 1,
// 				sy: 2,
// 				tx: 1000000000,
// 				ty: 2,
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := reachingPoints2(tt.args.sx, tt.args.sy, tt.args.tx, tt.args.ty)
// 		fmt.Printf("got = %v\texpect = %v\n", r, tt.want)
// 	}
// }
