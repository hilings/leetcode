package main

import "fmt"

// Solution ...
func Solution(A []int) int {
	m := map[int]int{} // count per location
	for _, a := range A {
		m[a]++
	}
	n := len(m)

	visited := map[int]int{}
	r := len(A)
	for left, right := 0, 0; left <= right && right < len(A); right++ {
		visited[A[right]]++
		if len(visited) < n {
			continue
		}
		// reach a potential right border of window
		for visited[A[left]] > 1 {
			visited[A[left]]--
			left++
		}
		w := right - left + 1
		if w < r {
			r = w
		}
		delete(visited, A[left])
		left++
	}

	return r
}

func dfs(A []int, left int, right int, m map[int]int) int {
	fmt.Printf("left = %d, right = %d\n", left, right)
	aLeft, aRight := A[left], A[right]
	if m[aLeft] == 1 && m[aRight] == 1 { // final option
		return right - left + 1
	}
	if m[aLeft] == 1 { // only option on left, try to trim right
		m[aRight]--
		return dfs(A, left, right-1, m)
	}
	if m[aRight] == 1 { // only option on right, try to trim left
		m[aLeft]--
		return dfs(A, left+1, right, m)
	}

	// trim left
	m[aLeft]--
	trimLeft := dfs(A, left+1, right, m)
	m[aLeft]++

	// trim right
	m[aRight]--
	trimRight := dfs(A, left, right-1, m)
	if trimLeft < trimRight {
		return trimLeft
	}
	return trimRight
}

// func main() {
// 	fmt.Printf("Codility Vacation minimal window, with Tesla, R0 ...\n\n")

// 	type args struct {
// 		A []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				A: []int{7, 3, 7, 3, 1, 3, 4, 1}, // 2 ~ 6
// 			},
// 			want: 5,
// 		},
// 		{
// 			args: args{
// 				A: []int{2, 1, 1, 3, 2, 1, 1, 3}, // 2 ~ 4
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				A: []int{7, 5, 2, 7, 2, 7, 4, 7}, // 1 ~ 6
// 			},
// 			want: 6,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := Solution(tt.args.A)
// 		fmt.Println(r)
// 	}
// }
