package main

import (
	"fmt"
	"strings"
)

func lengthOfLastWord(s string) int {
	s1 := strings.Trim(s, " ")
	s2 := strings.Split(s1, " ")
	s3 := s2[len(s2)-1]
	return len(s3)
}

func main() {
	fmt.Println("LeetCode 58. Length of Last Word ...")

	s := "Hello World"
	r := lengthOfLastWord(s)
	fmt.Println(r)
}
