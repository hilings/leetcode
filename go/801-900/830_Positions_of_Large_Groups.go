package main

func largeGroupPositions(s string) [][]int {
	r := [][]int{}
	for i, j := 0, 0; i < len(s); i = j + 1 {
		for j = i; j+1 < len(s) && s[j+1] == s[i]; j++ {
		}
		if j-i+1 >= 3 {
			r = append(r, []int{i, j})
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 830. Positions of Large Groups ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want [][]int
// 	}{
// 		{
// 			args: args{
// 				s: "abbxxxxzzy",
// 			},
// 			want: [][]int{{3, 6}},
// 		},
// 		{
// 			args: args{
// 				s: "abc",
// 			},
// 			want: [][]int{},
// 		},
// 		{
// 			args: args{
// 				s: "abcdddeeeeaabbbcd",
// 			},
// 			want: [][]int{{3, 5}, {6, 9}, {12, 14}},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := largeGroupPositions(tt.args.s)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
