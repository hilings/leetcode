package main

import (
	"fmt"
	"strconv"
)

func evaluate(expression string) int {
	return f(expression, map[string]int{})
}

func f(e string, m map[string]int) (r int) {
	fmt.Printf("\nf    %s    m = %v\n", e, m)

	if e[0] != '(' {
		if i, err := strconv.Atoi(e); err == nil { // integer
			return i
		}
		return m[e] // variable
	}

	v := split(e) // add | mult | let
	switch v[0] {
	case "add":
		return f(v[1], m) + f(v[2], m)
	case "mult":
		return f(v[1], m) * f(v[2], m)
	case "let":
		m2 := map[string]int{}
		for k, v := range m { // scope
			m2[k] = v
		}

		for i := 1; i < len(v)-1; i += 2 {
			m2[v[i]] = f(v[i+1], m2)
			fmt.Printf("%s <- %s    m = %v\n", v[i], v[i+1], m)
		}
		return f(v[len(v)-1], m2)
	}

	return 0
}

func split(e string) []string {
	v := []string{}
	for i := 1; i < len(e)-1; i++ { // expression, ignore () on both end
		if e[i] == '(' { // another expression inside
			count := 0
			for j := i; j <= len(e)-2; j++ {
				if e[j] == '(' {
					count++
					continue
				}
				if e[j] == ')' {
					count--
					if count == 0 {
						v = append(v, e[i:j+1])
						i = j + 1 // space after )
						break
					}
				}
			}
			continue // found )
		}

		// parse integer, variable, protected
		for j := i; j <= len(e)-2; j++ {
			if e[j] == ' ' { // first space
				v = append(v, e[i:j])
				i = j
				break
			}
			if j == len(e)-2 { // last word
				v = append(v, e[i:j+1])
				i = j
				break
			}
		}
	}

	fmt.Printf("split    %s    =>    %s\n", e, printV(v))
	return v
}

func printV(v []string) string {
	s := v[0]
	for i := 1; i < len(v); i++ {
		s += fmt.Sprintf("    %s", v[i])
	}
	return s
}

// func main() {
// 	fmt.Printf("LeetCode 736. Parse Lisp Expression ...\n\n")

// 	es := []string{
// 		// "(let x 2 (mult x (let x 3 y 4 (add x y))))", // 14
// 		// "(let x 3 x 2 x)", // 2
// 		// "(let x 1 y 2 x (add x y) (add x y))", // 5
// 		"(let x 2 (add (let x 3 (let x 4 x)) x))", // 6
// 	}
// 	for _, e := range es {
// 		r := evaluate(e)
// 		fmt.Println(r)
// 	}

// }
