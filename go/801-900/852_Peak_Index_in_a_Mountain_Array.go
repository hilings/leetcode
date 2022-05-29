package main

func peakIndexInMountainArray2(arr []int) int {
	left, right := 0, len(arr)-1
	for left < right {
		mid := (left + right) / 2
		if arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] {
			return mid
		}
		if arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1] {
			left = mid + 1
		} else {
			right = mid
		}

	}
	return left
}

func peakIndexInMountainArray(arr []int) int {
	for i := 1; i < len(arr)-1; i++ {
		if arr[i] > arr[i+1] {
			return i
		}
	}
	return 0
}

// func main() {
// 	fmt.Printf("LeetCode 852. Peak Index in a Mountain Array ...\n\n")

// 	type args struct {
// 		arr []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{0, 1, 0},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				arr: []int{0, 2, 1, 0},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				arr: []int{0, 10, 5, 2},
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := peakIndexInMountainArray(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = peakIndexInMountainArray2(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
