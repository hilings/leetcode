package main

func longestMountain2(arr []int) int {
	r := 0
	up, down := 0, 0
	for i := 1; i < len(arr); i++ {
		if (down > 0 && arr[i-1] < arr[i]) || arr[i-1] == arr[i] {
			up, down = 0, 0
		}
		if arr[i-1] < arr[i] {
			up++
		}
		if arr[i-1] > arr[i] {
			down++
		}
		if up > 0 && down > 0 && up+down+1 > r {
			r = up + down + 1
		}
	}
	return r
}

func longestMountain(arr []int) int {
	r := 0
	count := 1
	up := true
	for i := 1; i < len(arr); i++ {
		if up {
			if arr[i] > arr[i-1] {
				count++
			} else if arr[i] < arr[i-1] {
				if count >= 2 {
					up = false
					count++
				} else {
					count = 1
				}
			} else {
				count = 1
			}
			continue
		}

		if arr[i] < arr[i-1] {
			count++
		} else if arr[i] > arr[i-1] {
			if count > r {
				r = count
			}
			count = 2
			up = true
		} else {
			if count > r {
				r = count
			}
			count = 1
			up = true
		}
	}
	if !up && count > r {
		r = count
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 845. Longest Mountain in Array ...\n\n")

// 	type args struct {
// 		arr []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				arr: []int{2, 1, 4, 7, 3, 2, 5},
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				arr: []int{2, 2, 2},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				arr: []int{3, 2},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := longestMountain(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = longestMountain2(tt.args.arr)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
