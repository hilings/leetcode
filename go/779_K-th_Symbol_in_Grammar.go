package main

func kthGrammar(n int, k int) int {
	// fmt.Printf("n = %d, k = %d\n", n, k)
	if n == 1 {
		return 0
	}
	mReplace := map[int][]int{
		0: {0, 1},
		1: {1, 0},
	}

	k-- // 0-indexed
	return mReplace[kthGrammar(n-1, k/2+1)][k%2]
}

// func main() {
// 	fmt.Printf("LeetCode 779. K-th Symbol in Grammar ...\n\n")

// 	type args struct {
// 		n int
// 		k int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 1,
// 				k: 1,
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				n: 2,
// 				k: 1,
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				n: 2,
// 				k: 2,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				n: 20,
// 				k: 200,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				n: 25,
// 				k: 300,
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := kthGrammar(tt.args.n, tt.args.k)
// 		fmt.Println(r)
// 	}
// }
