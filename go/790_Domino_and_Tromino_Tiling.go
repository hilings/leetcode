package main

func numTilings(n int) int {
	limit := 1000000007
	dp := []int{
		1, // 0
		1, // 2*1
		2, // 2*2
	}
	for i := 3; i <= n; i++ {
		next := dp[i-1] + dp[i-2]
		for j := i - 3; j >= 0; j-- { // *   * *   ... * *
			next += dp[j] * 2 //         * *   * * ...   *
		}
		dp = append(dp, next%limit)
	}
	return dp[n]
}

// func main() {
// 	fmt.Printf("LeetCode 790. Domino and Tromino Tiling ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 3,
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				n: 1,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				n: 4,
// 			},
// 			want: 11,
// 		},
// 		{
// 			args: args{
// 				n: 5,
// 			},
// 			want: 24,
// 		},
// 		{
// 			args: args{
// 				n: 10,
// 			},
// 			want: 1255,
// 		},
// 		{
// 			args: args{
// 				n: 1000,
// 			},
// 			want: 979232805,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numTilings(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
