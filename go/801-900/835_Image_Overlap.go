package main

func largestOverlap(img1 [][]int, img2 [][]int) int {
	const width = 100 // big enough width for sliding point not to overlap
	n := len(img1)
	l1, l2 := []int{}, []int{}
	for k := 0; k < n*n; k++ {
		i, j := k/n, k%n  // index of point in img
		kk := i*width + j // another kind of encoding of img
		if img1[i][j] == 1 {
			l1 = append(l1, kk)
		}
		if img2[i][j] == 1 {
			l2 = append(l2, kk)
		}
	}

	m := map[int]int{}
	for _, i := range l1 {
		for _, j := range l2 {
			m[i-j]++ // diff i-j means some kind of sliding
		}
	}

	r := 0
	for _, v := range m {
		if v > r {
			r = v
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 835. Image Overlap ...\n\n")

// 	type args struct {
// 		img1 [][]int
// 		img2 [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				img1: [][]int{
// 					{1, 1, 0},
// 					{0, 1, 0},
// 					{0, 1, 0},
// 				},
// 				img2: [][]int{
// 					{0, 0, 0},
// 					{0, 1, 1},
// 					{0, 0, 1},
// 				},
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				img1: [][]int{
// 					{1},
// 				},
// 				img2: [][]int{
// 					{1},
// 				},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				img1: [][]int{
// 					{0},
// 				},
// 				img2: [][]int{
// 					{0},
// 				},
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := largestOverlap(tt.args.img1, tt.args.img2)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
