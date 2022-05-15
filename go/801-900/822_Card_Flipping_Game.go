package main

func flipgame(fronts []int, backs []int) int {
	n := len(fronts)
	mBad := map[int]bool{}
	for i := 0; i < n; i++ {
		if fronts[i] == backs[i] {
			mBad[fronts[i]] = true
		}
	}

	r := 2001
	for i := 0; i < n; i++ {
		if !mBad[fronts[i]] && fronts[i] < r {
			r = fronts[i]
		}
		if !mBad[backs[i]] && backs[i] < r {
			r = backs[i]
		}
	}

	if r == 2001 {
		return 0
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 822. Card Flipping Game ...\n\n")

// 	type args struct {
// 		fronts []int
// 		backs  []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				fronts: []int{1, 2, 4, 4, 7},
// 				backs:  []int{1, 3, 4, 1, 3},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				fronts: []int{1},
// 				backs:  []int{1},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := flipgame(tt.args.fronts, tt.args.backs)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
