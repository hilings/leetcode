package main

import "fmt"

func isHappy(n int, visited map[int]bool) bool {
	fmt.Println(n)
	digits := []int{}

	for n > 0 {
		d := n % 10
		digits = append(digits, d)
		n /= 10
	}

	sum := 0
	for _, d := range digits {
		sum += d * d
	}

	if sum == 1 {
		return true
	}

	if _, ok := visited[sum]; ok {
		fmt.Printf("\tlooping %d\n", sum)
		return false
	}

	visited[sum] = true

	return isHappy(sum, visited)
}

// func main() {
// 	// var a int
// 	// fmt.Scan(&a)
// 	fmt.Printf("%s", "hello world")

// 	visited := map[int]bool{}

// 	n := 19
// 	result := isHappy(n, visited)
// 	fmt.Println(result)

// 	n = 1234567895
// 	result = isHappy(n, visited)
// 	fmt.Println(result)

// 	n = 1234567896
// 	result = isHappy(n, visited)
// 	fmt.Println(result)

// }
