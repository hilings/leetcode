package main

func longestPalindrome2(s string) string {
	n := len(s)
	r := ""
	dp := map[int]map[int]bool{}
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if _, ok := dp[i]; !ok {
				dp[i] = map[int]bool{}
			}
			if s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]) {
				dp[i][j] = true
			}
			if dp[i][j] && j+1-i >= len(r) {
				r = s[i : j+1]
			}
		}
	}
	return r
}

func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	start, longest := 0, 0
	for i := 0; i < len(s)-1; i++ {
		p, l := extend(s, i, i) // odd length
		if l > longest {
			start, longest = p, l
		}
		p, l = extend(s, i, i+1) // even length
		if l > longest {
			start, longest = p, l
		}
	}
	return s[start : start+longest]
}

func extend(s string, c1 int, c2 int) (start int, length int) {
	for c1 >= 0 && c2 < len(s) && s[c1] == s[c2] {
		c1--
		c2++
	}
	return c1 + 1, c2 - c1 - 1
}

// func main() {
// 	fmt.Printf("LeetCode 5. Longest Palindromic Substring ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s: "babad",
// 			},
// 			want: "bab",
// 		},
// 		{
// 			args: args{
// 				s: "cbbd",
// 			},
// 			want: "bb",
// 		},
// 		{
// 			args: args{
// 				s: "a",
// 			},
// 			want: "a",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := longestPalindrome(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = longestPalindrome2(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
