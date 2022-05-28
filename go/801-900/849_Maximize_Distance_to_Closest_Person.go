package main

func maxDistToClosest(seats []int) int {
	r := 0
	for i := 0; i < len(seats); i++ {
		if seats[i] == 1 {
			continue
		}
		count := 0
		for ; i < len(seats) && seats[i] == 0; i++ {
			count++
		}

		if i-count > 0 && i < len(seats) { // if not empty seat in the end
			count = (count + 1) / 2
		}
		if count > r {
			r = count
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 849. Maximize Distance to Closest Person ...\n\n")

// 	type args struct {
// 		seats []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				seats: []int{1, 0, 0, 0, 1, 0, 1},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				seats: []int{1, 0, 0, 0},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				seats: []int{0, 0, 1, 0},
// 			},
// 			want: 2,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maxDistToClosest(tt.args.seats)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
