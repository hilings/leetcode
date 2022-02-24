package main

import (
	"fmt"
	"sort"
)

func partitionLabels(s string) []int {
	m := map[byte][]int{} // range for each letter, map[letter] -> [left, right]
	for i := 0; i < len(s); i++ {
		if _, ok := m[s[i]]; ok {
			continue
		}
		for j := len(s) - 1; j >= i; j-- {
			if s[j] == s[i] {
				m[s[i]] = []int{i, j}
				break
			}
		}
	}
	// fmt.Println(m)

	parts := [][]int{}
	for _, leftRight := range m {
		parts = union(parts, leftRight)
	}
	sort.Slice(parts, func(i, j int) bool {
		return parts[i][0] < parts[j][0]
	})
	// fmt.Printf("parts = %v\n", parts)

	partSize := []int{}
	for _, leftRight := range parts {
		partSize = append(partSize, leftRight[1]-leftRight[0]+1)
	}
	return partSize
}

func union(parts [][]int, new []int) [][]int {
	newParts := [][]int{}
	for _, part := range parts {
		if new[0] >= part[1] || new[1] <= part[0] { // no intersect
			newParts = append(newParts, part)
			continue
		}

		// merge
		if part[0] < new[0] {
			new[0] = part[0]
		}
		if part[1] > new[1] {
			new[1] = part[1]
		}
	}
	newParts = append(newParts, new)
	return newParts
}

// func main() {
// 	fmt.Printf("LeetCode 763. Partition Labels ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				s: "ababcbacadefegdehijhklij",
// 			},
// 			want: []int{9, 7, 8},
// 		},
// 		{
// 			args: args{
// 				s: "eccbbbbdec",
// 			},
// 			want: []int{10},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := partitionLabels(tt.args.s)
// 		fmt.Println(r)
// 	}
// }
