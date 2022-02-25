package main

func isToeplitzMatrix(matrix [][]int) bool {
	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			if matrix[i][j] != matrix[i-1][j-1] {
				return false
			}
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 766. Toeplitz Matrix ...\n\n")

// 	type args struct {
// 		matrix [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				matrix: [][]int{
// 					{1, 2, 3, 4},
// 					{5, 1, 2, 3},
// 					{9, 5, 1, 2},
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				matrix: [][]int{
// 					{1, 2},
// 					{2, 2},
// 				},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := isToeplitzMatrix(tt.args.matrix)
// 		fmt.Println(r)
// 	}
// }
