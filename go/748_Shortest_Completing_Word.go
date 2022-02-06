package main

import (
	"strings"
	"unicode"
)

func shortestCompletingWord(licensePlate string, words []string) string {
	m := map[rune]int{}
	for _, c := range strings.ToLower(licensePlate) {
		if unicode.IsLetter(c) {
			m[c]++
		}
	}

	s := ""
	for _, word := range words {
		mm := map[rune]int{} // copy m
		for k, v := range m {
			mm[k] = v
		}

		ok := false
		for _, c := range word {
			mm[c]--
			if mm[c] <= 0 {
				delete(mm, c)
			}
			if len(mm) == 0 {
				ok = true
				break
			}
		}
		if ok && (s == "" || len(word) < len(s)) {
			s = word
		}
	}
	return s
}

// func main() {
// 	fmt.Printf("LeetCode 748. Shortest Completing Word ...\n\n")

// 	type args struct {
// 		licensePlate string
// 		words        []string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				licensePlate: "1s3 PSt",
// 				words: []string{
// 					"step", "steps", "stripe", "stepple",
// 				},
// 			},
// 			want: "steps",
// 		},
// 		{
// 			args: args{
// 				licensePlate: "1s3 456",
// 				words: []string{
// 					"looks", "pest", "stew", "show",
// 				},
// 			},
// 			want: "pest",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := shortestCompletingWord(tt.args.licensePlate, tt.args.words)
// 		fmt.Println(r)
// 	}

// }
