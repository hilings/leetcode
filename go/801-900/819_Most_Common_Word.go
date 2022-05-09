package main

import (
	"strings"
	"unicode"
)

func mostCommonWord(paragraph string, banned []string) string {
	mBanned := map[string]bool{}
	for _, w := range banned {
		mBanned[w] = true
	}

	paragraph = strings.ToLower(paragraph)
	words := []string{}
	for i, j := 0, 0; i < len(paragraph); i++ {
		if !unicode.IsLetter(rune(paragraph[i])) {
			continue
		}
		for j = i + 1; j < len(paragraph) && unicode.IsLetter(rune(paragraph[j])); j++ {

		}
		words = append(words, paragraph[i:j])
		i = j
	}

	m := map[string]int{}
	r := ""
	for _, word := range words {
		m[word]++
		if m[word] > m[r] && !mBanned[word] {
			r = word
		}
	}
	// fmt.Println(m)

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 819. Most Common Word ...\n\n")

// 	type args struct {
// 		paragraph string
// 		banned    []string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				paragraph: "Bob hit a ball, the hit BALL flew far after it was hit.",
// 				banned:    []string{"hit"},
// 			},
// 			want: "ball",
// 		},
// 		{
// 			args: args{
// 				paragraph: "a, a, a, a, b,b,b,c, c",
// 				banned:    []string{"a"},
// 			},
// 			want: "b",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := mostCommonWord(tt.args.paragraph, tt.args.banned)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
