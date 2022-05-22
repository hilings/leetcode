package main

func pushDominoes(dominoes string) string {
	n := len(dominoes)
	cur := []byte(dominoes)
	for done := false; !done; {
		// fmt.Printf("\tcur = %v\n", string(cur))
		done = true
		next := append([]byte{}, cur...)
		for i := 0; i < n; i++ {
			if next[i] != '.' {
				continue
			}

			left, right := 0, 0 // force from neighbor
			if i-1 >= 0 && cur[i-1] == 'R' {
				left++
			}
			if i+1 < n && cur[i+1] == 'L' {
				right++
			}
			if left == right {
				continue
			}
			if left > right {
				next[i] = 'R'
			} else {
				next[i] = 'L'
			}
			done = false
		}
		cur = next
	}

	return string(cur)
}

// func main() {
// 	fmt.Printf("LeetCode 838. Push Dominoes ...\n\n")

// 	type args struct {
// 		dominoes string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				dominoes: "RR.L",
// 			},
// 			want: "RR.L",
// 		},
// 		{
// 			args: args{
// 				dominoes: ".L.R...LR..L..",
// 			},
// 			want: "LL.RR.LLRRLL..",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := pushDominoes(tt.args.dominoes)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
