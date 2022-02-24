package main

import (
	"fmt"
	"sort"
)

func makeLargestSpecial(s string) string {
	if s == "" {
		return ""
	}
	fmt.Printf("s = %s\n", s)
	count := 0
	l := []string{}
	for i, j := 0, 0; j < len(s); j++ {
		if s[j] == '1' {
			count++
		} else {
			count--
		}
		if count == 0 {
			// special make start with 1 and end with 0
			// split substring in the middleware
			_s := "1" + makeLargestSpecial(s[i+1:j]) + "0"
			fmt.Printf("\t%s\n", _s)
			l = append(l, _s)
			i = j + 1
		}
	}
	sort.Slice(l, func(i, j int) bool {
		return l[i] > l[j]
	})
	r := ""
	for _, _s := range l {
		r += _s
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 761. Special Binary String ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s: "11011000",
// 			},
// 			want: "11100100",
// 		},
// 		{
// 			args: args{
// 				s: "10",
// 			},
// 			want: "10",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := makeLargestSpecial(tt.args.s)
// 		fmt.Println(r)
// 	}
// }
