package main

func shiftingLetters(s string, shifts []int) string {
	for i := len(shifts) - 2; i >= 0; i-- {
		shifts[i] = (shifts[i] + shifts[i+1]) % 26
	}
	bytes := make([]byte, 0, len(s))
	for i, c := range s {
		bytes = append(bytes, byte(int('a')+(int(c-'a')+shifts[i])%26))
	}
	return string(bytes)
}

// func main() {
// 	fmt.Printf("LeetCode 848. Shifting Letters ...\n\n")

// 	type args struct {
// 		s      string
// 		shifts []int
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s:      "abc",
// 				shifts: []int{3, 5, 9},
// 			},
// 			want: "rpl",
// 		},
// 		{
// 			args: args{
// 				s:      "aaa",
// 				shifts: []int{1, 2, 3},
// 			},
// 			want: "gfd",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := shiftingLetters(tt.args.s, tt.args.shifts)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
