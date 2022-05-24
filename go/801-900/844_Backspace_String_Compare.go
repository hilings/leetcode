package main

func backspaceCompare2(s string, t string) bool {
	for i, j := len(s)-1, len(t)-1; i >= 0 || j >= 0; {
		back := 0
		for ; i >= 0 && (back > 0 || s[i] == '#'); i-- {
			if s[i] == '#' {
				back++
			} else {
				back--
			}
		}

		back = 0
		for ; j >= 0 && (back > 0 || t[j] == '#'); j-- {
			if t[j] == '#' {
				back++
			} else {
				back--
			}
		}

		if i < 0 && j < 0 {
			return true
		}

		if i < 0 || j < 0 || s[i] != t[j] {
			return false
		}
		i--
		j--
	}
	return true
}

func backspaceCompare(s string, t string) bool {
	return f844(s) == f844(t)
}

func f844(s string) string {
	r := ""
	for i := 0; i < len(s); i++ {
		if s[i] != '#' {
			r += string(s[i])
		} else if len(r) > 0 {
			r = r[:len(r)-1]
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 844. Backspace String Compare ...\n\n")

// 	type args struct {
// 		s string
// 		t string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				s: "ab#c",
// 				t: "ad#c",
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				s: "ab##",
// 				t: "c#d#",
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				s: "a#c",
// 				t: "b",
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				s: "xywrrmp",
// 				t: "xywrrm#p",
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := backspaceCompare(tt.args.s, tt.args.t)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = backspaceCompare2(tt.args.s, tt.args.t)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
