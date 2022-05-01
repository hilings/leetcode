package main

func expressiveWords(s string, words []string) int {
	r := 0
	for _, word := range words {
		// fmt.Println(word)
		if isStretchy(s, word) {
			r++
		}
	}
	return r
}

func isStretchy(s string, w string) bool {
	for i1, i2 := 0, 0; i1 < len(s) || i2 < len(w); {
		if i1 == len(s) || i2 == len(w) {
			return false
		}
		if s[i1] != w[i2] {
			// fmt.Printf("\tdoes not match: %c %c\n", s[i1], w[i2])
			return false
		}
		n1, n2 := 1, 1
		for j := i1 + 1; j < len(s) && s[j] == s[i1]; j++ {
			n1++
		}
		for j := i2 + 1; j < len(w) && w[j] == w[i2]; j++ {
			n2++
		}

		// fmt.Printf("\t%c%d\t%c%d\n", s[i1], n1, w[i2], n2)
		if n1 < n2 || (n1 > n2 && n1 < 3) {
			// fmt.Printf("\tnot stretchy!\n")
			return false
		}
		i1 += n1
		i2 += n2
	}
	// fmt.Printf("\tstretchy!\n")
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 809. Expressive Words ...\n\n")

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
// 				s: "heeellooo",
// 				words: []string{
// 					"hello", "hi", "helo",
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				s: "zzzzzyyyyy",
// 				words: []string{
// 					"zzyy", "zy", "zyy",
// 				},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				s: "abcd",
// 				words: []string{
// 					"abc",
// 				},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				s: "aaa",
// 				words: []string{
// 					"aaaa",
// 				},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := expressiveWords(tt.args.s, tt.args.words)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
