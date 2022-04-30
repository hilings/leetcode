package main

func soupServings(n int) float64 {
	if n > 5000 { // 0.99999 ~= 1
		return 1
	}

	dp := make(map[int]map[int]float64)
	return f808(n, n, dp)
}

func f808(a int, b int, dp map[int]map[int]float64) float64 {
	switch {
	case a <= 0 && b <= 0:
		return 0.5
	case a <= 0:
		return 1
	case b <= 0:
		return 0
	case dp[a] != nil && dp[a][b] > 0:
		return dp[a][b]
	}

	if _, ok := dp[a]; !ok {
		dp[a] = make(map[int]float64)
	}
	for sa := 100; sa >= 25; sa -= 25 {
		dp[a][b] += f808(a-sa, b-(100-sa), dp)
	}
	dp[a][b] *= 0.25
	return dp[a][b]
}

// func main() {
// 	fmt.Printf("LeetCode 808. Soup Servings ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want float64
// 	}{
// 		{
// 			args: args{
// 				n: 50,
// 			},
// 			want: 0.625,
// 		},
// 		{
// 			args: args{
// 				n: 100,
// 			},
// 			want: 0.71875,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := soupServings(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
