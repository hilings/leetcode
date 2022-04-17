package main

import "fmt"

func customSortString(order string, s string) string {
	setS := map[rune]int{} // count per char in s
	for _, c := range s {
		setS[c]++
	}
	r := ""
	for _, c := range order {
		if count, ok := setS[c]; ok {
			for i := 0; i < count; i++ {
				r += fmt.Sprintf("%c", c)
			}
			setS[c] = 0
		}
	}
	for c, count := range setS {
		for i := 0; i < count; i++ {
			r += fmt.Sprintf("%c", c)
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 791. Custom Sort String ...\n\n")

// 	type args struct {
// 		order string
// 		s     string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				order: "cba",
// 				s:     "abcd",
// 			},
// 			want: "cbad",
// 		},
// 		{
// 			args: args{
// 				order: "cbafg",
// 				s:     "abcd",
// 			},
// 			want: "cbad",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := customSortString(tt.args.order, tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
