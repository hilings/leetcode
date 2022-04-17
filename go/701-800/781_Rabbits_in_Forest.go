package main

import "fmt"

func numRabbits(answers []int) int {
	mC := map[int]int{} // count of rabbits that answer a number
	for _, a := range answers {
		mC[a]++
	}

	count := 0
	for k, v := range mC {
		fmt.Printf("%d = %d\n", k, v)
		if k+1 >= v {
			count += k + 1
		} else {
			count += v / (k + 1) * (k + 1)
			if v%(k+1) > 0 {
				count += k + 1
			}
		}
	}
	return count
}

// func main() {
// 	fmt.Printf("LeetCode 781. Rabbits in Forest ...\n\n")

// 	type args struct {
// 		answers []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				answers: []int{1, 1, 2},
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				answers: []int{3, 3, 3, 3, 3, 4},
// 			},
// 			want: 13,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numRabbits(tt.args.answers)
// 		fmt.Printf("got = %v, expect = %v\n", r, tt.want)
// 	}
// }
