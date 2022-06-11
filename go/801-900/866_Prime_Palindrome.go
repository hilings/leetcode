package main

func primePalindrome(n int) int {
	if n >= 9989900 {
		return 100030001
	}
	for true {
		if isPrime(n) && isPalindrome(n) {
			return n
		}
		n++
	}
	return 0
}

func isPrime(n int) bool {
	if n == 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func isPalindrome(n int) bool {
	n2 := 0
	for k := n; k > 0; k /= 10 {
		n2 = n2*10 + k%10
	}
	return n == n2
}

// func main() {
// 	fmt.Printf("LeetCode 866. Prime Palindrome ...\n\n")

// 	type args struct {
// 		n int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				n: 6,
// 			},
// 			want: 7,
// 		},
// 		{
// 			args: args{
// 				n: 8,
// 			},
// 			want: 11,
// 		},
// 		{
// 			args: args{
// 				n: 13,
// 			},
// 			want: 101,
// 		},
// 		{
// 			args: args{
// 				n: 9989900,
// 			},
// 			want: 100030001,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := primePalindrome(tt.args.n)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
