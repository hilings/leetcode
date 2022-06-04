package main

func mirrorReflection(p int, q int) int {
	for i, sum := 1, 0; i <= 1000; i++ {
		sum += q
		if sum%p == 0 {
			if i%2 == 0 {
				return 2
			} else if sum/p%2 == 1 {
				return 1
			} else {
				return 0
			}
		}
	}
	return 0
}

// func main() {
// 	fmt.Printf("LeetCode 858. Mirror Reflection ...\n\n")

// 	type args struct {
// 		p int
// 		q int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				p: 2,
// 				q: 1,
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				p: 3,
// 				q: 1,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				p: 3,
// 				q: 2,
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := mirrorReflection(tt.args.p, tt.args.q)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
