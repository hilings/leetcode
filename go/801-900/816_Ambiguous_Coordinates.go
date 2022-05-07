package main

import "fmt"

func ambiguousCoordinates(s string) []string {
	r := []string{}
	s = s[1 : len(s)-1]

	for i := 1; i < len(s); i++ {
		s1, s2 := s[:i], s[i:]
		// fmt.Println(s1, s2)

		for _, t1 := range parse(s1) {
			for _, t2 := range parse(s2) {
				r = append(r, fmt.Sprintf("(%s, %s)", t1, t2))
			}
		}
	}

	return r
}

// all valid numbers
func parse(s string) []string {
	r := []string{}
	if s[0] != '0' { // no leading 0
		r = append(r, s)        // s itself is valid
		if s[len(s)-1] == '0' { // trailing 0 invalid
			return r
		}
		for i := 1; i < len(s); i++ { // point can be anywhere
			r = append(r, s[:i]+"."+s[i:])
		}
	} else if len(s) == 1 { // just 0
		r = append(r, s)
	} else if s[len(s)-1] != '0' { // just one valid number
		r = append(r, s[:1]+"."+s[1:])
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 816. Ambiguous Coordinates ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want []string
// 	}{
// 		{
// 			args: args{
// 				s: "(123)",
// 			},
// 			want: []string{
// 				"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)",
// 			},
// 		},
// 		{
// 			args: args{
// 				s: "(0123)",
// 			},
// 			want: []string{
// 				"(0, 1.23)", "(0, 12.3)", "(0, 123)", "(0.1, 2.3)", "(0.1, 23)", "(0.12, 3)",
// 			},
// 		},
// 		{
// 			args: args{
// 				s: "(00011)",
// 			},
// 			want: []string{
// 				"(0, 0.011)", "(0.001, 1)",
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := ambiguousCoordinates(tt.args.s)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
