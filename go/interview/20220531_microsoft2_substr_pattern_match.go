package main

import "unicode"

/*
s1 []string{
	"a1",
	"a2",
	"a33",
	"a4",
	"a55",
	...
}

s2 []string{
	"b11",
	"b2",
	"b33",
	"b4",
	"b55",
	...
}

s3 []string{
	"c11",
	"c22",
	"c3",
	"c4",
	"c55",
	...
}

s = "c55 a4 b33 c22 a33 b11"

check if input match the pattern the substrings in s mapped in s1 ~ sn array

*/

func check(ss [][]string, sample string, input string) bool {
	m := map[byte]map[string]int{}
	for i := 0; i < len(ss); i++ {
		list := ss[i]
		first := list[0][0]         // first char
		m[first] = map[string]int{} //

		for j := 0; j < len(list); j++ {
			m[first][list[j]] = j
		}
	}

	sampleResult := []int{}

	for i := 0; i < len(sample); i++ {
		first := sample[i] //

		l := 1
		for j := i + 1; j < len(sample) && unicode.IsDigit(rune(sample[j])); j++ {
			l++
		}

		word := sample[i : i+l] // c55

		index := m[first][word]

		sampleResult = append(sampleResult, int(first), index)
	}

	// do same thing for input
	inputResult := []int{}

	for i := 0; i < len(sampleResult); i++ {
		if inputResult[i] != sampleResult[i] {
			return false
		}
	}

	return true
}

// func main() {
// 	fmt.Printf("LeetCode XXX. ABCDEFG ...\n\n")

// 	type args struct {
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := tt.args
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
