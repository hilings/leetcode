package main

func numFriendRequests(ages []int) int {
	m := map[int]int{}
	for _, a := range ages {
		m[a]++
	}

	r := 0
	for x, cx := range m {
		for y, cy := range m {
			if isValid(x, y) {
				if x == y {
					r += cx * (cx - 1)
				} else {
					r += cx * cy
				}
			}
		}
	}
	return r
}

func isValid(x, y int) bool {
	if float64(y) <= 0.5*float64(x)+7 || y > x || (y > 100 && x < 100) {
		return false
	}
	return true
}

func numFriendRequests0(ages []int) int {
	r := 0
	for i, x := range ages {
		for j, y := range ages {
			if i == j {
				continue
			}
			if float64(y) <= float64(x)*0.5+7 {
				continue
			}
			if y > x {
				continue
			}
			if y > 100 && x < 100 {
				continue
			}
			r++
		}
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 825. Friends Of Appropriate Ages ...\n\n")

// 	type args struct {
// 		ages []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				ages: []int{16, 16},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				ages: []int{16, 17, 18},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				ages: []int{20, 30, 100, 110, 120},
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numFriendRequests0(tt.args.ages)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = numFriendRequests(tt.args.ages)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
