package main

import (
	"unicode"
)

func letterCasePermutation(s string) []string {
	q := []string{""}
	for _, c := range s {
		lSuffix := []string{}
		if unicode.IsDigit(c) {
			lSuffix = []string{string(c)}
		} else {
			lSuffix = []string{string(unicode.ToUpper(c)), string(unicode.ToLower(c))}
		}

		qNext := []string{}
		for _, prefix := range q {
			for _, suffix := range lSuffix {
				qNext = append(qNext, prefix+suffix)
			}
		}
		q = qNext
	}
	return q
}

func letterCasePermutation2(s string) []string {
	r := []string{}
	f784(s, &r, []string{""}, 0)
	return r
}

func f784(s string, r *[]string, q []string, i int) {
	if i == len(s) {
		*r = append(*r, q...)
		return
	}

	c := rune(s[i])
	lSuffix := []string{}
	if unicode.IsDigit(c) {
		lSuffix = []string{string(c)}
	} else {
		lSuffix = []string{string(unicode.ToUpper(c)), string(unicode.ToLower(c))}
	}
	todo := []string{}
	for _, prefix := range q {
		for _, suffix := range lSuffix {
			todo = append(todo, prefix+suffix)
		}
	}
	f784(s, r, todo, i+1)
}

// func main() {
// 	fmt.Printf("LeetCode 784. Letter Case Permutation ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want []string
// 	}{
// 		{
// 			args: args{
// 				s: "a1b2",
// 			},
// 			want: []string{
// 				"a1b2",
// 				"a1B2",
// 				"A1b2",
// 				"A1B2",
// 			},
// 		},
// 		{
// 			args: args{
// 				s: "3z4",
// 			},
// 			want: []string{
// 				"3z4",
// 				"3Z4",
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := letterCasePermutation(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = letterCasePermutation2(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
