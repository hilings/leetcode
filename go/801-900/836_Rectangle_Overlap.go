package main

func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	if rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1] {
		return false
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 836. Rectangle Overlap ...\n\n")

// 	type args struct {
// 		rec1 []int
// 		rec2 []int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				rec1: []int{0, 0, 2, 2},
// 				rec2: []int{1, 1, 3, 3},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				rec1: []int{0, 0, 1, 1},
// 				rec2: []int{1, 0, 2, 1},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				rec1: []int{0, 0, 1, 1},
// 				rec2: []int{2, 2, 3, 3},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := isRectangleOverlap(tt.args.rec1, tt.args.rec2)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
