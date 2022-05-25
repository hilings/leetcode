package main

import (
	"sort"
)

func isNStraightHand(hand []int, groupSize int) bool {
	set := []int{}
	mCount := map[int]int{}
	for _, a := range hand {
		if _, ok := mCount[a]; ok {
			mCount[a]++
		} else {
			mCount[a] = 1
			set = append(set, a)
		}
	}
	sort.Ints(set)
	// fmt.Println(set)
	// fmt.Println(mCount)
	for i, a := range set {
		// fmt.Printf("\ti = %d, a = %d, m = %v\n", i, a, mCount)
		if mCount[a] == 0 {
			continue
		} else if mCount[a] < 0 || i+groupSize > len(set) {
			return false
		}
		c := mCount[a]
		for k := a; k < a+groupSize; k++ {
			if _, ok := mCount[k]; !ok {
				return false
			}
			mCount[k] -= c
		}
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 846. Hand of Straights ...\n\n")

// 	type args struct {
// 		hand      []int
// 		groupSize int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				hand:      []int{1, 2, 3, 6, 2, 3, 4, 7, 8},
// 				groupSize: 3,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				hand:      []int{1, 2, 3, 4, 5},
// 				groupSize: 4,
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				hand:      []int{6, 8, 10},
// 				groupSize: 3,
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := isNStraightHand(tt.args.hand, tt.args.groupSize)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
