package main

func numMatchingSubseq(s string, words []string) int {
	r := 0
	for _, word := range words {
		if isSubSeq(s, word) {
			r++
		}
	}
	return r
}

func isSubSeq(s string, sub string) bool {
	for i, j := 0, 0; i < len(s); i++ {
		if s[i] != sub[j] {
			continue
		}
		j++ // match
		if j == len(sub) {
			return true
		}
	}
	return false
}

// func main() {
// 	fmt.Printf("LeetCode 792. Number of Matching Subsequences ...\n\n")

// 	type args struct {
// 		s     string
// 		words []string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				s: "abcde",
// 				words: []string{
// 					"a", "bb", "acd", "ace",
// 				},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				s: "dsahjpjauf",
// 				words: []string{
// 					"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax",
// 				},
// 			},
// 			want: 2,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numMatchingSubseq(tt.args.s, tt.args.words)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
