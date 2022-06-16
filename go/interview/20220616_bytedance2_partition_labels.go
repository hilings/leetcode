package main

import (
	"fmt"
	"sort"
)

func main() {
	// var a int
	// fmt.Scan(&a)

	fmt.Printf("%s", "hello world\n")
	fmt.Printf("Partition Labels, with ByteDance R2 ...\n\n")

	s := "ababcbacadefegdehijhklij"
	res := scan(s)

	fmt.Println(res)

}

func scan(s string) []int {
	res := []int{}

	m := map[rune][]int{}
	for i, c := range s {
		if _, ok := m[c]; !ok {
			m[c] = []int{i, i}
		} else {
			m[c][1] = i
		}
	}

	ranges := [][]int{}
	for _, rng := range m {
		ranges = append(ranges, rng)
	}

	sort.Slice(ranges, func(i, j int) bool {
		return ranges[i][0] < ranges[j][0] || (ranges[i][0] == ranges[j][0] && ranges[i][1] < ranges[j][1])
	})

	left, right := -1, -1
	for _, section := range ranges {
		fmt.Printf("\t%v\n", section)
		if left == -1 {
			left, right = section[0], section[1]
			continue
		}
		if section[1] < right {
			continue
		}
		if section[0] < right && section[1] > right {
			right = section[1]
			continue
		}
		if section[0] > right {
			res = append(res, right-left+1)
			fmt.Printf("\tleft = %d, right = %d\n", left, right)
			fmt.Printf("\t%s\n", s[left:right+1])
			left, right = section[0], section[1]
		}
	}
	if left != -1 {
		res = append(res, right-left+1)
		fmt.Printf("\t%s\n", s[left:right+1])
	}
	return res
}
