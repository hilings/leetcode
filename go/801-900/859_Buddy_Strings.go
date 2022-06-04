package main

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}

	letters := []byte{}      // diff letters
	mCount := map[byte]int{} // count per letter
	dup := false             // whether s contains duplicate letter
	for i := 0; i < len(s); i++ {
		if s[i] == goal[i] {
			mCount[s[i]]++
			if mCount[s[i]] > 1 {
				dup = true
			}
		} else {
			letters = append(letters, s[i], goal[i])
		}
	}

	switch {
	case len(letters) > 4, len(letters) == 2:
		return false
	case len(letters) == 4:
		return letters[0] == letters[3] && letters[1] == letters[2]
	case len(letters) == 0:
		return dup
	}
	return false
}

// func main() {
// 	fmt.Printf("LeetCode 859. Buddy Strings ...\n\n")

// 	type args struct {
// 		s    string
// 		goal string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				s:    "ab",
// 				goal: "ba",
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				s:    "ab",
// 				goal: "ab",
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				s:    "aa",
// 				goal: "aa",
// 			},
// 			want: true,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := buddyStrings(tt.args.s, tt.args.goal)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
