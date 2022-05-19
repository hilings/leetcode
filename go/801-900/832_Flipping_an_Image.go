package main

func flipAndInvertImage(image [][]int) [][]int {
	n := len(image)
	for i := 0; i < n; i++ {
		for j := 0; j <= n-1-j; j++ {
			image[i][j], image[i][n-1-j] = image[i][n-1-j]^1, image[i][j]^1
		}
	}
	return image
}

// func main() {
// 	fmt.Printf("LeetCode 832. Flipping an Image ...\n\n")

// 	type args struct {
// 		image [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				image: [][]int{
// 					{1, 1, 0},
// 					{1, 0, 1},
// 					{0, 0, 0},
// 				},
// 			},
// 			want: [][]int{
// 				{1, 0, 0},
// 				{0, 1, 0},
// 				{1, 1, 1},
// 			},
// 		},
// 		{
// 			args: args{
// 				image: [][]int{
// 					{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0},
// 				},
// 			},
// 			want: [][]int{
// 				{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0},
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := flipAndInvertImage(tt.args.image)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
