package main

func findReplaceString(s string, indices []int, sources []string, targets []string) string {
	m := map[int][]string{}
	for k := 0; k < len(indices); k++ {
		m[indices[k]] = []string{
			sources[k], targets[k],
		}
	}

	r := ""
	for i := 0; i < len(s); i++ {
		// fmt.Printf("i = %d\n", i)
		strs, ok := m[i]
		if !ok {
			r += s[i : i+1]
			// fmt.Printf("\tnot match\n")
			continue
		}

		src, tgt := strs[0], strs[1]
		// fmt.Printf("\tindexed, src = %s, tgt = %s\n", src, tgt)
		if i+len(src) > len(s) || s[i:i+len(src)] != src {
			r += s[i : i+1]
			// fmt.Printf("\tnot matched\n")
			continue
		}

		// fmt.Printf("\tswap %s -> %s\n", src, tgt)
		r += tgt
		i = i + len(src) - 1
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 833. Find And Replace in String ...\n\n")

// 	type args struct {
// 		s       string
// 		indices []int
// 		sources []string
// 		targets []string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s:       "abcd",
// 				indices: []int{0, 2},
// 				sources: []string{"a", "cd"},
// 				targets: []string{"eee", "ffff"},
// 			},
// 			want: "eeebffff",
// 		},
// 		{
// 			args: args{
// 				s:       "abcd",
// 				indices: []int{0, 2},
// 				sources: []string{"ab", "ec"},
// 				targets: []string{"eee", "ffff"},
// 			},
// 			want: "eeecd",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := findReplaceString(tt.args.s, tt.args.indices, tt.args.sources, tt.args.targets)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
