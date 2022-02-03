package main

func monotoneIncreasingDigits(n int) int {
	// split integer into digit slice
	v := []int{}
	for k := n; k > 0; k /= 10 {
		v = append([]int{k % 10}, v...)
	}

	// check increasing
	k, i := 0, 1
	for i = 1; i < len(v); i++ {
		if v[i-1] < v[i] {
			k = i // rightmost index greater than left digit
		} else if v[i-1] > v[i] {
			break
		}
	}
	if i < len(v) { // need adjustment
		v[k]--
		for i := k + 1; i < len(v); i++ {
			v[i] = 9
		}
	}

	// build integer
	r := 0
	for _, d := range v {
		r = 10*r + d
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 738. Monotone Increasing Digits ...\n\n")

// 	ns := []int{
// 		10,     //9
// 		1234,   //1234
// 		332,    //299
// 		123321, //122999
// 	}
// 	for _, n := range ns {
// 		r := monotoneIncreasingDigits(n)
// 		fmt.Printf("%d\n\n", r)
// 	}

// }
