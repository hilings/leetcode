package main

import (
	"fmt"
)

func uniqueMorseRepresentations(words []string) int {
	dict := []string{
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
		"....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-",
		"..-", "...-", ".--", "-..-", "-.--", "--..",
	}

	m := map[string]int{}
	for _, word := range words {
		s := ""
		for _, c := range word {
			s += dict[c-'a']
		}
		m[s]++
	}

	return len(m)
}

func main() {
	fmt.Printf("LeetCode 804. Unique Morse Code Words ...\n\n")

	type args struct {
		words []string
	}
	tests := []struct {
		args args
		want int
	}{
		{
			args: args{
				words: []string{"gin", "zen", "gig", "msg"},
			},
			want: 2,
		},
		{
			args: args{
				words: []string{"a"},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		r := uniqueMorseRepresentations(tt.args.words)
		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
	}
}
