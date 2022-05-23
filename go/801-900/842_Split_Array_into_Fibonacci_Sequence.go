package main

import (
	"math"
	"strconv"
)

func splitIntoFibonacci(num string) []int {
	n := len(num)
	for i := 1; i <= n-2 && i <= 10; i++ { // start of second number
		f1 := num[0:i]
		a1, _ := strconv.Atoi(f1)
		if a1 > math.MaxInt32 {
			break
		}
		for j := i + 1; j <= n-1 && j-i <= 10; j++ { // start of third number
			f2 := num[i:j]
			a2, _ := strconv.Atoi(f2)
			if a2 > math.MaxInt32 {
				break
			}
			if r, ok := buildFib(a1, a2, num); ok {
				// fmt.Println(r)
				return r
			}
		}
	}
	return []int{}
}

func buildFib(a1, a2 int, num string) ([]int, bool) {
	// fmt.Printf("\t%d %d\n", a1, a2)
	r := []int{a1, a2}
	s := strconv.Itoa(a1) + strconv.Itoa(a2)
	for len(s) < len(num) {
		a1, a2 = a2, a1+a2
		if a2 > math.MaxInt32 {
			break
		}
		s += strconv.Itoa(a2)
		r = append(r, a2)
	}
	// fmt.Printf("\ts = %s, r = %v\n", s, r)
	if s == num {
		return r, true
	}
	return []int{}, false
}

// func main() {
// 	fmt.Printf("LeetCode 842. Split Array into Fibonacci Sequence ...\n\n")

// 	type args struct {
// 		num string
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				num: "1101111",
// 			},
// 			want: []int{11, 0, 11, 11},
// 		},
// 		{
// 			args: args{
// 				num: "112358130",
// 			},
// 			want: []int{},
// 		},
// 		{
// 			args: args{
// 				num: "0123",
// 			},
// 			want: []int{},
// 		},
// 		{
// 			args: args{
// 				num: "539834657215398346785398346991079669377161950407626991734534318677529701785098211336528511",
// 			},
// 			want: []int{},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := splitIntoFibonacci(tt.args.num)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
