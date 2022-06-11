package main

func binaryGap(n int) int {
	r := 0
	last := -1
	for i := 0; n > 0; i, n = i+1, n>>1 {
		if n&1 == 0 {
			continue
		}
		if last == -1 {
			last = i
			continue
		}
		dis := i - last
		if dis > r {
			r = dis
		}
		last = i
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 868. Binary Gap ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 22,
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				n: 8,
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				n: 5,
// 			},
// 			want: 2,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := binaryGap(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
