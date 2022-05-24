package main

func perm(set []int) [][]int {
	r := [][]int{}
	helper([]int{}, set, &r)
	return r
}

func helper(cur []int, set []int, r *[][]int) {
	if len(set) == 0 {
		*r = append(*r, cur)
	}
	for i := 0; i < len(set); i++ {
		next := append([]int{}, cur...)
		next = append(next, set[i])
		nextset := append([]int{}, set[0:i]...)
		nextset = append(nextset, set[i+1:]...)
		helper(next, nextset, r)
	}
}

// func main() {
// 	fmt.Printf("Interview, Lanhu R1, permutation ...\n\n")

// 	type args struct {
// 		set []int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				set: []int{1, 2, 3},
// 			},
// 			want: [][]int{
// 				{1, 2, 3},
// 				{1, 3, 2},
// 				{2, 1, 3},
// 				{2, 3, 1},
// 				{3, 1, 2},
// 				{3, 2, 1},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := perm(tt.args.set)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
