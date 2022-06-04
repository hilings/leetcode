package main

func lemonadeChange(bills []int) bool {
	c5, c10, c20 := 0, 0, 0
	for _, b := range bills {
		switch b {
		case 5:
			c5++
		case 10:
			if c5 == 0 {
				return false
			}
			c5, c10 = c5-1, c10+1
		case 20:
			if c10 >= 1 && c5 >= 1 {
				c5, c10, c20 = c5-1, c10-1, c20+1
			} else if c5 >= 3 {
				c5, c20 = c5-3, c20+1
			} else {
				return false
			}
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 860. Lemonade Change ...\n\n")

// 	type args struct {
// 		bills []int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				bills: []int{5, 5, 5, 10, 20},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				bills: []int{5, 5, 10, 10, 20},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := lemonadeChange(tt.args.bills)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
