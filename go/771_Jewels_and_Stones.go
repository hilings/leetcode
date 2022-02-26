package main

func numJewelsInStones(jewels string, stones string) int {
	m := map[rune]bool{}
	for _, c := range jewels {
		m[c] = true
	}
	count := 0
	for _, c := range stones {
		if _, ok := m[c]; ok {
			count++
		}
	}
	return count
}

// func main() {
// 	fmt.Printf("LeetCode 771. Jewels and Stones ...\n\n")

// 	type args struct {
// 		jewels string
// 		stones string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				jewels: "aA",
// 				stones: "aAAbbbb",
// 			},
// 			want: 3,
// 		},
// 		{
// 			args: args{
// 				jewels: "z",
// 				stones: "ZZ",
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numJewelsInStones(tt.args.jewels, tt.args.stones)
// 		fmt.Println(r)
// 	}
// }
