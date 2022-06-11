package main

func transpose(matrix [][]int) [][]int {
	r := make([][]int, len(matrix[0]))
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			r[j] = append(r[j], matrix[i][j])
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 867. Transpose Matrix ...\n\n")

// 	type args struct {
// 		matrix [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				matrix: [][]int{
// 					{1, 2, 3},
// 					{4, 5, 6},
// 					{7, 8, 9},
// 				},
// 			},
// 			want: [][]int{
// 				{1, 4, 7},
// 				{2, 5, 8},
// 				{3, 6, 9},
// 			},
// 		},
// 		{
// 			args: args{
// 				matrix: [][]int{
// 					{1, 2, 3},
// 					{4, 5, 6},
// 				},
// 			},
// 			want: [][]int{
// 				{1, 4},
// 				{2, 5},
// 				{3, 6},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := transpose(tt.args.matrix)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
