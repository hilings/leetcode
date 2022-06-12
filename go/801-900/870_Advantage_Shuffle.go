package main

import (
	"fmt"
	"sort"
)

func advantageCount2(nums1 []int, nums2 []int) []int {
	nums2p := [][2]int{}
	for i, a := range nums2 {
		nums2p = append(nums2p, [2]int{i, a}) // keep nums2 original index
	}

	sort.Ints(nums1)
	sort.Slice(nums2p, func(i, j int) bool {
		return nums2p[i][1] < nums2p[j][1]
	})

	r := make([]int, len(nums1))
	left, right := 0, len(nums1)-1
	for i := len(nums2p) - 1; i >= 0; i-- { // scan nums2 from bigger to smaller
		if nums1[right] > nums2p[i][1] { // take from bigger side of nums1
			r[nums2p[i][0]] = nums1[right]
			right--
		} else { // take a smallest from nums1
			r[nums2p[i][0]] = nums1[left]
			left++
		}
	}
	return r
}

func advantageCount(nums1 []int, nums2 []int) []int {
	nums2Map := [][]int{}
	for i := 0; i < len(nums2); i++ {
		nums2Map = append(nums2Map, []int{nums2[i], i})
	}

	sort.Ints(nums1)
	sort.Ints(nums2)
	sort.Slice(nums2Map, func(i, j int) bool {
		return nums2Map[i][0] < nums2Map[j][0]
	})

	r := []int{}
	dp870(nums1, 0, nums2, 0, &r, []int{}, []int{})
	fmt.Println(r)

	rMap := [][]int{}
	for i := 0; i < len(r); i++ {
		rMap = append(rMap, []int{r[i], nums2Map[i][1]})
	}
	sort.Slice(rMap, func(i, j int) bool {
		return rMap[i][1] < rMap[j][1]
	})
	fmt.Println(rMap)

	r = []int{}
	for i := 0; i < len(nums1); i++ {
		r = append(r, rMap[i][0])
	}
	return r
}

func dp870(nums1 []int, i1 int, nums2 []int, i2 int, max *[]int, sofar []int, skipped []int) {
	fmt.Printf("nums1 = %v, i1 = %d, nums2 = %v, i2 = %d, sofar = %v, skipped = %v\n", nums1, i1, nums2, i2, sofar, skipped)
	if i1 == len(nums1) || i2 == len(nums2) {
		if len(sofar) >= len(*max) {
			*max = append(sofar, skipped...)
		}
		return
	}

	if nums1[i1] > nums2[i2] {
		r1 := append([]int{}, sofar...)
		r1 = append(r1, nums1[i1])
		dp870(nums1, i1+1, nums2, i2+1, max, r1, skipped)
		return
	}

	skipped2 := append([]int{}, skipped...)
	skipped2 = append(skipped2, nums1[i1])
	dp870(nums1, i1+1, nums2, i2, max, sofar, skipped2)   // move forward in nums1
	dp870(nums1, i1+1, nums2, i2+1, max, sofar, skipped2) // skip one in nums2
}

// func main() {
// 	fmt.Printf("LeetCode 870. Advantage Shuffle ...\n\n")

// 	type args struct {
// 		nums1 []int
// 		nums2 []int
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				nums1: []int{2, 7, 11, 15},
// 				nums2: []int{1, 10, 4, 11},
// 			},
// 			want: []int{2, 11, 7, 15},
// 		},
// 		{
// 			args: args{
// 				nums1: []int{12, 24, 8, 32},
// 				nums2: []int{13, 25, 32, 11},
// 			},
// 			want: []int{24, 32, 8, 12},
// 		},
// 		{
// 			args: args{
// 				nums1: []int{0},
// 				nums2: []int{0},
// 			},
// 			want: []int{0},
// 		},
// 		{
// 			args: args{
// 				nums1: []int{28, 47, 45, 8, 2, 10, 25, 35, 43, 37, 33, 30, 33, 20, 33, 42, 43, 36, 34, 3, 16, 23, 15, 10, 19, 42, 13, 47, 0, 21, 36, 38, 0, 5, 3, 28, 4, 20, 14, 5, 19, 22, 29, 17, 3, 16, 35, 0, 26, 0},
// 				nums2: []int{44, 10, 27, 4, 27, 40, 46, 40, 45, 0, 41, 2, 44, 50, 36, 30, 37, 4, 44, 4, 12, 13, 35, 20, 19, 25, 38, 42, 43, 14, 2, 4, 5, 38, 4, 38, 0, 35, 12, 32, 38, 33, 3, 1, 19, 46, 23, 13, 24, 41},
// 			},
// 			want: []int{0},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := advantageCount2(tt.args.nums1, tt.args.nums2)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
