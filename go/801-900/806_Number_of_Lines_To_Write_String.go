package main

func numberOfLines(widths []int, s string) []int {
	limit := 100
	row, cur := 0, limit
	for _, c := range s {
		width := widths[c-'a']
		if cur+width > limit {
			row++
			cur = 0
		}
		cur += width
	}
	return []int{row, cur}
}

// func main() {
// 	fmt.Printf("LeetCode 806. Number of Lines To Write String ...\n\n")

// 	type args struct {
// 		widths []int
// 		s      string
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				widths: []int{
// 					10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
// 				},
// 				s: "abcdefghijklmnopqrstuvwxyz",
// 			},
// 			want: []int{3, 60},
// 		},
// 		{
// 			args: args{
// 				widths: []int{
// 					4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
// 				},
// 				s: "bbbcccdddaaa",
// 			},
// 			want: []int{2, 4},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numberOfLines(tt.args.widths, tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
