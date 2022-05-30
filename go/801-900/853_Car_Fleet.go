package main

import (
	"sort"
)

func carFleet(target int, position []int, speed []int) int {
	n := len(position)
	data := [][]int{} // data[i] = [position, speed]
	for i := 0; i < n; i++ {
		data = append(data, []int{position[i], speed[i]})
	}
	sort.Slice(data, func(i, j int) bool {
		return data[i][0] > data[j][0]
	})

	r := 0
	time := 0.0
	for i := 0; i < n; i++ {
		if float64(data[i][0])+float64(data[i][1])*time >= float64(target) {
			continue
		}
		r++
		time = float64(target-data[i][0]) / float64(data[i][1])
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 853. Car Fleet ...\n\n")

// 	type args struct {
// 		target   int
// 		position []int
// 		speed    []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				target:   12,
// 				position: []int{10, 8, 0, 5, 3},
// 				speed:    []int{2, 4, 1, 1, 3},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				target:   10,
// 				position: []int{3},
// 				speed:    []int{3},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				target:   100,
// 				position: []int{0, 2, 4},
// 				speed:    []int{4, 2, 1},
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := carFleet(tt.args.target, tt.args.position, tt.args.speed)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
