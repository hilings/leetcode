package main

import (
	"strings"
)

func minimumLengthEncoding(words []string) int {
	m := map[string]bool{}
	for _, w := range words {
		m[w] = true
	}
	for w := range m {
		for i := 1; i < len(w); i++ {
			delete(m, w[i:])
		}
	}
	r := 0
	for w := range m {
		r += len(w) + 1
	}
	return r
}

func minimumLengthEncoding0(words []string) int {
	bitmap := make([]bool, len(words))
	for i := 0; i < len(words)-1; i++ {
		if bitmap[i] {
			continue
		}
		for j := i + 1; j < len(words); j++ {
			if bitmap[j] {
				continue
			}

			if strings.HasSuffix(words[i], words[j]) {
				bitmap[j] = true
			} else if strings.HasSuffix(words[j], words[i]) {
				bitmap[i] = true
			}
		}
	}

	r := 0
	for i, w := range words {
		if bitmap[i] {
			continue
		}
		r += len(w) + 1
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 820. Short Encoding of Words ...\n\n")

// 	type args struct {
// 		words []string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				words: []string{"time", "me", "bell"},
// 			},
// 			want: 10,
// 		},
// 		{
// 			args: args{
// 				words: []string{"t"},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				words: []string{"abc", "abd"},
// 			},
// 			want: 8,
// 		},
// 		{
// 			args: args{
// 				words: []string{"abc", "bc"},
// 			},
// 			want: 4,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := minimumLengthEncoding(tt.args.words)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}

// 	if strings.HasSuffix("bc", "abc") {
// 		fmt.Println(true)
// 	}
// }
