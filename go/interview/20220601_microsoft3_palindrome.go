package main

func longestPalindrome(s string) string {
	n := len(s)
	r := ""
	dp := map[int]map[int]bool{}
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if _, ok := dp[i]; !ok {
				dp[i] = map[int]bool{}
			}
			if s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]) {
				dp[i][j] = true
			}
			if dp[i][j] && j+1-i > len(r) {
				r = s[i : j+1]
			}
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("interview, Microsoft R3, longest palindrome substring...\n\n")

// 	s := "babadd"
// 	r := longestPalindrome(s)
// 	fmt.Println(r)
// }
