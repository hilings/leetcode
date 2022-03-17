package main

import (
	"sort"
	"strings"
)

func solution(file []string) []string {
	files := [][]string{}
	for _, row := range file {
		cols := strings.Split(row, " ")
		files = append(files, cols)
	}

	sort.Slice(files, func(i, j int) bool {
		return files[i][0] < files[j][0] || (files[i][0] == files[j][0] && files[i][1] > files[j][1])
	})

	r := []string{}
	for _, rows := range files {
		row := strings.Join(rows, " ")
		r = append(r, row)
	}

	return r
}

// func main() {
// 	fmt.Printf("sort file, with Didi, R1 ...\n\n")

// 	file := []string{
// 		"songj123 100",
// 		"sj 23",
// 		"sj 445",
// 		"ritu 56",
// 	}
// 	r := solution(file)
// 	for _, row := range r {
// 		fmt.Println(row)
// 	}
// }
