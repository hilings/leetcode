package main

func shortestToChar(s string, c byte) []int {
	n := len(s)
	r := make([]int, n)
	for i := 0; i < n; i++ {
		if s[i] != c {
			continue
		}
		for j := i - 1; j >= 0 && s[j] != c; j-- {
			d := i - j
			if r[j] == 0 || d < r[j] {
				r[j] = d
			}
		}
		for j := i + 1; j < n && s[j] != c; j++ {
			d := j - i
			if r[j] == 0 || d < r[j] {
				r[j] = d
			}
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 821. Shortest Distance to a Character ...\n\n")

// 	type args struct {
// 		s string
// 		c byte
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				s: "loveleetcode",
// 				c: 'e',
// 			},
// 			want: []int{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0},
// 		},
// 		{
// 			args: args{
// 				s: "aaab",
// 				c: 'b',
// 			},
// 			want: []int{3, 2, 1, 0},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := shortestToChar(tt.args.s, tt.args.c)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
