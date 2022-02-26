package main

import "fmt"

func maxChunksToSorted(arr []int) int {
	fmt.Println(arr)
	count := 0
	for i, right := 0, 0; i < len(arr); i = right + 1 {
		max := arr[i]
		needScan := true
		right = i // right most index < max
		for needScan {
			needScan = false
			for j := len(arr) - 1; j > i; j-- {
				if arr[j] < max {
					right = j
					fmt.Printf("\tfound smaller arr[%d] = %d\n", j, arr[j])
					break
				}
			}
			for j := right - 1; j > i; j-- {
				if arr[j] > max {
					max = arr[j]
					needScan = true
					fmt.Printf("\tfound bigger arr[%d] = %d\n", j, arr[j])
				}
			}
		}
		count++
		fmt.Printf("partition = %v\n", arr[i:right+1])
	}
	return count
}

// func main() {
// 	fmt.Printf("LeetCode 768. Max Chunks To Make Sorted II ...\n\n")

// 	type args struct {
// 		arr []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{5, 4, 3, 2, 1},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 1, 3, 4, 4},
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				arr: []int{5, 1, 1, 8, 1, 6, 5, 9, 7, 8},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				arr: []int{1, 0, 1, 3, 2},
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maxChunksToSorted(tt.args.arr)
// 		fmt.Println(r)
// 	}
// }
