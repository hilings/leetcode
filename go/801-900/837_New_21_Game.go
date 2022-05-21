package main

import "fmt"

func new21Game2(n int, k int, maxPts int) float64 {
	if k == 0 || n >= k+maxPts {
		return 1
	}
	dp := make([]float64, n+1)
	dp[0] = 1.0
	var wsum float64 = 1.0
	var r float64 = 0
	for i := 1; i <= n; i++ {
		dp[i] = wsum / float64(maxPts)
		if i < k { // game ends if i reach k
			wsum += dp[i]
		} else {
			r += dp[i] // accumulate probabilities of ending game with k~n points
		}
		if i-maxPts >= 0 {
			wsum -= dp[i-maxPts] // accumulate sum of window size of maxPts
		}
	}
	return r
}

func new21Game(n int, k int, maxPts int) float64 {
	m := map[string]float64{}
	return dp837(n, k, maxPts, m)
}

func dp837(n int, k int, maxPts int, m map[string]float64) float64 {
	key := fmt.Sprintf("%d:%d", n, k)
	// fmt.Println(key)
	if v, ok := m[key]; ok {
		return v
	}

	if k <= 0 {
		if n >= 0 {
			return 1
		}
		return 0
	}

	var p float64 = 1.0 / float64(maxPts)
	var r float64
	for i := 1; i <= maxPts && i <= n; i++ {
		r += dp837(n-i, k-i, maxPts, m)
	}
	r *= p

	m[key] = r
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 837. New 21 Game ...\n\n")

// 	type args struct {
// 		n      int
// 		k      int
// 		maxPts int
// 	}
// 	tests := []struct {
// 		args args
// 		want float64
// 	}{
// 		{
// 			args: args{
// 				n:      10,
// 				k:      1,
// 				maxPts: 10,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				n:      6,
// 				k:      1,
// 				maxPts: 10,
// 			},
// 			want: 0.6,
// 		},
// 		{
// 			args: args{
// 				n:      21,
// 				k:      17,
// 				maxPts: 10,
// 			},
// 			want: 0.73278,
// 		},
// 		{
// 			args: args{
// 				n:      9811,
// 				k:      8776,
// 				maxPts: 1096,
// 			},
// 			want: 0.99696,
// 		},
// 		{
// 			args: args{
// 				n:      0,
// 				k:      0,
// 				maxPts: 1,
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := new21Game(tt.args.n, tt.args.k, tt.args.maxPts)
// 		fmt.Printf("got = %.5f, want = %v\n", r, tt.want)

// 		r = new21Game2(tt.args.n, tt.args.k, tt.args.maxPts)
// 		fmt.Printf("got = %.5f, want = %v\n\n", r, tt.want)
// 	}

// }
