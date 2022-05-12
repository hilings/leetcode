package main

import "fmt"

func find(n int, digits []int) int {
	fmt.Println(n)
	nums := []int{}
	for ; n > 0; n /= 10 {
		nums = append(nums, n%10)
	}

	m := map[int]bool{}
	for _, d := range digits {
		m[d] = true
	}

	for i := len(nums) - 1; i >= 0; i-- {
		fmt.Printf("\tn = %v, i = %d\n", build(nums), i)
		cur := nums[i]
		flag := false
		for j := cur; j >= 0; j-- {
			if m[j] {
				flag = true
				nums[i] = j
				if j < cur {
					for k := i - 1; k >= 0; k-- {
						nums[k] = 9
					}
				}
				fmt.Printf("\t\tnums[%d] = %d, n = %d\n", i, nums[i], build(nums))
				break
			}
		}
		if !flag {
			if i+1 < len(nums) {
				i++
			}
			nums[i]--
			for j := i - 1; j >= 0; j-- {
				nums[j] = 9
			}
			n = build(nums)
			fmt.Printf("\t\tno fit digit, recursive n = %d\n", n)
			return find(n, digits)
		}
	}

	return build(nums)
}

func build(nums []int) int {
	r := 0
	for i := len(nums) - 1; i >= 0; i-- {
		r = r*10 + nums[i]
	}
	return r
}

// func main() {
// 	fmt.Printf("build biggest number with cap, with ByteDance, R2 ...\n\n")

// 	type args struct {
// 		n      int
// 		digits []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n:      23121,
// 				digits: []int{2, 4, 9},
// 			},
// 			want: 22999,
// 		},
// 		{
// 			args: args{
// 				n:      21121,
// 				digits: []int{2, 4, 9},
// 			},
// 			want: 9999,
// 		},
// 		{
// 			args: args{
// 				n:      21121,
// 				digits: []int{1, 2, 4, 8},
// 			},
// 			want: 21121,
// 		},
// 		{
// 			args: args{
// 				n:      20121,
// 				digits: []int{1, 2, 4, 8},
// 			},
// 			want: 18888,
// 		},
// 		{
// 			args: args{
// 				n:      21121,
// 				digits: []int{2, 4, 8},
// 			},
// 			want: 8888,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := find(tt.args.n, tt.args.digits)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
