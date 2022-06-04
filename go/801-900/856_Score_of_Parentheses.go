package main

func scoreOfParentheses2(s string) int {
	r := 0
	layer := 0
	for i, c := range s {
		if c == '(' {
			layer++
		} else {
			layer--
		}
		if c == ')' && s[i-1] == '(' {
			r += 1 << layer
		}
	}
	return r
}

func scoreOfParentheses(s string) int {
	stk := make([]int, 0, len(s))
	for _, c := range s {
		if c == '(' {
			stk = append(stk, -1)
		} else {
			stk = append(stk, -2)
		}

		for len(stk) >= 2 { // process
			n := len(stk)
			if (stk)[n-1] == -2 { // )
				if stk[n-2] == -1 { // ()
					stk = stk[:n-2]
					stk = append(stk, 1)
				} else if stk[n-2] > 0 && stk[n-3] == -1 { // (A)
					score := 2 * stk[n-2]
					stk = stk[:n-3]
					stk = append(stk, score)
				}
			} else if stk[n-1] > 0 { // A
				if stk[n-2] > 0 { // A+B
					A, B := stk[n-2], stk[n-1]
					stk = stk[:n-2]
					stk = append(stk, A+B)
				} else {
					break
				}
			} else { // (
				break
			}
		}
	}
	return stk[0]
}

// func main() {
// 	fmt.Printf("LeetCode 856. Score of Parentheses ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				s: "()",
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				s: "(())",
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				s: "()()",
// 			},
// 			want: 2,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := scoreOfParentheses(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = scoreOfParentheses2(tt.args.s)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
