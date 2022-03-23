package main

func longestSubstrWODup(s string) int {
	set := map[byte]bool{}
	r := 0

	for i, j := 0, 0; i <= j && j < len(s); j++ {
		// window move right til dup
		if _, ok := set[s[j]]; !ok {
			set[s[j]] = true
			continue
		}

		// update max
		l := len(set)
		// fmt.Printf("[%d, %d] = %s\n", i, j, s[i:j])
		if l > r {
			r = l
		}

		// window move left
		for ; i <= j; i++ {
			if s[i] != s[j] {
				delete(set, s[i])
			} else {
				i++
				break
			}
		}
	}

	l := len(set)
	if l > r {
		r = l
	}

	return r
}

// func main() {
// 	fmt.Printf("Longest substring without duplicate, with ByteDance, R1 ...\n\n")

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
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				s: "abaa",
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				s: "bbbbb",
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := longestSubstrWODup(tt.args.s)
// 		fmt.Println(r)
// 	}
// }
