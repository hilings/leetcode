package main

import (
	"sort"
)

func intersectionSizeTwo(intervals [][]int) int {
	// sort by interval upper bound ascendingly
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][1] == intervals[j][1] {
			return intervals[i][0] < intervals[j][0]
		}
		return intervals[i][1] < intervals[j][1]
	})
	// fmt.Println(intervals)

	count := 2
	last, penultimate := intervals[0][1], intervals[0][1]-1

	// greedily pick the largest integer in an interval
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] <= penultimate { // have 2 in common
			continue
		}
		if intervals[i][0] <= last { // have 1 in common,
			count++
			if intervals[i][1] != last { // pick the largest integer
				penultimate = last
				last = intervals[i][1]
			} else { // maintain the largest 2 integers so far
				penultimate = last - 1
			}
		} else { // no intersection
			count += 2
			last, penultimate = intervals[i][1], intervals[i][1]-1
		}
	}

	return count
}

// func main() {
// 	fmt.Printf("LeetCode 757. Set Intersection Size At Least Two ...\n\n")

// 	type args struct {
// 		intervals [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				intervals: [][]int{
// 					{3, 5},
// 					{2, 5},
// 					{1, 3},
// 					{1, 4},
// 				},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				intervals: [][]int{
// 					{1, 2},
// 					{2, 3},
// 					{2, 4},
// 					{4, 5},
// 				},
// 			},
// 			want: 5,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := intersectionSizeTwo(tt.args.intervals)
// 		fmt.Println(r)
// 	}
// }
