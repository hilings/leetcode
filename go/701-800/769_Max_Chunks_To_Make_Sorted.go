package main

import "fmt"

func maxChunksToSorted(arr []int) int {
	fmt.Println(arr)
	count := 0
	for i, max := 0, 0; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
		}
		if max == i {
			count++
		}
	}

	return count
}

// func main() {
// 	fmt.Printf("LeetCode 769. Max Chunks To Make Sorted ...\n\n")

// 	type args struct {
// 		arr []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{0, 2, 1, 4, 3, 5, 7, 6},
// 			},
// 			want: 5,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maxChunksToSorted(tt.args.arr)
// 		fmt.Println(r)
// 	}
// }
