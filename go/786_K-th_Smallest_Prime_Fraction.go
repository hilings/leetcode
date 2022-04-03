package main

import (
	"sort"
)

func kthSmallestPrimeFraction(arr []int, k int) []int {
	type Fraction struct {
		Keys     []int
		Fraction float64
	}

	l := []Fraction{}
	for i := 0; i < len(arr)-1; i++ {
		for j := i + 1; j < len(arr); j++ {
			f := Fraction{
				Keys:     []int{arr[i], arr[j]},
				Fraction: float64(arr[i]) / float64(arr[j]),
			}
			l = append(l, f)
		}
	}
	sort.Slice(l, func(i, j int) bool {
		return l[i].Fraction < l[j].Fraction
	})
	// fmt.Println(l)

	return l[k-1].Keys
}

// func main() {
// 	fmt.Printf("LeetCode 786. K-th Smallest Prime Fraction ...\n\n")

// 	type args struct {
// 		arr []int
// 		k   int
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{1, 2, 3, 5},
// 				k:   3,
// 			},
// 			want: []int{2, 5},
// 		},
// 		{
// 			args: args{
// 				arr: []int{1, 7},
// 				k:   1,
// 			},
// 			want: []int{1, 7},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := kthSmallestPrimeFraction(tt.args.arr, tt.args.k)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
