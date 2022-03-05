package main

import (
	"fmt"
	"sort"
)

func missingInteger1(A []int) int {
	m := map[int]bool{}
	for _, a := range A {
		if a > 0 {
			m[a] = true
		}
	}
	for i := 1; i < 100000; i++ {
		if _, ok := m[i]; !ok {
			return i
		}
	}
	return 0
}

func missingInteger2(A []int) int {
	sorted := []int{}

	for _, a := range A {
		if a > 0 {
			sorted = append(sorted, a)
		}
	}

	sort.Ints(sorted)

	x := 1
	for i := 0; i < len(sorted); i++ {
		if x < sorted[i] {
			return x
		}
		x = sorted[i] + 1
	}

	return x
}

func main() {
	fmt.Printf("Codility Missing Integer ...\n\n")

	type args struct {
		A []int
	}
	tests := []struct {
		args args
		want int
	}{
		{
			args: args{
				A: []int{1, 2, 3, 4, 6},
			},
			want: 5,
		},
		{
			args: args{
				A: []int{-1, -3},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		r := missingInteger1(tt.args.A)
		fmt.Println(r)
		r = missingInteger2(tt.args.A)
		fmt.Println(r)
	}
}
