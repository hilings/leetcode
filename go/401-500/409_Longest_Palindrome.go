package main

func longestPalindrome(s string) int {
	m := map[rune]int{} // count per char
	for _, c := range s {
		m[c]++
	}

	r := 0
	single := 0 // any char with odd count
	for _, count := range m {
		r += count / 2 * 2
		if count%2 == 1 {
			single = 1
		}
	}
	return r + single
}

// func main() {
// 	fmt.Printf("LeetCode 409. Longest Palindrome ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				s: "abccccdd",
// 			},
// 			want: 7,
// 		},
// 		{
// 			args: args{
// 				s: "a",
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				s: "bb",
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				s: "ccc",
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := longestPalindrome(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
