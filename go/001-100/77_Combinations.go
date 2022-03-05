package main

func combine(n int, k int) [][]int {
	r := [][]int{}
	dfs(n, k, []int{}, &r, 1)
	return r
}

func dfs(n int, k int, cur []int, res *[][]int, start int) {
	// fmt.Printf("cur = %v, start = %d\n", cur, start)
	if len(cur) == k {
		// *res = append(*res, cur)	// may end up appending same slice address again
		*res = append(*res, append([]int{}, cur...))
		return
	}

	for i := start; i <= n; i++ {
		dfs(n, k, append(cur, i), res, i+1)
	}
}

// func main() {
// 	fmt.Printf("LeetCode 77. Combinations ...\n\n")

// 	type args struct {
// 		n int
// 		k int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				n: 4,
// 				k: 2,
// 			},
// 			want: [][]int{
// 				{1, 2},
// 				{1, 3},
// 				{1, 4},
// 				{2, 3},
// 				{2, 4},
// 				{3, 4},
// 			},
// 		},
// 		{
// 			args: args{
// 				n: 5,
// 				k: 4,
// 			},
// 			want: [][]int{
// 				{1, 2, 3, 4}, {1, 2, 3, 5}, {1, 2, 4, 5}, {1, 3, 4, 5}, {2, 3, 4, 5},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := combine(tt.args.n, tt.args.k)
// 		fmt.Println(r)
// 	}

// 	a := []int{}
// 	fmt.Println(a, cap(a))
// 	a = append(a, 1)
// 	fmt.Println(a, cap(a))
// 	a = append(a, 2)
// 	fmt.Println(a, cap(a))
// 	a = append(a, 3)
// 	fmt.Println(a, cap(a))

// 	v := [][]int{}

// 	s := append(a, 4)
// 	v = append(v, s)
// 	fmt.Printf("s = %v\t%p\n", s, &s)

// 	s = append(a, 5)
// 	fmt.Printf("s = %v\t%p\n", s, &s)
// 	v = append(v, s)

// 	fmt.Printf("v = %v\n", v)

// }
