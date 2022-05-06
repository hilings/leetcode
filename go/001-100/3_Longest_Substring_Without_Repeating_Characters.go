package main

func lengthOfLongestSubstring(s string) int {
	r := 0
	m := make(map[byte]bool)
	for right, left := 0, 0; right < len(s); right++ {
		c := s[right]

		// window right move
		if _, ok := m[c]; !ok {
			m[c] = true
			if len(m) > r {
				r = len(m)
			}
			continue
		}

		// window left move
		for ; left < right && s[left] != c; left++ {
			delete(m, s[left])
		}
		left++
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 3. Longest Substring Without Repeating Characters ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				s: "abcabcbb",
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				s: "bbbbb",
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				s: "pwwkew",
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := lengthOfLongestSubstring(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
